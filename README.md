# Projeto 3.1 da disciplina de Linguagem de Programação 1 - Protótipo de autocomplete

## Descrição

O programa funciona em linha de comando, onde o usuário insere uma sentença e é retornado uma listagem de combinações para a sentença a partir da base de dados que o usuário escolheu na hora de rodar o programa. 

## Executando o programa
* Passo 00 - Para gerar os arquivos iniciais de build, ao rodar o projeto pela primeira vez, use o seguinte comando no diretório raiz: 
> cmake -S ./ -B ./build

* Passo 01 - Para realizar o build do projeto e gerar o arquivo executável, estando em ./build/, use o seguinte comando: 
> cmake --build .

* Passo 02 - Para rodar o programa, utilize, estando em ./build/, o comando:
> ./autocomplete ../data/wiktionary.txt

ou

> ./autocomplete ../data/cities.txt

* Passo 03 - Para testar o programa de forma automática, use o comando abaixo (estando em ./build/):
> ./all_tests

## Autoria

Anny Klarice Fernandes Souza
[anny.klarice.fernandes.127@ufrn.edu.br]
