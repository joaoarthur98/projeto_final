#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include <string.h>

char* alocar_din(int tamanho){
    char *ponteiro;
    ponteiro = (char*)malloc(tamanho*sizeof(char));

    return ponteiro;
}

void criarArquivo(char linha[], char *m, char *n){
    char comando[10];
    // Lê a linha no padrão especificado no parâmetro do meio
    sscanf(linha, "%s %s %s", comando, m, n);
    // Abre a imagem baseado no que foi lido na linha
    FILE *imagem = fopen("teste.ppm", "w");
    // Preenche as primeiras linhas da imagem
    fprintf(imagem, "P3\n");
    fprintf(imagem, "%s %s\n", m, n);
    fprintf(imagem, "255\n");
    // Fecha a imagem
    fclose(imagem);
}

void limparImagem(Pixel **cores, char linha[], char* m, char* n, char* r, char* g, char* b){
    // Transforma o tamanho das dimensões em inteiro
    int m1 = atoi(m);
    int n1 = atoi(n);
    int i, j;
    char comando[10];
    // Lê a linha no padrão especificado no parâmetro do meio
    sscanf(linha, "%s %s %s %s", comando, r, g, b);
    
    // Percorre cores, preenchendo cada pixel com as cores especificadas pela linha lida
    for(i = 0; i < m1; i++){
        for(j = 0; j < n1; j++){
            cores[i][j].r = atoi(r);
            cores[i][j].g = atoi(g);
            cores[i][j].b = atoi(b);
        }
    }
}

void renomearImagem(char linha[]){
    char comando[10];
    char nome_novo[20];
    // Lê a linha no padrão especificado no parâmetro do meio
    sscanf(linha, "%s %s", comando, nome_novo);
    // Abre a imagem
    FILE *imagem = fopen("teste.ppm", "a");
    // Renomeia a imagem
    rename("teste.ppm", nome_novo);
    // Fecha a imagem
    fclose(imagem);
}

void desenharLinha(Pixel **cores, char linha[], char* m, char* n){
    char comando[10];
    char x1[5];
    char x2[5];
    char y1[5];
    char y2[5];
    int i, j;

    sscanf(linha, "%s %s %s %s %s", comando, x1, y1, x2, y2);

    int x1_int = atoi(x1);
    int x2_int = atoi(x2);
    int y1_int = atoi(y1);
    int y2_int = atoi(y2);

    int x = x1_int;
    int y = y1_int;

    // Inclinação
    int dx = abs(x2_int-x1_int);
    int dy = abs(y2_int-y1_int);

    int decisao = (2*dy-dx);
    int incI = 2*dy;
    int incS = 2*(dy-dx);

    cores[y][x].r = 0;
    cores[y][x].g = 0;
    cores[y][x].b = 0;

    while(x != x2_int){
        if(decisao >= 0){
            decisao = decisao+2*dy-2*dx;
            //x++;
            //y++;
        }
        else{
            decisao = decisao + 2*dy;
            //y++;
        }
        x++;
    cores[y][x].r = 0;
    cores[y][x].g = 0;
    cores[y][x].b = 0;
    }
}


// Função para alocar dinamicamente cores
Pixel** alocar_pixels(char linha[], char* m, char* n){
    char comando[10];
    sscanf(linha, "%s %s %s", comando, m, n);
    int m1 = atoi(m);
    int n1 = atoi(n);
    int i;
    Pixel **cores = (Pixel**)malloc(m1 * sizeof(Pixel*));

    for(i = 0; i < m1; i++){
        cores[i] = (Pixel*)malloc(n1 * sizeof(Pixel));
    }
    return cores;
}

void pintarImagem(Pixel** cores, char linha[], char* m, char* n, char* r, char* g, char* b){
     int m1 = atoi(m);
    int n1 = atoi(n);
    int i, j;
    char comando[10];
    // Lê a linha no padrão especificado no parâmetro do meio
    sscanf(linha, "%s %s %s %s", comando, r, g, b);
    
    // Percorre cores, preenchendo cada pixel com as cores especificadas pela linha lida
    for(i = 0; i < m1; i++){
        for(j = 0; j < n1; j++){
            cores[i][j].r = atoi(r);
            cores[i][j].g = atoi(g);
            cores[i][j].b = atoi(b);
        }
    }
    // Abre a imagem baseado no que foi lido na linha
    //FILE *imagem = fopen("teste.ppm", "a+");

    // // Preenche a imagem com os valores de cores em todos os seus pixels
    // for(i = 0; i < m1; i++){
    //     for(j = 0; j < n1; j++){
    //         fprintf(imagem, "%u ", cores[i][j].r);
    //         fprintf(imagem, "%u ", cores[i][j].g);
    //         fprintf(imagem, "%u \n", cores[i][j].b);
    //     }
    // }
    // // Fecha a imagem
    // fclose(imagem);
}

void criarArquivo2(char linha[], Pixel** cores, char* m, char* n){
    char comando[10];
    char nome[20];
    int i, j;
    int m1 = atoi(m);
    int n1 = atoi(n);

    sscanf(linha, "%s %s", comando, nome);

    FILE *imagem = fopen(nome, "w");

    fprintf(imagem, "P3\n");
    fprintf(imagem, "%s %s\n", m, n);
    fprintf(imagem, "255\n");

    for(i = 0; i < m1; i++){
        for(j = 0; j < n1; j++){
            fprintf(imagem, "%u ", cores[i][j].r);
            fprintf(imagem, "%u ", cores[i][j].g);
            fprintf(imagem, "%u \n", cores[i][j].b); 
        }
    }
}