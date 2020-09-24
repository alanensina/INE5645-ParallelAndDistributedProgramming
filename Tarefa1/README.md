#Tarefa 1
Com base na aula “04 - Extração de Paralelismo em SW”, você deve extrair paralelismo de um algoritmo sequencial e implementar um código paralelo em linguagem C capaz de realizar instruções do algoritmo em paralelo. Você deve usar a biblioteca pthread.h para implementar threads para a execução paralela.

1) Execute um programa sequencial que verifique quais números em um intervalo (ex. 1 a 10.000) são primos. Para determinar se um número x é primo, ele só pode ser divisível por 1 e por x. Ao final da execução, o programa deve imprimir apenas os números primos no intervalo.

2) Implemente uma versão paralela para o seu programa. Você deve explorar execuções com diferentes granularidades entre as tarefas (threads) do seu programa. Para isso, o seu programa deve receber como parâmetro pela linha de comando: (a) o número máximo do intervalo a ser processado, (b) o número de tarefas paralelas a serem executadas.

Ex.: As invocações do programa abaixo representam o cálculo de quais números são primos no intervalo de 1 à 10000, sendo computados por 32 e 4 threads, respectivamente.

./PrimoSequencial 10000

./PrimoParalelo 10000 32

./PrimoParalelo 10000 4