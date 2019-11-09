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
void criarArquivo(char* m, char* n);
void limparImagem(Pixel **cores, int m, int n, char* r, char* g, char* b);
void renomearImagem(char* nome_novo);
// void alocarImagem(FILE *arquivo, Pixel **img, int m, int n);
// void lerArquivo(FILE *arquivo, Pixel **img,  int m, int n);

#endif