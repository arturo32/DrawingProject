# Projeto de Desenho Gráfico
Projeto final da disciplina de Introdução às Técnicas de Programação, ministrada pelo professor Gustavo Girão no Bacharelado de Tecnologia da Informação da UFRN. 2019.2.

## Sobre
Nosso projeto é um gerador de imagens <a href="http://netpbm.sourceforge.net/doc/ppm.html">`.ppm`</a> feito em C. É possível desenhar retas, curvas, polígonos, pintar a partir de comandos escritos em um arquivo de texto. 
## Tipos
 * Pixel

 * Image
 
## Funções
### Painting
Dentro do arquivo `painting.c` estão contidas as funções relacionadas a "pintura" da imagem, isto é, definir a cor RGB dos pixels da matriz.

* Clear

Limpa a imagem, setando todos os pixels para a cor especificada. Esta função recebe 3 valores inteiros que representam uma cor RGB.

Ex: `clear 0 0 0`

* Color

* Fill

* paintCirclePoints

### Shapes

* line

* line2 

* circle

* rect

### Input and Output



## Como usar //escrever melhor
Para compilar o arquivo no Linux, digite no terminal na pasta onde se encontra os arquivos do projeto:
```
make
./ppm config.txt
```

## O que teríamos feito diferente

* Recursão da função fill

## Autores
* <a href="https://github.com/artursantiago">Artur Santiago</a>
* <a href="https://github.com/arturo32">Arturo Fonseca</a>
