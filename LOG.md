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

## Sessão 3 – 22/08/2026
**Funcionalidades implementadas hoje:**

- Implementei um conjunto de funções que em conjunto permitem criam uma sala de tamanho arbitrário.
- Verifiquei que de facto é possível criar um gerador de salas aleatório.

**Maior dificuldade encontrada e como resolvi (ou não resolvi):**

Perceber como criar as salas (Rooms) de forma que possam ser geradas só com base em coordenadas de ínico, largura e altura foi complicado. Em particular perceber que tipo de estrutura seria apropriada e como usar essa estrutura para construir as funções para a gerar demorou bastante.
Inicialmente pensei em criar diretamente várias structs do tipo Room, mas devido ao facto de isto seria limitante no desenvolvimento futuro decidi criar um array de pointers, que contem pointers para Rooms criadas pelas funções, baseando-me em como projetos online similares fizeram.
De decidir que este é o melhor percurso a implementar é que foi o problema. Ainda demoro bastante a  entender exatamente o que está a acontecer na máquina relativamente a pointers, por isso progresso é lento.

**Próximo passo planeado:**
...
- Melhorar a geração do mapa (gerar corredores para ligar as salas);
- Implementar inimigos rudimentares;
- Simplificar e limpar o código para posteriormente o dividir em diferentes ficheiros ( o que implica perceber como fazer isso no geral);

**Linhas de código escritas hoje (estimativa):**

- 60 linhas de código no final, provavelmente centenas se contar as diferentes tentativas de implementação.


## Sessão 4 – 23/08/2026
**Funcionalidades implementadas hoje:**

- Simplifiquei o código criando uma struct para as coordenadas, dado que se preciso de aceder à posição de algo preciso da coordenada x e y. A ideia surgiu após ler sugestões feitas online a pessoas com projetos semelhantes.

**Maior dificuldade encontrada e como resolvi (ou não resolvi):**
...
Nada de mais, fora a dificuldade usual de entender o que está a acontecer no código com os pointers. Entender o que uma operação do estilo coordinates.x foi interessante.

**Próximo passo planeado:**
Os mesmos da sessão passada. A sessão de hoje foi curta e só envolveu reescrever algum código.

**Linhas de código escritas hoje (estimativa):**
10 +-, a maiorio foi reescrever código que já existia.

## Sessão 5 – 25(26)/08/2026
**Funcionalidades implementadas hoje:**

- Implementação de corredores entre salas com um algoritmo de distância greedy;
- Implementação de uma nova struct Level para permitir, no futuro, ter diferentes níveis no jogo;
- Implementação básica de monstros. As funções implementadas simplesmente geram os monstros em posições aleatórias de casa sala (tem uma chance de gerar por sala também ) com as suas características implementadas;
- Fiz uma reorganização geral do projeto. Dividi o main.c em diversos ficheiros para cada parte relevante ao trabalho (player, mapa, salas,monstros, níveis). Implementei o  makefile do projeto. 

**Maior dificuldade encontrada e como resolvi (ou não resolvi):**
- Tive grande dificuldade em dividir o projeto por diversos ficheiros. Tive que reinstalar o compilador do C e seguir vários tutoriais até estar tudo funcional.

**Próximo passo planeado:**

- Melhorar (muito provavelmente mudar completamente) o algoritmo dos corredores. De momento não produz o resultado desejado dependendo de onde as portas são geradas.
- Completar os monstros (faze-los mover pelo mapa);
- Criar um sistema de combate;
- Gerador de mapa aleatório (a partir de uma seed gerar um mapa com as respetivas rooms e monstros distribuidos);
- Criar tesouros/items para colocar no mapa;

**Linhas de código escritas hoje (estimativa):**

+- 300 linhas, mais algumas dezenas reescritas ;

## Sessão 6 – 27/08/2026
**Funcionalidades implementadas hoje:**

- Implementei funcionalidade de movimento aos monstros com dois padrões de movimento:
    - Movimento aleatório;
    - Movimento 'seeking', em que o monstro se move em direção à posição do jogador (mesmo algoritmo que para a geração de corredores);
- Implementação básica do sistema de combate;
- Implementação de uma interface básica do jogo;
- Leve reorganização geral do código e melhoria/simplifação de algumas funções; 
**Maior dificuldade encontrada e como resolvi (ou não resolvi):**

Implementar um algoritmo diferente para os corredores provou ser bastante difícil. Não consegui fazer algo que não causa-se SegFaults. Decidi avançar para os passos seguintes. 


**Próximo passo planeado:**

- Gerador de mapa aleatório (a partir de uma seed gerar um mapa com as respetivas rooms e monstros distribuidos);
- Criar tesouros/items para colocar no mapa;
- Melhor o sistema de combate;
- Introduzir mais mecânicas de RPG (Equipamento, diferentes armas, level-ups...) 

**Linhas de código escritas hoje (estimativa):**
 
 +- 200 linhas de código;


## Sessão 7 – 28/08/2026
**Funcionalidades implementadas hoje:**

- Implementei as suguestões feitas no github, nomeadamente:
    - Corrigir a gralha no nome da pasta source,
    - Resolver a questão de os ficheiros .exe estarem a ser enviados para o repositório no github;
    - Resolver a questão de os ficheiros .c não estarem a ser enviados para o github;
- Resolvi também um erro grave no código que causava crashes aleatórios causado por uma chamada imprópria da função rand() no ficheiro room.c; 


**Maior dificuldade encontrada e como resolvi (ou não resolvi):**

 Perceber aonde estava o erro que causava o crash foi demorado, pois achava que estava relacionado com as mudanças relativas ao git. 

**Próximo passo planeado:**

O descrito na sessão anterior.

**Linhas de código escritas hoje (estimativa):**

Neste commit nenhumas, farei outro commit ainda hoje com o progresso real no projeto.



## Sessão 8 – 28/08/2026
**Funcionalidades implementadas hoje:**

- Implementei uma algoritmo de Breadth First Search para criar os túneis entre as rooms.

**Maior dificuldade encontrada e como resolvi (ou não resolvi):**
...
A implementação  do algoritmo Breadth First Search. Traduzir o algoritmo para C, em particular, mantendo a estrutura que já tinha no código foi difícil. Para entender o algoritmo consultei vários recursos online, contudo este [site] (https://www.redblobgames.com/pathfinding/) foi essencial.
Também passei algum tempo no source code (e discussões do mesmo) do jogo [NetHack] (https://github.com/NetHack/NetHack), que serviu como inspiração para este projeto, que foi interessante mas não muito útil.  

**Próximo passo planeado:**

As  que tinha referido na sessão 6, ao que acrescento a criação de um menu e end game screen.


**Linhas de código escritas hoje (estimativa):**

+- 150 linhas de código.

## Sessão 9 – 29/08/2026
**Funcionalidades implementadas hoje:**

- Reescrita do código para desacupular as funções que geram objetos das funções que lhes dão print;
- Reescrita do main.c e da estrutura que inicializa o jogo;;
- Implementação de um menu inicial, bem como, as funções responsáveis por geral outros menus;
- Implementação de uma 'death' flag, ou seja, quando o jogador estiver a zero HP, o jogo termina.


**Maior dificuldade encontrada e como resolvi (ou não resolvi):**

Não consegui fazer a implementação de items nem maneiras de mudar de nível de forma conveniente. Obtive imensos e erros crashs sem explicação bem como SegFaults ao ponto de abandonar o método que pretendia utilizar que consistia em criar condições no mapa para a mudança de nível.
Relativamente aos items, a abordagem inicial de criar uma função que gera structs para cada items também não funcinou. 
Amanhã tentarei implementar algo mais simples devido as limitações de tempo.

**Próximo passo planeado:**

- Finalizar o sistema de combate -> usar a AC (armour class) para determinar a chance de acertar um ataque tanto para o jogador como os monstros;
- Implementar um sistema simples de tesouros (somente ouro devio a limitações de tempo) espalhados pelo mapa;
- Implementar um inventário para o jogador ativado por uma tecla (i) contendo poções que possam ser usadas;
- Implementar a mudança de níveis do mapa;
- Implementar simples de nível do personagem do jogador;
- Reescrever o README file; 

**Linhas de código escritas hoje (estimativa):**

+- 250 contando com a reesccrita de funções/restruturação do main.c.

## Sessão 10 – 30/08/2026
**Funcionalidades implementadas hoje:**

- Implemententação de um sistema de AC para monstros e o jogador e uma função que usa esse valor para determinar a change de acertar;
- Reescrita substancial do sistema de interação entre jogador e monstros, bem como o pathfinding dos mesmos;
- Implementação de funções que geram items, usadas somente para colocar ouro ($) e poções de HP (!) no mapa. Contudo estão desenhas para suportar qualquer tipo de item da forma struct item. Por questões de tempo esses outros items não foram implementados;
- Implementação de um sistema de inventário para o jogador. Não foi possível implementar um menu separado para o mesmo, mas a arquitetura estabelicida foi usada apresentar o número de poções disponíveis ao jogador que se altera dinamicamente comforme estas são apanhas do mapa e consumidas;
- Implementação de um sistema para 'pick up' de ouro e poções, bem como funções para o consumo de poções;
- Implementação de um sistema level up para o personagem do jogador (subida de nível implica aumento do HP máximo, AC e dano);
- Implementação de um sistemas de níveis para o jogo. Quando o personagem entra nas escadas (<) desce de nível. Existem monstros mais perigosos quão mais fundo o jogador for;
- Aumento dos elementos de diferenciação entre os monstros (diferentes montantes de XP);
- Reescrita substancial um pouco por todo o código no decorrer da implementação das funcionalidades descritas anteriormente. Foco particular em questões de gestão de memória e pointers soltos;
- Reescrita do README file;

**Maior dificuldade encontrada e como resolvi (ou não resolvi):**

Enorme dificuldade em implementar o sistema de mudança de nível. Envolveu reescrever grande parte do levels.c e do game.c e uma reorganização estrutural do código como um todo.
Em particular, foi preciso repensar a implementação da função create_level e da main_game_loop. 

**Próximo passo planeado:**

NA - Apresentação

**Linhas de código escritas hoje (estimativa):**

350-400 linhas de código.