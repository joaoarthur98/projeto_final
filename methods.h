#ifndef METHODS_H
#define METHODS_H
#include <stdio.h>

typedef struct { 
    unsigned char r,g,b;
} Pixel;

typedef struct {
    int x0, y0, x1, y1;
} Polygon;

void lerComandos(FILE *arquivo);
char* alocar_din(int tamanho);
void criarArquivo(char linha[], char *m, char *n);
void limparImagem(Pixel **cores, char linha[], char* m, char* n, char* r, char* g, char* b);
void renomearImagem(char linha[]);
Pixel** alocar_pixels(char linha[], char* m, char* n);
void desenharLinha(Pixel **cores, char linha[], char* m, char* n);
void pintarImagem(Pixel** cores, char linha[], char* m, char* n, char* r, char* g, char* b);
void criarArquivo2(char linha[], Pixel** cores, char* m, char* n);
// void alocarImagem(FILE *arquivo, Pixel **img, int m, int n);
// void lerArquivo(FILE *arquivo, Pixel **img,  int m, int n);

#endif