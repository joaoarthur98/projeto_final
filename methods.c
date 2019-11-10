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
    // Abre a imagem baseado no que foi lido na linha
    FILE *imagem = fopen("teste.ppm", "a");

    // Preenche a imagem com os valores de cores em todos os seus pixels
    for(i = 0; i < m1; i++){
        for(j = 0; j < n1; j++){
            fprintf(imagem, "%u ", cores[i][j].r);
            fprintf(imagem, "%u ", cores[i][j].g);
            fprintf(imagem, "%u \n", cores[i][j].b);
        }
    }
    // Fecha a imagem
    fclose(imagem);
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
// Função para alocar dinamicamente cores
Pixel** alocar_pixels(char* m, char* n){
    int m1 = atoi(m);
    int n1 = atoi(n);
    int i;
    Pixel **cores = (Pixel**)malloc(m1 * sizeof(Pixel*));

    for(i = 0; i < m1; i++){
        cores[i] = (Pixel*)malloc(n1 * sizeof(Pixel));
    }
    return cores;
}