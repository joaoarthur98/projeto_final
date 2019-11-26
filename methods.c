#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#include <string.h>
#include <math.h>

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
    //char comando[10];
    // Lê a linha no padrão especificado no parâmetro do meio
    //sscanf(linha, "%s %s %s %s", comando, r, g, b);
    
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

    int dx = abs(x2_int-x1_int), sx = x1_int<x2_int ? 1 : -1;
    
    int dy = abs(y2_int-y1_int), sy = y1_int<y2_int ? 1 : -1; 

    int err = (dx>dy ? dx : -dy)/2, e2;

    while(x != x2_int && y != y2_int){
        //printf("P[%d][%d]\n", x, y);
        //printf("%d\n", y);

        if (x == x2_int && y == y2_int){
            break;
        }
        e2 = err;
        if (e2 >-dx) { 
            err -= dy; x += sx;
        }
        if (e2 < dy) { 
            err += dx; y += sy;
        }

    cores[x][y].r = 0;
    cores[x][y].g = 0;
    cores[x][y].b = 0;
    }
}
void desenharCirculo(Pixel **cores, int x1, int y1, int raio){
    // char comando[10];
    // char raio[5];
    // char xc[5];
    // char yc[5];
    int x;

    // sscanf(linha, "%s %s %s %s", comando, xc, yc, raio);
    
    // int x1 = atoi(xc);
    // int y1 = atoi(yc);
    // int raio_int = atoi(raio);
    
    

    for(x=0; x<(raio*sin(45*M_PI/180)); x++){
        float yFloat = sqrt(raio*raio-x*x);

        float yBaixo = yFloat +0.5;
        float yCima = -yFloat +0.5;
        float xDireita = x;
        float xEsquerda = -x;

        pintarPixel(cores, yBaixo+x1, xEsquerda+y1);
        pintarPixel(cores, xDireita+x1, yCima+y1);
        pintarPixel(cores, xEsquerda+x1, yCima+y1);
        pintarPixel(cores, yCima+x1, xEsquerda+y1);
        pintarPixel(cores, yCima+x1, xDireita+y1);
        pintarPixel(cores, xEsquerda+x1, yBaixo+y1);
        pintarPixel(cores, xDireita+x1, yBaixo+y1);
        pintarPixel(cores, yBaixo+x1, xDireita+y1);

    }
}

void pintarPixel(Pixel **cores, int i, int j){
    cores[i][j].r = 0;
    cores[i][j].g = 0;
    cores[i][j].b = 0;

    // FILE *imagem = fopen("xablau", "w");
    
}

// Função para alocar dinamicamente cores
Pixel** alocar_pixels(char linha[], char* m, char* n){
    //char comando[10];
    //sscanf(linha, "%s %s %s", comando, m, n);
    int m1 = atoi(m);
    int n1 = atoi(n);
    int i;
    Pixel **cores = (Pixel**)malloc(m1 * sizeof(Pixel*));

    for(i = 0; i < m1; i++){
        cores[i] = (Pixel*)malloc(n1 * sizeof(Pixel));
    }
    return cores;
}

void pintarImagem(Pixel** cores, char* m, char* n, char* r, char* g, char* b){
    int m1 = atoi(m);
    int n1 = atoi(n);
    int i, j;
    //char comando[10];
    // Lê a linha no padrão especificado no parâmetro do meio
    //sscanf(linha, "%s %s %s %s", comando, r, g, b);
    
    // Percorre cores, preenchendo cada pixel com as cores especificadas pela linha lida
    for(i = 0; i < m1; i++){
        for(j = 0; j < n1; j++){
            cores[i][j].r = atoi(r);
            cores[i][j].g = atoi(g);
            cores[i][j].b = atoi(b);
        }
    }
}

void criarArquivo2(char linha[], Pixel** cores, char* m, char* n){
    char comando[10];
    char nome[20];
    int x,y;
    int m1 = atoi(m);
    int n1 = atoi(n);

    sscanf(linha, "%s %s", comando, nome);

    FILE *imagem = fopen(nome, "w");

    fprintf(imagem, "P3\n");
    fprintf(imagem, "%s %s\n", m, n);
    fprintf(imagem, "255\n");

    for(y = 0; y < n1; y++){
        for(x = 0; x < m1; x++){
            fprintf(imagem, "%u ", cores[x][y].r);
            fprintf(imagem, "%u ", cores[x][y].g);
            fprintf(imagem, "%u \n", cores[x][y].b); 
        }
    }
    fclose(imagem);
}

void desenharPoligono(FILE *arquivo, Pixel **cores, char linha[]){
    char comando[10];
    char lados[5];
    int lados_int;

    sscanf(linha, "%s %s", comando, lados);
    printf("%s\n", comando);
    printf("%s\n", lados);

    if((lados_int = atoi(lados)) == 3){
        printf("%s\n", comando);
        printf("%s\n", lados);
        //desenharTriangulo(cores, linha);
    }
}

void desenharLinhaPoligono(Pixel **cores, int x1, int y1, int x2, int y2){
    int x = x1;
    int y = y1;

    int dx = abs(x2-x1), sx = x1<x2 ? 1 : -1;
    
    int dy = abs(y2-y1), sy = y1<y2 ? 1 : -1; 

    int err = (dx>dy ? dx : -dy)/2, e2;

    while(x != x2 && y != y2){
        //printf("P[%d][%d]\n", x, y);
        //printf("%d\n", y);

        if (x == x2 && y == y2){
            break;
        }
        e2 = err;
        if (e2 >-dx) { 
            err -= dy; x += sx;
        }
        if (e2 < dy) { 
            err += dx; y += sy;
        }

    cores[x][y].r = 0;
    cores[x][y].g = 0;
    cores[x][y].b = 0;
    }
}

void criarArquivo3(Pixel **cores, char nomeFinal[], char *m, char *n){
    int x,y;
    int m1 = atoi(m);
    int n1 = atoi(n);

    //sscanf(linha, "%s %s", comando, nome);

    FILE *imagem = fopen(nomeFinal, "w");

    fprintf(imagem, "P3\n");
    fprintf(imagem, "%s %s\n", m, n);
    fprintf(imagem, "255\n");

    for(y = 0; y < n1; y++){
        for(x = 0; x < m1; x++){
            fprintf(imagem, "%u ", cores[x][y].r);
            fprintf(imagem, "%u ", cores[x][y].g);
            fprintf(imagem, "%u \n", cores[x][y].b); 
        }
    }
    fclose(imagem);
}

void desenharPoligono2(FILE *arquivo, Pixel **cores, int lados, int x1, int y1){
    int pontosEmX[lados];
    int pontosEmY[lados];
    int i;

    for(i = 0; i < lados; i++){
        fscanf(arquivo, "%d %d", &x1, &y1);
        pontosEmX[i] = x1;
        pontosEmY[i] = y1;

        int pontoAnteriorX;
        int pontoAnteriorY;
        int pontoAtualX;
        int pontoAtualY;

                
        if(i == 0){
            pontoAnteriorX = pontosEmX[i];
            pontoAnteriorY = pontosEmY[i];
        }
        // Tamanho de vetores maior que 0?
        if ( i > 0){
            // Se sim, desenha uma linha entre pontos atuais e anteriores
                    
            pontoAtualX = pontosEmX[i];
            pontoAtualY = pontosEmY[i];
            // printf("Anterior: X -> %d | Y -> %d\n", pontoAnteriorX, pontoAnteriorY);
            // printf("Atual: X -> %d | Y -> %d\n", pontoAtualX, pontoAtualY);

            desenharLinhaPoligono(cores, pontoAnteriorX, pontoAnteriorY, pontoAtualX, pontoAtualY);

            pontoAnteriorX = pontosEmX[i];
            pontoAnteriorY = pontosEmY[i];
            //desenharLinhaPoligono(cores, pontosEmX[i-1], pontosEmY[i-1], pontosEmX[i], pontosEmY[i]);
        }
        if(i == lados-1){
            pontoAnteriorX = pontosEmX[i];
            pontoAnteriorY = pontosEmY[i];

            pontoAtualX = pontosEmX[0];
            pontoAtualY = pontosEmY[0];

            desenharLinhaPoligono(cores, pontoAnteriorX, pontoAnteriorY, pontoAtualX, pontoAtualY);
        }
    }
}