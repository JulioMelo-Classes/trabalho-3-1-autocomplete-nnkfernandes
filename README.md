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

# Avaliação

## Ler e validar os argumentos da linha de comando | 8 / 10

- Faltou validar o conteúdo do arquivo.

## Ler os dados da base de dados e armazená-los em uma classe apropriada | 10 / 10

- ok

## Separar a interface textual das demais classes do sistema concentrando os couts e cins em um único objeto | 10 / 10

- ok

## Implementação de uma classe para conter o resultado da requisição do usuário | 3 / 10

- Acho que a classe match serviria para esse fim. Porém a forma como você fez, onde a classe basicamente é um conjunto de métodos
não faz muito sentido. Uma sugestão de modelagem seria vc colocar o método de busca dentro de DataBase e retornar uma instancia da classe
Match contendo o resultado da busca.

## Implementação eficiente através de referencias e algoritmos de busca binária | 5 / 10

- Voce implementou a busca binária, porém não usou da forma correta para encontrar os limites superior e inferior do conjunto. Além disso o código tem muitos
usos de cópias, especialmente de containers. Uma sugestão é usar referencias nos parâmetros de função e retornar ponteiros (ou não retornar containers) quando
for necessário retornar containers.

## Organização do código em src, include, data | 5 / 5

- ok

## Documentação do código usando o padrão doxygen | 3 / 5

- Faltou documentar os atributos

## Implementação e documentação de arquivos de teste | 10 / 10

- Acho que eu daria 11 de 10, muito bom seu esquema de testes!
