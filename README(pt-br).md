# Projeto de Desenho Gráfico
Projeto final da disciplina de Introdução às Técnicas de Programação, ministrada pelo professor Gustavo Girão no Bacharelado de Tecnologia da Informação da UFRN. 2019.2.

<p align="center">
 <img src="https://github.com/arturo32/DrawingProject/blob/216c31c9ac130f11ee00acf756ddf9eda12e7050/Examples/Hexagons%20and%20curves.png"
   alt="A imagem é um quadrado, em sua maior parte preto, com 4 hexágonos finos brancos, um dentro do outro vindo do centro. Um conjunto de curvas surgem do canto superior esquerdo e do canto inferior direito."/>
</p>

## Sobre
Nosso projeto é um gerador de imagens <a href="http://netpbm.sourceforge.net/doc/ppm.html">`.ppm`</a> feito em C. É possível desenhar retas, curvas, polígonos, pintar a partir de comandos escritos em um arquivo de texto.
É importante notar que nosso programa funciona como uma grande matriz, isto é, o ponto (0, 0) está no canto superior esquerdo da imagem, quanto maior a primeira coordena, mais a direita ele estará e quanto maior a segunda coordenada mais para baixo ele estará.

## Tipos
 * **Pixel** Tipo usado para criar uma matriz de pixels que representa a imagem ppm e para armazenar a cor atual que será usada em todo o código. Esse tipo é composto por 3 *unsigned char* que representam os valores RGB da cor, respectivamente.

 * **Image** Tipo usado para armazenar a imagem composta por uma matriz de Pixels and pela sua altura e largura.
 
## Funcionalidades
### Funções de Pintura
Dentro do arquivo `painting.c` estão contidas as funções relacionadas a "pintura" da imagem, isto é, define a cor RGB dos pixels da matriz.

* **Limpar** Limpa a imagem, setando todos os pixels para a cor especificada. Esta função recebe 3 valores inteiros que representam uma cor RGB.

   `clear <valor_R> <valor_G> <valor_B>`

* **Definir cor** Recebe um valor RGB e o define como a cor atual que será usada.

   `color <valor_R> <valor_G> <valor_B>`

* **Preencher** Preenche um espaço da imagem até encontrar as bordas de alguma figura(ou seja, um pixel com a cor RGB diferente do pixel inicial) ou o fim da imagem. Está função recebe o ponto inicial (par xy), onde vai ser iniciado o preenchimento. Funciona com recursão. <b>CUIDADO: Não use essa função em áreas muito grandes (maiores que 500 por 500 pixels), pode causar stack overflow.</b>

   `fill <x_incial> <y_inicial>`

### Funções de Desenho
As funções para realizar desenhos na imagem estão contidas no arquivo `shapes.c`.

* **Linha** Essa função desenha uma linha a partir de dois pontos especificados (dois pares xy) pelo usuário utilizando o <a href="https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html">Algoritmo de Bresenham</a>.

   `line <x_inicial> <y_inicial> <x_final> <y_final>`

* **Círculo** Desenha um círculo a partir da posição do seu centro (par xy) e do seu raio.

   `circle <x_central> <y_central> <raio>`

* **Retângulo** Desenha um retângulo a partir da posição (xy) do seu canto superior esquerdo seguido de sua altura e largura.

   `rect <x_ponto_superior_esquerdo> <y_ponto_superior_esquerdo> <altura> <largura>`
   
* **Polígono** Desenha um polígono delimitado por uma lista de pontos. O primeiro parâmetro é a quantidade de pontos n seguido pelos n pontos (par xy).

   `polygon <qtd_pontos_n> <x_ponto_1> <y_ponto_1> <x_ponto_2> <y_ponto_2>... <x_ponto_n> <y_ponto_n>`

### Funções de Entrada e Saída
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

* **Curvas de Bézier** O método para desenhar curvas de Bézier recebe 3 pontos (pares x,y) como parâmetros: o ponto inicial, o ponto de inflexão e o ponto final. 
   O método usado na implementação das curvas de Bézier se baseia fundamentalmente na <a href="https://www.youtube.com/watch?v=mAi2-LTC2CA">interpolação linear</a>. Vale ressaltar todas as curvas feitas no projeto são do tipo quadrática.
   
   O desenho das curvas pode ser feito de duas formas. A primeira em que o usuário especifica os 3 pontos de controle para a construção da curva, e pode ser chamado da seguinte forma:
  
   `curve <x_inicial> <y_inicial> <x_inflexão> <y_inflexão> <x_final> <y_final>`
  
   A outra forma, é especificando apenas o ponto inicial e o número de curvas desejadas. Dessa forma, todos os outros pontos serão definidos de forma aleatória, pode ser chamado pelo seguinte comando:
  
   `randcurve <numero_de_curvas> <x_inicial> <y_inicial>`

* **Polígonos Regulares** Desenha um polígono regular a partir do seu número de lados, raio(de um círculo circunscrito), ângulo de rotação e pelo seu ponto central. O ângulo de rotação é convertido para radianos e a rotação é implementada no sentido anti-horário. Os 360º do círculo é divido igualmente para o número de lados e utiliza o seno e cosseno para achar as coordenadas dos vértices da figura e depois é utilizado o algorítimo de linhas para traçar as retas do polígono.

   `rpolygon <numero_de_lados> <raio> <rotacao> <x_central> <y_central>`

## O que teríamos feito diferente

* **Função fill** Como dito anteriormente nossa função fill só funciona para áreas pequenas por conta do stack overflow causado pelas inúmeras chamadas da função recursiva. Gostaríamos de ter implementado uma estrutura de dados como *queue* usando alocação dinâmica em vez da função recursiva, mas esse conteúdo foge do escopo da disciplina e não tivemos tempo suficiente para pesquisar sobre.  

## Autores
* <a href="https://github.com/artursantiago">Artur Santiago</a>
* <a href="https://github.com/arturo32">Arturo Fonseca</a>

### Contribuições de cada um

* **Artur Santiago**
  * Modularização
  * Polígonos
  * Círculos
  * Retângulos
  * Documentação

* **Arturo Fonseca**
  * Polígonos Regulares
  * Curvas de Bézier
  * Linhas
  * Função Fill
