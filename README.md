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

Desenhar círculo:

    Para a criação do círculo foi desenvolvida uma função chamada “desenharCirculo”, que recebe a matriz cores, a posição do ponto central e o raio. Através de um cálculo matemático o círculo é dividido em oito partes que, em cada repetição do laço, os pixels são preenchidos com a cor preta com o uso da função “pintarPixel” que tem como parâmetros a posição do pixel que será preenchido.
    
Função fill:
    
    A função “fill” tem o objetivo de pintar todos os pixels, entretanto, não pode sobrepor linhas, pintar dentro de círculos/polígonos ou ultrapassar o limite da imagem. A função tem como parâmetros apenas a matriz cores e a posição do ponto de partida. A partir desse ponto será iniciada a mudança de cor de cada pixel.
    Dividimos o algoritmo em 4 partes. As partes são bastante semelhantes, mas cada uma irá pintar um quadrante diferente. É formada por duas estruturas de repetição while, que tem como condição “Enquanto o pixel não dor preto”, pois os pixels que formam as linhas, polígonos e círculos são pretos. 
    No primeiro quadrante, o primeiro laço controla o “x” e o laço interno (segundo laço) controla a posição do “y”. Em cada x, o y é subtraído um até que seja encontrado um pixel preto, assim, toda coluna será pintada e, logo após, o x é somado um para ir à coluna da direita.
    No segundo quadrante, em cada x, o y é subtraído um até que seja encontrado um pixel preto, assim, toda coluna será pintada e, logo após, o x é subtraído um para ir à coluna da esquerda.
    No terceiro quadrante, em cada x, o y é somado um até que seja encontrado um pixel preto, assim, toda coluna será pintada e, logo após, o x é subtraído um para ir à coluna da esquerda.
    No quarto quadrante, em cada x, o y é somado um até que seja encontrado um pixel preto, assim, toda coluna será pintada e, logo após, o x é somado um para ir à coluna da esquerda.    

# O que não foi feito:

    Decorrente da falta de compreensão de alguns requisitos do projeto, a função “color” não foi desenvolvida e usada corretamente. Pois, o objetivo dela é definir a cor que será predominante nos próximos comandos. No entanto, estávamos usando para definir a cor que será aplicada no backgound.
    Além disso, por pintar cada coluna de forma estática, ao localizar um pixel da cor preta para a repetição. Desta forma, não é possível localizar e pintar os pixels que estão no outro lado, caso exista.
    
# Como compilar o projeto:
    
    No projeto foi acrescentada a biblioteca math, string, stdlib, stdio. Porém, para compilar é necessário apenas o comando make e o ./main e, para apagar o arquivo anterio e refazer, usa-se o make clean. Para que isso seja possível foi necessário o uso do arquivo makefile. 
    
    
    

    

    
