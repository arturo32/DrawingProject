# Projeto de Desenho Gráfico
Projeto final da disciplina de Introdução às Técnicas de Programação, ministrada pelo professor Gustavo Girão no Bacharelado de Tecnologia da Informação da UFRN. 2019.2.

## Sobre
Nosso projeto é um gerador de imagens <a href="http://netpbm.sourceforge.net/doc/ppm.html">`.ppm`</a> feito em C. É possível desenhar retas, curvas, polígonos, pintar a partir de comandos escritos em um arquivo de texto.
É importante notar que nosso programa funciona como uma grande matriz, isto é, o ponto (0, 0) está no canto superior esquerdo da imagem, quanto maior a primeira coordena, mais a direita ele estará e quanto maior a segunda coordenada mais para baixo ele estará.

## Tipos
 * **Pixel** Tipo usado para criar uma matriz de pixels que representa a imagem ppm e para armazenar a cor atual que será usada em todo o código. Esse tipo é composto por 3 *unsigned char* que representam os valores RGB da cor, repectivamente.

 * **Image** Tipo usado para armazenar a imagem composta por uma matriz de Pixels and pela sua altura e largura.
 
## Funcionalidades
### Funções de Pintura
Dentro do arquivo `painting.c` estão contidas as funções relacionadas a "pintura" da imagem, isto é, definir a cor RGB dos pixels da matriz.

* **Clear** Limpa a imagem, setando todos os pixels para a cor especificada. Esta função recebe 3 valores inteiros que representam uma cor RGB.

   `clear <valor_R> <valor_G> <valor_B>`

* **Color** Rcebe um valor RGB e o define como a cor atual que será usada.

   `color <valor_R> <valor_G> <valor_B>`

* **Fill** Preenche um espaço da imagem até encontrar as bordas de alguma figura(ou seja, um pixel com a cor RGB diferente do pixel inicial) ou o fim da imagem. Está função recebe o ponto inical(par xy), onde ser iniciado o preenchimento.

   `fill <x_incial> <y_inicial>`

### Funções de Desenho
As funções para realizar desenhos na imagem estão contidas no arquivo `shapes.c`.

* **Linha** Essa função desenha uma linha a partir de dois pontos específicados (dois pares xy) pelo usuário utilizando o <a href="https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html">Algoritmo de Bresenham </a>.

   `line <x_inicial> <y_inicial> <x_final> <y_final>`

* **Círculo** Desenha um círculo a partir da posição do seu centro(par x,y) e do seu raio.

   `circle <x_central> <y_central> <raio>`

* **Retângulo** Desenha um retângulo a partir da posição x,y do seu canto superior esquerdo seguido de sua altura e largura.

   `rect <ponto_x_superior_esquerdo> <ponto_y_superior_esquerdo> <altura> <largura>`
   
* **Polígono** Desenha um polígono delimitado por uma lista de ponto. O primeiro parâmetro é a quantidade de pontos n seguido pelos n pontos(par x,y).

   `polygon <qtd_pontos_n> <x_ponto_1> <y_ponto_1> <x_ponto_2> <y_ponto_2>... <x_ponto_n> <y_ponto_n>`

### Funçes de Entrada e Saída
As funções que não se relacionam com a manipulação da imagem de fato, mas se relacionam com a leitura e criação de arquivos, estão contidas no arquivo `IO.c`.

* **Criar Imagem** Cria uma nova "imagem", com a largura e altura especificadas.

   `image <altura> <largura>`
   
* **Salvar Imagem** Salva a imagem criada em um determinado arquivo usando o formato ppm. Recebe o nome da imagem seguido pela extensão *.ppm*.

   `save <nome_da_imagem.ppm>`

## Como Compilar
Para compilar o arquivo no Linux, digite no terminal na pasta onde se encontra os arquivos do projeto:
```
make
./ppm config.txt
```
O *ppm* é o nome do arquivo executável que o make gera e o *config.txt* é o arquivo que possui os comandos para criação da imagem ppm.

Exemplo do arquivo config.txt:
```
image 600 400
clear 0 0 0
color 100 170 200
line 0 400 600 200
polygon 3 0 400 300 200 600 400
circle 200 100 50
color 180 30 50
fill 300 300
save test.ppm
```
OBS: O arquivo *config.txt* deve conter no mínimo 3 comandos : *image*, *clear* e *save*;

## Extras

* **Curvas de Bezier**

* **Polígonos Regulares**

## O que teríamos feito diferente

* **Função fill** Como dito anteriormente nossa função fill só funciona para áreas pequenas por conta do stackoverflow causado pelas inúmeras chamadas da função recursiva. Gostaríamos de ter implementado uma estrutura de dados como *queue* usando alocação dinâmica em vez da função recursiva, mas esse conteúdo foge do escopo da disciplina e não tivemos tempo suficiente para pesquisar sobre.  

## Autores
* <a href="https://github.com/artursantiago">Artur Santiago</a>
* <a href="https://github.com/arturo32">Arturo Fonseca</a>

### Contribuiçes de cada um

* **Artur Santiago**
  * Modularização
  * Polígonos
  * Círculos
  * Retângulos
  * Documentação

* **Arturo Fonseca**
  * Polígonos Regulares
  * Curvas de Bezier
  * Linhas
  * Função Fill
