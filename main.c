#include "methods.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE *arquivo;
    Pixel **cores;
    int i, j;
    char comando[20];
    char novo_arquivo[20];

    arquivo = fopen("especificacao-presentation.txt", "r");

    //Alocando dinamicamente as dimensões da imagem
    char *m = alocar_din(5);
    char *n = alocar_din(5);

    //Alocando dinamicamente os representantes r, g e b 
    char *r = alocar_din(3);
    char *g = alocar_din(3);
    char *b = alocar_din(3);
    
    // Lendo a primeira linha
    fscanf(arquivo, "%s %s %s\n", comando, m, n);
    criarArquivo(m, n);
    
    int m2 = atoi(m);                                   // Transformado char em int
    int n2 = atoi(n);                                   // Transformando char em int

    cores = (Pixel**)malloc(m2*sizeof(Pixel*));         // Alocação dinâmica de Pixel

    for(i = 0; i < m2; i++){
        cores[i] = (Pixel*)malloc(n2*sizeof(Pixel));
    }

    //Lendo a segunda linha
    fscanf(arquivo, "%s %s %s %s\n", comando, r, g, b);
    limparImagem(cores, m2, n2, r, g, b);
    
    //Lendo a terceira linha
    fscanf(arquivo, "%s %s\n", comando, novo_arquivo);
    renomearImagem(novo_arquivo);
    
    return 0;
}