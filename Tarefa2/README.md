# Avaliação de desempenho
Nesta atividade você deve avaliar e comparar um algoritmo paralelo com a versão sequencial. Para isso, você deverá medir speedup e eficiência do algoritmo paralelo para diferentes números de threads (ex. 2, 4, 8, 16, 32). Utilize para este estudo o algoritmo desenvolvido para a atividade “A.2 Programação Paralela”, que solicitava um programa que identifica quais números em um intervalo são primos.

Instrumente o seu código para medir o tempo de execução ou utilize o comando time do Linux;
Gere os gráficos de speedup e eficiência para diferentes números de threads;
Elabore um breve relatório que inclua os gráficos e adicione a sua interpretação sobre os resultados.  
Como entrega para esta atividade são esperados (i) o relatório, (ii) o código fonte.


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