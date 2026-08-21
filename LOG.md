## Sessão 1 – 19/08/2026

Sendo a primeira sessão o objetivo será estudar a viabilidade da ideia, procurar recursos online se a idea for exequivel dentro prazo dado e dar o setup do main.c.

**Funcionalidades implementadas hoje:**

- Criar o main.c;
-Instalar o Ncurses e tentar correr o main.c como teste;

**Maior dificuldade encontrada e como resolvi (ou não resolvi):**

O compilador MSYS2 UCRT64 GCC não estava a reconhecer a instalação do Ncurses. Resolvi através da command line.

A minha instalação do C está com problemas e o VScode não reconhece o compilador MSYS2 UCRT64 GCC, e dá vários erros relacionados com a Ncurses. 

**Próximo passo planeado:**

Resolver o problema relacionado com o compilador e com a Ncurses;
Criar a estrutura básica do jogo.
**Linhas de código escritas hoje (estimativa):**


## Sessão 2 – 21/08/2026
**Funcionalidades implementadas hoje:**

- O Ncurses está a funcionar!

- Implementei a base que será usada para mover o  Player e guardar informações sobre o mesmo através da estrutura Struct; 
    - Aprendi bastante sobre boas práticas de como implementar este tipo de objeto (se usar typedef vs só struct) [aqui] (https://stackoverflow.com/questions/1675351/typedef-struct-vs-struct-definitions);
- Implementei uma função rudimentar que desenha o mapa (de momento apenas uma sala);
- Implementei a função que altera o struct Player e permite dar update a posição do utilizador e que dá print ao 'Avatar' do mesmo (@); 
- Implementei uma função que verifica o carácter onde o cursor está, que permite em conjunto com a função que move o Avatar impedir o utilizador de atravessar paredes. Permitirá no futuro ao jogo identificar se o utilizador está a mover para uma posição com tesouro,monstros, etc.



**Maior dificuldade encontrada e como resolvi (ou não resolvi):**

- Através de pesquisa online sobre o funcionamento do VSCode e do próprio C consegui ligar a biblioteca NCurses ao meu projeto.
    - Contudo não consegui colocar o terminal do VSCode a correr o terminal associado ao UCRT, dado que tenho que usar o terminal do mesmo para testar o código.
- Aprender como utilizar os pointers à struct Player e fazer as funções de mover o avatar e detetar o carácter funcionarem.
    - Aprender mais sobre pointers em geral.

-
**Próximo passo planeado:**

- Implementar uma função que crie partes do mapa (rooms), verificar a viabilidade de criar um gerador de salas aleatório;
- Implementar inimigos rudimentares;  

**Linhas de código escritas hoje (estimativa):**

- 130 linhas +-;
..