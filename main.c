#include "methods.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    Pixel **cores;
    FILE *arquivo;
    int i, j;
    char linha[20];

    // Alocando dinamicamente as dimensões da imagem
    char *m = alocar_din(5);
    char *n = alocar_din(5);

    // Abertura do arquivo de especificação
    arquivo = fopen("especificacao-presentation.txt", "r");

    //Alocando dinamicamente os representantes r, g e b 
    char *r = alocar_din(3);
    char *g = alocar_din(3);
    char *b = alocar_din(3);

    // Pega cada linha até o fim do arquvio de especificação
    while(fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Verifica de na linha especificada contém o comando especificado
        if(strstr(linha, "image")){
            // Aloca pixels dinamicamente
            cores = alocar_pixels(linha, m, n);
        }
        if(strstr(linha, "clear")){
            // Se a linha conter o comando clear, limpa a imagem com as cores especificadas
            limparImagem(cores, linha, m, n, r, g, b);
        }
        if(strstr(linha, "line")){
            desenharLinha(cores, linha, m, n);
        }
        if(strstr(linha, "save")){
            // Se a linha conter o comando save, salva o arquivo com o nome especificado
            criarArquivo2(linha, cores, m, n);
        }
        if(strstr(linha, "color")){
            pintarImagem(cores, linha, m, n, r, g, b);
        }
        if(strstr(linha, "circle")){
            desenharCirculo(cores, linha);
        }
        if(strstr(linha, "polygon")){
            desenharPoligono(cores, linha);
        }
    }
    // Fecha arquivo de especificação
    fclose(arquivo);

    return 0;
}