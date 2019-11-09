#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include <string.h>

#include <graphics.h>

char* alocar_din(int tamanho){
    char *ponteiro;
    ponteiro = (char*)malloc(tamanho*sizeof(char));

    return ponteiro;
}

void criarArquivo(char* m, char* n){
    FILE *imagem = fopen("teste2.ppm", "w");
    fprintf(imagem, "P3\n");
    fprintf(imagem, "%s %s\n", m, n);
    fprintf(imagem, "255\n");
    fclose(imagem);
}

void limparImagem(Pixel **cores, int m, int n, char* r, char* g, char* b){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cores[i][j].r = atoi(r);
            cores[i][j].g = atoi(g);
            cores[i][j].b = atoi(b);
        }
    }
    FILE *imagem = fopen("teste2.ppm", "a");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            fprintf(imagem, "%u ", cores[i][j].r);
            fprintf(imagem, "%u ", cores[i][j].g);
            fprintf(imagem, "%u \n", cores[i][j].b);
        }
    }
    fclose(imagem);
}

void renomearImagem(char* nome_novo){
    FILE *imagem = fopen("teste2.ppm", "a");
    rename("teste2.ppm", nome_novo);
    fclose(imagem);
}

void desenharLinha(int x0, int y0, int x1, int y1){
    int dx, dy, p, x, y;

    Polygon poligono;

    dx = x1 - x0;
    dy = y1 - y0;

    x = x0;
    y = y0;

    p = 2*dy-dx;

    while(x < x1){
        if(p>=0){
            
        }
    }
}

// void alocarImagem(FILE *arquivo, Pixel **img, int m, int n){
//     int i, j;
//     img = (Pixel**)calloc(m, sizeof(Pixel*));

//     if(img == NULL){
//         printf("Erro ao alocar!");
//     }

//     for(i = 0; i < m; i++){
//         img[i] = (Pixel*)calloc(n, sizeof(Pixel));

//         if(img[i] == NULL){
//             printf("Erro ao alocar!");
//         }
//     }

//     fprintf(arquivo, "P3\n");
//     fprintf(arquivo, "%u %u \n", m, n);
//     fprintf(arquivo, "255 \n");

//     for(i = 0; i < m; i++){
//         for(j = 0; j < n; j++){
//             img[i][j].r = 0;
//             img[i][j].g = 255;
//             img[i][j].b = 0;
//         }
//     }

//     for(i = 0; i < m; i++){
//         for(j = 0; j < n; j++){
//             fprintf(arquivo, "%u %u %u \n", img[i][j].r, img[i][j].g, img[i][j].b);
//         }
//     } 
// }

// void lerArquivo(FILE *arquivo, Pixel **img, int m, int n){
//     int i, j;
//     arquivo = fopen("imagem.ppm", "r");

//     if (arquivo == NULL){
//         printf("Erro na leitura do arquivo!");
//     }
//     else{
//         for(i = 0; i < m; i++){
//             for(j = 0; j < n; j++){
//                 printf("%u %u %u \n", img[i][j].r,img[i][j].g, img[i][j].b);
//             }
//         }
//     }
// }