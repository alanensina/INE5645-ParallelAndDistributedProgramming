# Tarefa 1
Com base na aula “04 - Extração de Paralelismo em SW”, você deve extrair paralelismo de um algoritmo sequencial e implementar um código paralelo em linguagem C capaz de realizar instruções do algoritmo em paralelo. Você deve usar a biblioteca pthread.h para implementar threads para a execução paralela.

1) Execute um programa sequencial que verifique quais números em um intervalo (ex. 1 a 10.000) são primos. Para determinar se um número x é primo, ele só pode ser divisível por 1 e por x. Ao final da execução, o programa deve imprimir apenas os números primos no intervalo.

2) Implemente uma versão paralela para o seu programa. Você deve explorar execuções com diferentes granularidades entre as tarefas (threads) do seu programa. Para isso, o seu programa deve receber como parâmetro pela linha de comando: (a) o número máximo do intervalo a ser processado, (b) o número de tarefas paralelas a serem executadas.

# Compilando os projetos: 
_(Necessário ter o compilador GCC instalado)_

Acesse o diretório do projeto pelo terminal e digite:
```
gcc -pthread PrimoSequencial.c -o PrimoSequencial
gcc -pthread PrimoParalelo.c -o PrimoParalelo
```

# Executando os projetos:
Após compilado com o gcc, acesse o diretório do projeto pelo terminal e digite:
```
./PrimoSequencial 10000
./PrimoParalelo 10000 4 
```
No primeiro exemplo, no _PrimoSequencial_, será verificado todos os números primos no intervalo de 1 a 10000. Já no segundo exemplo _PrimoParalelo_, será verificado todos os números primos no intervalo de 1 a 10000 em 4 threads paralelamente.