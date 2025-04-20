//
//#include "foo.h"
//
//int foo(int a,int b){
//	return a-b-1;
//}
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DateProblem.h"

// Função para verificar se o ano é bissexto
int ehBissexto(int ano) {
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

// Função principal: calcula a próxima data
char* NextDate(int mes, int dia, int ano) {
    static char resultado[11];  // Buffer para "DD/MM/AAAA" + '\0'
    int diasPorMes[] = { 0, 31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 }; // Índice 0 é ignorado

    // Validações
    if (mes < 1 || mes > 12)
        return "E01";  // Mês inválido
    if (dia < 1 || dia > 31)
        return "E02";  // Dia inválido
    if (ano < 1900 || ano > 2099)
        return "E03";  // Ano inválido

    // Ajusta fevereiro para anos bissextos
    if (mes == 2 && ehBissexto(ano)) {
        diasPorMes[2] = 29;
    }

    // Verifica se a data é válida
    if (dia > diasPorMes[mes])
        return "E04";  // Data inválida (ex: 30/02/2023)

    // Incrementa o dia
    dia++;
    if (dia > diasPorMes[mes]) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            ano++;
        }
    }

    // Formata a data de saída
    snprintf(resultado, sizeof(resultado), "%02d/%02d/%04d", dia, mes, ano);
    return resultado;
}

// Exemplo de uso
//int main() {
//    //int dia = 28, mes = 2, ano = 2024;
//    int dia, mes, ano;
//    scanf("%d %d %d", &dia, &mes, &ano);
//
//    char* proximaData = NextDate(mes, dia, ano);
//    printf("Data seguinte: %s\n", proximaData);
//    return 0;
//}
