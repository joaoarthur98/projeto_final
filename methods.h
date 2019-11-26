#ifndef METHODS_H
#define METHODS_H
#include <stdio.h>

typedef struct { 
    unsigned char r,g,b;
} Pixel;


char* alocar_din(int tamanho);
void limparImagem(Pixel **cores, char linha[], char* m, char* n, char* r, char* g, char* b);
Pixel** alocar_pixels(char linha[], char* m, char* n);
void pintarImagem(Pixel** cores, char* m, char* n, char* r, char* g, char* b);
void pintarPixel(Pixel **cores, int i, int j);
void desenharCirculo(Pixel **cores,  int x1, int y1, int raio);
void desenharLinhaPoligono(Pixel **cores, int x1, int y1, int x2, int y2);
void criarArquivo3(Pixel **cores, char nomeFinal[], char *m, char *n);
void desenharPoligono2(FILE *arquivo, Pixel **cores, int lados, int x1, int y1);
void fill( Pixel **cores, int xc, int yc);
void pintarAmarelo(Pixel **cores, int i, int j);
void pintarVermelho(Pixel **cores, int i, int j);
void pintarVerde(Pixel **cores, int i, int j);
void pintarBranco(Pixel **cores, int i, int j);
void pintarBorda(Pixel **cores, char* m, char* n);


#endif