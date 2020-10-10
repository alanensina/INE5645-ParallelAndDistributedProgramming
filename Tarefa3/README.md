# Problemas de sincronização
Nesta atividade, vocês devem escolher um problema de sincronização apresentado no livro The Little Book of Semaphores, podendo ser qualquer problema descrito nos capítulos 4, 5, 6 ou 7.

Então, você deve descrever o problema, suas características (mencionando potenciais limitações ou variações do problema), além de um algoritmo com as sincronizações necessárias para resolver o problema.

A entrega é na forma de um relatório e o algoritmo pode ser descrito em C ou em uma pseudo-linguagem, suficiente para entender a lógica do problema e da solução.

# Jantar dos filósofos

O Jantar dos filósofos foi proposto por Dijkstra em 1965 como um problema de sincronização. A partir de então todos os algoritmos propostos como soluções de sincronização acabaram sendo relacionados ou testados contra o problema do Jantar dos filósofos.

Cinco filósofos estão sentados em uma mesa redonda para jantar. Cada filósofo tem um prato com espaguete à sua frente. Cada prato possui um garfo para pegar o espaguete. O espaguete está muito escorregadio e, para que um filósofo consiga comer, será necessário utilizar dois garfos. 

Lembre-se que é apenas uma analogia. Nesse sentido, cada filósofo alterna entre duas tarefas: comer ou pensar. Quando um filósofo fica com fome, ele tenta pegar os garfos à sua esquerda e à sua direita; um de cada vez, independente da ordem. Caso ele consiga pegar dois garfos, ele come durante um determinado tempo e depois recoloca os garfos na mesa. Em seguida ele volta a pensar.

# Compilando os projetos: 
_(Necessário ter o compilador GCC instalado)_

Acesse o diretório do projeto pelo terminal e digite:
```
gcc -pthread JantarDosFilosofos.c -o JantarDosFilosofos
```

# Executando os projetos:
Após compilado com o gcc, acesse o diretório do projeto pelo terminal e digite:
```
./JantarDosFilosofos