#include "methods.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    Pixel **cores;
    FILE *arquivo;
    int i, j, raio, lados;
    char linha[20];
    char comando[20];
    char nome_final[20];
    int x1, y1, x2, y2;

    // Alocando dinamicamente as dimensões da imagem
    char *m = alocar_din(5);
    char *n = alocar_din(5);

    // Abertura do arquivo de especificação
    arquivo = fopen("especificacao-presentation.txt", "r");

    //Alocando dinamicamente os representantes r, g e b 
    char *r = alocar_din(3);
    char *g = alocar_din(3);
    char *b = alocar_din(3);

    while(strcmp(comando, "save") != 0){
        fscanf(arquivo, "%s", comando);

        if(strcmp(comando, "image") == 0){
            fscanf(arquivo,"%s %s\n", m, n);
            // Aloca pixels dinamicamente
            cores = alocar_pixels(linha, m, n);          
        }
        if(strcmp(comando, "clear") == 0){
            fscanf(arquivo, "%s %s %s\n", r, g, b);
            limparImagem(cores, comando, m, n, r, g, b);
        }
        if(strcmp(comando, "save") == 0){
            fscanf(arquivo, "%s\n", nome_final);
            criarArquivo3(cores, nome_final, m, n);
        }
        
        if(strcmp(comando, "color") == 0){
            fscanf(arquivo, "%s %s %s\n", r, g, b);
            pintarImagem(cores, m, n, r, g, b);
            pintarBorda(cores, m, n);
        }
        
        if(strcmp(comando, "line") == 0){
            fscanf(arquivo, "%d %d %d %d\n", &x1, &y1, &x2, &y2);
            desenharLinhaPoligono(cores, x1, y1, x2, y2);
        }
        
        if(strcmp(comando, "circle") == 0){
            fscanf(arquivo, "%d %d %d\n", &x1, &y1, &raio);
            desenharCirculo(cores, x1, y1, raio);
        }
        
        if(strcmp(comando, "polygon") == 0){
            fscanf(arquivo, "%d", &lados);
            desenharPoligono2(arquivo, cores, lados, x1, y1);
        }

        if(strcmp(comando, "fill") == 0){
            fscanf(arquivo, "%d %d", &x1, &y1);
            fill(cores, x1, y1);
        }
    }
    fclose(arquivo);

    return 0;
}