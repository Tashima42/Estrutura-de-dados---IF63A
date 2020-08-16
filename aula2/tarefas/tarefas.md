Utilizando a estrutura de pilha, resolva os seguintes problemas:

1 - Utilizando a estrutura de pilhas dinâmica, resolva o problema de decidir se uma dada sequência de parênteses e colchetes está bem-formada (ou seja, parênteses e colchetes são fechados na ordem inversa àquela em que foram abertos).  Por exemplo, a sequência ( ( ) [ ( ) ] ) está bem formada, enquanto que a sequência ( [ ) ]   está malformada.



2 - João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada “.<...<<..>>....>....>>>.”, três diamantes são formados.

Exemplos: 

“<..><.<..>>” Resp: 2

“<<<..<......<<<<....>” Resp: 1

Escreva um programa que receba uma string e imprima o número de diamantes encontrados.



3 - Há um estacionamento muito estreito, no qual os carros são estacionados em uma fila sequencial conforme chegam no estacionamento. Todavia, para retirar um carro, o manobrista precisa retirar todos os carros que chegaram depois do carro estacionado e depois voltá-los no estacionamento mantendo a mesma ordem que estavam. Faça um programa que conte quantas vezes o manobrista precisa retirar um carro e voltá-lo ao estacionamento durante um dia. Primeiro o sistema recebe todas as operações de entrada e retirada e após finalizado, exibe o número de vezes que o manobrista teve que retirar um carro e voltá-lo para o estacionamento. Considere que a placa de um carro é um número inteiro.  Por exemplo:

           Entra: 1341 1234 2342 

           Sai:  1234

           Entra: 3325 1634

           Sai:  2342  

           Sai: 1341

	Resposta: 5