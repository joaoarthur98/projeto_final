# projeto_final
Projeto final da disciplina de Introdução às Técnicas de Programação

# Dupla: 
    - João Arthur Oliveira Barbosa 
    - Rickson Andrade de Lima

# O que foi feito:

    O projeto final da disciplina de Introdução às Técnicas de Programação tinha como objetivo 
    um programa que pudesse manipular um arquivo ppm, podendo realizar desenhos e pinturas.

    O projeto final contém um arquivo "main.c", responsável por abrir o arquivo de especificação e fazer a sua leitura. Na leitura, fazemos uso da biblioteca "methods.c", contendo todos os métodos do projeto e a struct Pixel, responsável pelos pixels de cores da nossa imagem.
    Todos os métodos da biblioteca "methods.c" estão anotados no header "methods.h".

    Explicando um pouco todo o processo de desenvolvimento do projeto, inicialmente foi feito um protótipo totalmente estático, onde assumíamos o que o arquivo de especificação continha, linha por linha. Este protótipo foi apresentado ao professor no dia 06/11. Até então, o programa continha a criação do arquivo com a função "image", que recebia as dimensões do arquivo. Continha também a função "clear", que tinha o trabalho de limpar a imagem com a cor especificada pelo arquivo. A função "color", que pintava a imagem com a função especificada e com o comando line, o programa só desenhava uma linha e esta, só poderia ser horizontal.

    Nosso projeto baseia-se na nossa Struct Pixel, que tem atributos unsigned char r, g, b, para que suas cores possam ser preenchidas e postas no arquivo ppm.

    Após isso, foi reformulado a forma como líamos as primitivas, com o uso do sscanf, assim. Lendo em cada método a sua linha e seus parâmetros.
    A partir deste ponto, a função line agora faria uso do algoritmo de Bresenham.

    No entanto, quando tivemos contato com o algoritmo de desenho de polígonos, seria necessário uma função que recebesse dinamicamente os parâmetros da linha de poligonos, já que essa figura possui n lados. 
    Foi então que passamos a usar a função fscanf, e usando um while para pegar 2 parametros por vez, no caso, os pontos x e y, até que a quantidade de lados acabasse. Então, mudamos logo para todas as primitivas, para que o projeto ficasse "homogêneo". Além disso, passamos a usar o strcmp, para comparar as primitivas com o que continha no arquivo de especificação. 

Desenho de Linhas: 
    
    Recebemos por parâmetro o Pixel cores, e dois pontos: (x1,y1) e (x2, y2).

    Após isso, são criadas duas variáveis, dx e dy. Estas variáveis são responsáveis pelo cálculo de inclinação no eixo x e y. Cálculo esse feito pelo valor absoluto de x2-x1 e y2-y1.

    Além disso, são criadas as variáveis sx e sy. A variável sx verifica se x1 é menor que x2, se sim, recebe 1. Do contrário, -1. Isto será útil porque temos que lidar com pontos onde o x1 é menor que o x2 e o contrário também. Caso seja menor, o x será incrementado na pintura até chegar ao x2. O mesmo ocorre com o y.

    Depois desse passo, temos um laço que vai cuidar da incrementação e decrementação dessas variáveis,
    para que os pixels sejam pintados de forma correta ao que foi proposto no arquivo de especificação

Desenhar círculo:

    Para a criação do círculo foi desenvolvida uma função chamada “desenharCirculo”, que recebe a matriz cores, a posição do ponto central e o raio. Através de um cálculo matemático o círculo é dividido em oito partes que, em cada repetição do laço, os pixels são preenchidos com a cor preta com o uso da função “pintarPixel” que tem como parâmetros a posição do pixel que será preenchido.

Desenhar poligonos: 

    São criados dois vetores com o tamanho da quantidade de lados do poligono.
    A partir desse ponto, é criado um laço de zero até a quantidade de lados.
    No primeiro ponto do laço, as variaveis PontoAnteriorX e PontoAnteriorY recebem o primeiro ponto (x,y) do arquivo de especificação.
    No segundo ponto, as variáveis PontoAtualX e PontoAtualY recebem o segundo ponto (x,y) do arquivo.
    Com os dois pontos em mãos, usamos a função de desenhar linha, passando como parâmetro PontoAnterior e PontoAtual. Após isso, PontoAnterior recebe pontoAtual, e assim por diante.
    No último ponto, pontoAnterior recebe o último ponto (x,y) e pontoAtual receberá o primeiro ponto (x,y), a fim de que o polígono possa se fechar.

Função fill:
    
    A função “fill” tem o objetivo de pintar todos os pixels, entretanto, não pode sobrepor linhas, pintar dentro de círculos/polígonos ou ultrapassar o limite da imagem. A função tem como parâmetros apenas a matriz cores e a posição do ponto de partida. A partir desse ponto será iniciada a mudança de cor de cada pixel.
    Dividimos o algoritmo em 4 partes. As partes são bastante semelhantes, mas cada uma irá pintar um quadrante diferente. É formada por duas estruturas de repetição while, que tem como condição “Enquanto o pixel não dor preto”, pois os pixels que formam as linhas, polígonos e círculos são pretos. 
    No primeiro quadrante, o primeiro laço controla o “x” e o laço interno (segundo laço) controla a posição do “y”. Em cada x, o y é subtraído um até que seja encontrado um pixel preto, assim, toda coluna será pintada e, logo após, o x é somado um para ir à coluna da direita.
    No segundo quadrante, em cada x, o y é subtraído um até que seja encontrado um pixel preto, assim, toda coluna será pintada e, logo após, o x é subtraído um para ir à coluna da esquerda.
    No terceiro quadrante, em cada x, o y é somado um até que seja encontrado um pixel preto, assim, toda coluna será pintada e, logo após, o x é subtraído um para ir à coluna da esquerda.
    No quarto quadrante, em cada x, o y é somado um até que seja encontrado um pixel preto, assim, toda coluna será pintada e, logo após, o x é somado um para ir à coluna da esquerda.

# Quem fez o que no projeto: 

    João Arthur: 
        - Criação do arquivo main, divisão dos métodos no arquivo methods.c e methods.h;
        - Criação do arquivo Makefile para compilação do programa;
        - Criação da função de escrita no arquivo abarcando a primitiva "image" e "clear";
        - Implementação de nova função "line" baseada no algoritmo de Bresenham;
        - Implementação da função "polygon" baseada no fluxograma apresentado pelo professor nas instruções do projeto.

    Rickson Andrade: 
        - Criação da função de pintura através da primitiva "color";
        - Criação de função de desenho de linhas através da primitiva "line". Sem o uso do algoritmo de Bresenham.
        - Implementação da função "circle";
        - Implementação da função "fill".    

# O que não foi feito:

    Decorrente da falta de compreensão de alguns requisitos do projeto, a função “color” não foi desenvolvida e usada corretamente. Pois, o objetivo dela é definir a cor que será predominante nos próximos comandos. No entanto, estávamos usando para definir a cor que será aplicada no backgound.
    Além disso, por pintar cada coluna de forma estática, ao localizar um pixel da cor preta para a repetição. Desta forma, não é possível localizar e pintar os pixels que estão no outro lado, caso exista.
    
    Também não foram definidas funcionalidades extras.
    
# Como compilar o projeto:
    
    No projeto foi acrescentada a biblioteca math, string, stdlib, stdio.
    
    Para compilar o projeto, criamos um arquivo Makefile que fará todo esse trabalho para nós. Basta
    rodar o comando "make" estando dentro do projeto no termimal. Depois de compilado, utilizar o comando
    "./main" para que o projeto seja executado. 
    No caso de desejar apagar o arquivo anterior, use o comando "make clean".
    

    
