# OpenMP: Adaptação do "Primo paralelo"
Nesta atividade você deve revisitar o problema definido na Atividade A.2, a qual solicita a implementação de uma solução paralela para identificação de todos os números primos em um intervalo.

O objetivo agora é resolver o mesmo problema utilizando OpenMP ao invés de usar POSIX threads.

# Compilando os projetos: 
_(Necessário ter o compilador GCC instalado)_

Acesse o diretório do projeto pelo terminal e digite:
```
gcc -fopenmp OpenMP.c -o OpenMP
```

# Executando os projetos:
Após compilado com o gcc, acesse o diretório do projeto pelo terminal e digite:
```
./OpenMP <limite>
```

Por exemplo:

```
./OpenMP 50000