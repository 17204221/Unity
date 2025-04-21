#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DateProblem.h"

// Função para verificar se o ano eh bissexto
int ehBissexto(int ano) {
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

// Funcao calcula a proxima data
char* NextDate(int dia, int mes, int ano) {
    static char resultado[11];  // Buffer para "DD/MM/AAAA" + '\0'
    //static char lixo[50];
    int diasPorMes[] = { 0, 31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 }; 
     
    // Valida limites de entrada 
    if (mes < 1 || mes > 12) 
        return "E01";
    
    if (dia < 1 || dia > 31) 
        return "E02";

    if (ano < 1900 || ano > 2099) 
        return "E03";


    // Ajusta fevereiro para anos bissextos
    if (mes == 2 && ehBissexto(ano)) {
        diasPorMes[2] = 29;
    }

    // Verifica se a data eh valida
    if (dia > diasPorMes[mes])
        return "E04";  // ex: 30/02/2023

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

    // Formata saida
    snprintf(resultado, sizeof(resultado), "%02d/%02d/%04d", dia, mes, ano);
    return resultado;
}

// Main apenas para teste
//int main() {
//   
//    int dia, mes, ano;
//    scanf("%d %d %d", &dia, &mes, &ano);
//
//    char* proximaData = NextDate(mes, dia, ano);
//    printf("Data seguinte: %s\n", proximaData);
//    return 0;
//}