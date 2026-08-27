Algoritmo "Registrar Notas"

Var
nt: vetor[1..3] de real
md: vetor[1..5] de real
nm: vetor[1..5] de caractere
i, qn: inteiro
sm: real
er: logico
procedimento cab()
inicio
escreval("===================")
escreval("  Registrar Notas  ")
escreval("===================")
fimprocedimento
Inicio
qn <- 1
repita
      limpatela
      sm <- 0
      i <- 0
      cab()
      repita
        i <- i+1
        escreva("Escreva a nota ", i,": ")
        leia(nt[i])
        se (nt[i] > 100) ou (nt[i] < -1) entao
           er <- verdadeiro
           nt[i] <- -1
        fimse
      ate (i = 3) ou (nt[i] = -1)
      se nt[i] <> -1 entao
         Escreva("Nome do aluno: ")
         leia(nm[qn])
         para i de 1 ate 3 faca
               sm <- nt[i] + sm
         fimpara
         md[qn] <- sm/3
         qn <- qn+1
      fimse
ate (qn = 5) ou (nt[i] = -1)
limpatela
se er = verdadeiro entao
   escreval("Erro: Nota invalida.")
fimse
se qn = 5 entao
   qn = qn+1
fimse
para i de 1 ate qn-1 faca
     escreval(nm[i]:5,"Média:", md[i])
fimpara

Fimalgoritmo