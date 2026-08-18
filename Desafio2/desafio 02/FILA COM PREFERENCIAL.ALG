Algoritmo "fila com preferencial"

Var
fila: vetor[1..10] de inteiro
nome: vetor[1..10] de caractere
i, pref, aux, cont, res: inteiro
auxc: caractere
procedimento cab()
inicio
escreval("":3,"======================")
escreval("":3,"   Sistema Fila 1.0   ")
escreval("":3,"======================")
fimprocedimento
//
procedimento comecar()
inicio
escreval("":3,"Gostaria de inciar?")
escreval("":3,"[1] Sim")
escreval("":3,"[2] Nao")
escreval("":3,"======================")
escreva("":3,"> Digite a opcao: ")
leia(i)
fimprocedimento
//
procedimento continuar()
inicio
escreval("":3,"Gostaria de adicionar mais um cliente?")
escreval("":3,"[1] Sim")
escreval("":3,"[2] Nao")
escreval("":3,"======================")
escreva("":3,"> Digite a opcao: ")
leia(res)
fimprocedimento
//
procedimento filando()
inicio
limpatela
cab()
escreva("":3,"Nome do cliente: ")
leia(nome[i])
escreva("":3,"Idade de ", nome[i],": ")
leia(fila[i])
se (fila[i] >= 60) entao
auxc <- nome[pref]
nome[pref] <- nome[i]
nome[i] <- auxc
aux <- fila[pref]
fila[pref] <- fila[i]
fila[i] <- aux
pref <- pref + 1
fimse
cont <- cont-1
escreval("":3,"Espacos na fila: ",cont)
fimprocedimento
//
Inicio
repita
   pref <- 1
   cont <- 10
   cab()
   comecar()
   se i = 1 entao
      i <- 0
      repita
         i <- i + 1
         filando()
         se cont > 0 entao
            continuar()
         fimse
      ate (i = 10) ou (res = 2)
      limpatela
      cab()
      cont <- i
      para i de 1 ate cont faca
           escreva("":3)
           se i % 2 = 1 entao
              escreva("|", "":1)
           senao
              escreva("":2)
           fimse
           escreval(i,"º: ", nome[i], " idade: ", fila[i]:3)
      fimpara
      escreval("":3,"======================")
      escreval("":3,"Gostaria de criar outra fila?")
      escreval("":3,"[1] Sim")
      escreval("":3,"[2] Nao")
      escreval("":3,"======================")
      escreva ("":3,"> Digite a opcao: ")
   leia(i)
   fimse
   escreval("  --|___|--")
   escreval("    \O O/")
   escreval("     | |")
   limpatela
ate i <> 1

Fimalgoritmo