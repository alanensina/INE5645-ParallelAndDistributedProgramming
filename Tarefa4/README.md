# Problemas de sincronização 2
Para a atividade anterior (Problemas de Sincronização), você deve implementar um programa em C que modele e o problema e aplicar os mecanismos de sincronização necessária.

# Projeto
O código implementado simula operações de saques e depósitos na mesma conta bancária. Através do uso do Mutex foi possível aplicar locks em zonas críticas, sendo assim o saldo permanece consistente mesmo com threads sendo executadas em paralelo.

# Compilando os projetos: 
_(Necessário ter o compilador GCC instalado)_

Acesse o diretório do projeto pelo terminal e digite:
```
gcc -pthread Main.c -o Main
```

# Executando os projetos:
Após compilado com o gcc, acesse o diretório do projeto pelo terminal e digite:
```
./Main <saldo> <valorDeSaque> <valorDeDeposito>
```

Por exemplo:

```
./Main 50000 250 300