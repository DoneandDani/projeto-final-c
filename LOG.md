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