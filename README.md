# Projeto de Desenho Gráfico
Projeto final da disciplina de Introdução às Técnicas de Programação, ministrada pelo professor Gustavo Girão no Bacharelado de Tecnologia da Informação da UFRN. 2019.2.

## Sobre
Nosso projeto é um gerador de imagens <a href="http://netpbm.sourceforge.net/doc/ppm.html">`.ppm`</a>  [go](http://stackoverflow.com){:target="_blank" rel="noopener"}
 feito em C. É possível desenhar retas, curvas, polígonos, pintar a partir de comandos escritos em um arquivo de texto. 
## Tipos

## Funções
### Painting
Dentro do arquivo `painting.c` estão contidas as funções relacionadas a "pintura" da imagem, isto é, definir a cor RGB dos pixels da matriz.

#### Clear
Limpa a imagem, setando todos os pixels para a cor especificada. Esta função recebe 3 valores inteiros que representam uma cor RGB.

Ex: `clear 0 0 0`

![image](https://user-images.githubusercontent.com/47838241/69669342-6d0a6200-1070-11ea-998a-3584cf42b8f4.png)

#### Color

![image](https://user-images.githubusercontent.com/47838241/69669766-43056f80-1071-11ea-9be7-5f801dc2444c.png)

#### Fill

![image](https://user-images.githubusercontent.com/47838241/69669944-a0012580-1071-11ea-8680-308c038301c7.png)

#### paintCirclePoints

![image](https://user-images.githubusercontent.com/47838241/69670066-d048c400-1071-11ea-9c87-d39cb003fb51.png)

### Shapes

#### line

![image](https://user-images.githubusercontent.com/47838241/69670582-fd49a680-1072-11ea-9186-b1ee8e4211c3.png)

#### line2

![image](https://user-images.githubusercontent.com/47838241/69670518-dd19e780-1072-11ea-8268-8a647d853be9.png)


#### circle

![image](https://user-images.githubusercontent.com/47838241/69670697-397d0700-1073-11ea-95d4-c477022ef061.png)

#### rect

![image](https://user-images.githubusercontent.com/47838241/69670742-53b6e500-1073-11ea-8774-b41575361bcb.png)

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
