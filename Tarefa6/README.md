# OpenMP: Contador de palavras
Nesta atividade, você deve desenvolver duas versões para um programa que conta palavras em um texto.

Dado um texto e um conjunto de "palavras chave", crie um programa sequencial que contabiliza o número de ocorrências de cada palavra
Implemente uma versão paralela para o mesmo programa usando OpenMP

# Compilando os projetos: 
_(Necessário ter o compilador GCC instalado)_

Acesse o diretório do projeto pelo terminal e digite:
```
gcc ContadorSequencial.c -o ContadorSequencial
gcc -fopenmp ContadorOpenMP.c -o ContadorOpenMP
```

# Executando os projetos:
Após compilado com o gcc, acesse o diretório do projeto pelo terminal e digite:
```
./ContadorSequencial 
./ContadorOpenMP 
```