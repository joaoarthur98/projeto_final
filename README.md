# projeto_final
Projeto final da disciplina de Introdução às Técnicas de Programação

# Dupla: 
    - João Arthur Oliveira Barbosa 
    - Rickson Andrade de Lima

# O que foi feito:

    O projeto final da disciplina de Introdução às Técnicas de Programação tinha como objetivo 
    um programa que pudesse manipular um arquivo ppm, podendo realizar desenhos e pinturas.

    Inicialmente, foi feito um protótipo totalmente estático, onde assumíamos o que o arquivo de especificação continha, linha por linha. Este protótipo foi apresentado ao professor no dia 06/11. Até então, o programa continha a criação do arquivo com a função "image", que recebia as dimensões do arquivo. Continha também a função "clear", que tinha o trabalho de limpar a imagem com a cor especificada pelo arquivo. A função "color", que pintava a imagem com a função especificada e com o comando line, o programa só desenhava uma linha e esta, só poderia ser horizontal.

    Quem fez o que nesta etapa do projeto: 

    João Arthur: 
        - Criação do arquivo main, divisão dos métodos no arquivo methods.c e methods.h;
        - Criação do arquivo Makefile para compilação do programa;
        - Criação da função de escrita no arquivo abarcando a primitiva "image" e "clear";

    Rickson Andrade: 
        - Criação da função de pintura através da primitiva "color";
        - Criação de função de desenho de linhas através da primitiva "line". Sem o uso do algoritmo de Bresenham.

    Recomendações do professor: Dinamizar código e correr com as funções restantes.

    Após isso, foi reformulado a forma como líamos as primitivas, com o uso do sscanf, assim. Lendo em cada método a sua linha e seus parâmetros.
    A partir deste ponto, a função line agora faria uso do algoritmo de Bresenham. 

    Nesta função de desenho de linhas, recebemos por parâmetro o Pixel cores, e dois pontos: (x1,y1) e (x2, y2).

    Após isso, são criadas duas variáveis, dx e dy. Estas variáveis são responsáveis pelo cálculo de inclinação no eixo x e y. Cálculo esse feito pelo valor absoluto de x2-x1 e y2-y1.

    Além disso, são criadas as variáveis sx e sy. A variável sx verifica se x1 é menor que x2, se sim, recebe 1. Do contrário, -1. Isto será útil porque temos que lidar com pontos onde o x1 é menor que o x2 e o contrário também. Caso seja menor, o x será incrementado na pintura até chegar ao x2. O mesmo ocorre com o y.

    