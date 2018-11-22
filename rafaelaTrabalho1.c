// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Rafaela Santos Fernandes de Jesus
//  email: rafaela.sjfernandes@gmail.com
//  Matrícula: 2015216016
//  Semestre: 2018.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int validaData(char *data, int *Dia, int *Mes, int *Ano);
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){

    char d[3], m[3], a[5];
    int i = 0, j = 0, y = 0, t = 0, u = 0;
    int dia, mes, ano;
    int datavalida = 1;

    for(i = 0; data[i] != '/'; i++){
        d[i] = *(data + i);
    }
    d[i] = '\0';
    dia = atoi(d);

    for(j = i+1, y = 0; data[j] != '/'; j++, y++){
        m[y] = *(data + j);
    }
    m[y] = '\0';
    mes = atoi(m);

    for(t = j+1, u = 0; data[t] != '\0'; t++, u++){
        a[u] = *(data + t);
    }
    a[u] = '\0';
    ano = atoi(a);

    if((mes >= 1 && mes <= 12) && (dia >= 1 && dia <= 31)){

        switch(mes){
            case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
	        if(dia >= 1 && dia <= 31){
		    datavalida = 1;
		}
		else{
		    datavalida = 0;
		}
		break;
            case 4:
	    case 6:
	    case 9:
            case 11:
	        if(dia >= 1 && dia <= 30){
		    datavalida = 1;
		}
		else{
		    datavalida = 0;
		}
		break;
            case 2:
		if((dia >= 1 && dia <= 29) && (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0))){
		    datavalida = 1;
		}
		else if(dia >= 1 && dia <= 28){
		    datavalida = 1;
		}
		else{
		    datavalida = 0;
		}
		break;
            default:
		datavalida = 0;
        }
    }
    else{
        datavalida = 0;
    }

    if(datavalida){
        return 1;
    }
    else{
        return 0;
    }
}

int validaData(char *data, int *Dia, int *Mes, int *Ano){

    char d[3], m[3], a[5];
    int i = 0, j = 0, y = 0, t = 0, u = 0;
    int dia, mes, ano;
    int datavalida = 1;

    for(i = 0; data[i] != '/' ; i++){
        d[i] = *(data + i);
    }
    d[i] = '\0';
    dia = atoi(d);
    *Dia = dia;

    for(j = i+1, y = 0; data[j] != '/'; j++, y++){
        m[y] = *(data + j);
    }
    m[y] = '\0';
    mes = atoi(m);
    *Mes = mes;

    for(t = j+1, u = 0; data[t] != '\0'; t++, u++){
        a[u] = *(data + t);
    }
    a[u] = '\0';
    ano = atoi(a);
    *Ano = ano;

    if((mes >= 1 && mes <= 12) && (dia >= 1 && dia <= 31)){

        switch(mes){
	    case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
	        if(dia >= 1 && dia <= 31){
		    datavalida = 1;
		}
		else{
		    datavalida = 0;
		}
		break;
	    case 4:
	    case 6:
	    case 9:
	    case 11:
	        if(dia >= 1 && dia <= 30){
		    datavalida = 1;
		}
		else{
		    datavalida = 0;
		}
		break;
	    case 2:
	        if((dia >= 1 && dia <= 29) && (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0))){
		    datavalida = 1;
		}
		else if(dia >= 1 && dia <= 28){
		    datavalida = 1;
		}
		else{
		    datavalida = 0;
		}
		break;
	    default:
	        datavalida = 0;
        }
    }
    else{
        datavalida = 0;
    }

    if(datavalida){
        return 1;
    }
    else{
        return 0;
    }
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){

    int validar_inicial = 0, validar_final = 0, diaInicial, diaFinal, mesInicial, mesFinal, anoInicial, anoFinal;
    int nDias = 0, nMeses = 0, nAnos = 0;
    int i, cont_bis = 0;

    //se a data for invalida
    validar_inicial = validaData(datainicial, &diaInicial, &mesInicial, &anoInicial);
    if (validar_inicial == 0){
        return 2;
    }
    validar_final = validaData(datafinal, &diaFinal, &mesFinal, &anoFinal);
    if (validar_final == 0){
        return 3;
    }
    // se a data inicial for maior que a final
    if((diaInicial > diaFinal) && (mesInicial > mesFinal) && (anoInicial > anoFinal)){
        return 4;
    }
    else if((diaInicial > diaFinal) && (mesInicial > mesFinal) && (anoInicial == anoFinal)){
        return 4;
    }
    else if((diaInicial > diaFinal) && (mesInicial == mesFinal) && (anoInicial == anoFinal)){
        return 4;
    }
    else if((diaInicial < diaFinal) && (mesInicial > mesFinal) && (anoInicial > anoFinal)){
        return 4;
    }
    else if((diaInicial < diaFinal) && (mesInicial == mesFinal) && (anoInicial > anoFinal)){
        return 4;
    }
    else if((diaInicial < diaFinal) && (mesInicial < mesFinal) && (anoInicial > anoFinal)){
        return 4;
    }
    else if((diaInicial == diaFinal) && (mesInicial == mesFinal) && (anoInicial > anoFinal)){
        return 4;
    }
    //data inicial for menor que a final
    else if((diaInicial == diaFinal) && (mesInicial == mesFinal) && (anoInicial < anoFinal)){

	switch(mesInicial){
            case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
                for(i = mesInicial; i < mesFinal; i++){
		    nMeses++;
		}

                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                      cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (31 - diaInicial) + diaFinal;
                if(nDias >= 31){
                    nDias = ((31 - diaInicial) + diaFinal)%31;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                for(i = mesInicial; i < mesFinal; i++){
                    nMeses++;
                }
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (30 - diaInicial) + diaFinal;
                if(nDias >=30){
                    nDias = ((30 - diaInicial) + diaFinal)%30;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 2:
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                if(cont_bis > 0){
                    nDias = (29 - diaInicial) + diaFinal;
                    if(nDias >= 29){
                        nDias = ((29 - diaInicial) + diaFinal)%29;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                else{
                    nDias = (28 - diaInicial) + diaFinal;
                    if(nDias >=28){
                        nDias = ((28 - diaInicial) + diaFinal)%28;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                break;
        }
    }
    else if((diaInicial < diaFinal) && (mesInicial < mesFinal) && (anoInicial < anoFinal)){

        switch(mesInicial){
            case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
                for(i = mesInicial; i < mesFinal; i++){
		    nMeses++;
		}

                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                      cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (31 - diaInicial) + diaFinal;
                if(nDias >= 31){
                    nDias = ((31 - diaInicial) + diaFinal)%31;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                for(i = mesInicial; i < mesFinal; i++){
                    nMeses++;
                }
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (30 - diaInicial) + diaFinal;
                if(nDias >=30){
                    nDias = ((30 - diaInicial) + diaFinal)%30;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 2:
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                if(cont_bis > 0){
                    nDias = (29 - diaInicial) + diaFinal;
                    if(nDias >= 29){
                        nDias = ((29 - diaInicial) + diaFinal)%29;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                else{
                    nDias = (28 - diaInicial) + diaFinal;
                    if(nDias >=28){
                        nDias = ((28 - diaInicial) + diaFinal)%28;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                break;
        }
    }
    else if((diaInicial < diaFinal) && (mesInicial < mesFinal) && (anoInicial == anoFinal)){

       switch(mesInicial){
            case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
                for(i = mesInicial; i < mesFinal; i++){
		    nMeses++;
		}

                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                      cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (31 - diaInicial) + diaFinal;
                if(nDias >= 31){
                    nDias = ((31 - diaInicial) + diaFinal)%31;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                for(i = mesInicial; i < mesFinal; i++){
                    nMeses++;
                }
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (30 - diaInicial) + diaFinal;
                if(nDias >=30){
                    nDias = ((30 - diaInicial) + diaFinal)%30;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 2:
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                if(cont_bis > 0){
                    nDias = (29 - diaInicial) + diaFinal;
                    if(nDias >= 29){
                        nDias = ((29 - diaInicial) + diaFinal)%29;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                else{
                    nDias = (28 - diaInicial) + diaFinal;
                    if(nDias >=28){
                        nDias = ((28 - diaInicial) + diaFinal)%28;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                break;
        }
    }
    else if((diaInicial < diaFinal) && (mesInicial == mesFinal) && (anoInicial == anoFinal)){

        switch(mesInicial){
            case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
                for(i = mesInicial; i < mesFinal; i++){
		    nMeses++;
		}

                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                      cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (31 - diaInicial) + diaFinal;
                if(nDias >= 31){
                    nDias = ((31 - diaInicial) + diaFinal)%31;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                for(i = mesInicial; i < mesFinal; i++){
                    nMeses++;
                }
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (30 - diaInicial) + diaFinal;
                if(nDias >=30){
                    nDias = ((30 - diaInicial) + diaFinal)%30;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 2:
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                if(cont_bis > 0){
                    nDias = (29 - diaInicial) + diaFinal;
                    if(nDias >= 29){
                        nDias = ((29 - diaInicial) + diaFinal)%29;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                else{
                    nDias = (28 - diaInicial) + diaFinal;
                    if(nDias >=28){
                        nDias = ((28 - diaInicial) + diaFinal)%28;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                break;
        }
    }
    else if((diaInicial > diaFinal) && (mesInicial < mesFinal) && (anoInicial < anoFinal)){

        switch(mesInicial){
            case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
                for(i = mesInicial; i < mesFinal; i++){
		    nMeses++;
		}

                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                      cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (31 - diaInicial) + diaFinal;
                if(nDias >= 31){
                    nDias = ((31 - diaInicial) + diaFinal)%31;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                for(i = mesInicial; i < mesFinal; i++){
                    nMeses++;
                }
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (30 - diaInicial) + diaFinal;
                if(nDias >=30){
                    nDias = ((30 - diaInicial) + diaFinal)%30;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 2:
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                if(cont_bis > 0){
                    nDias = (29 - diaInicial) + diaFinal;
                    if(nDias >= 29){
                        nDias = ((29 - diaInicial) + diaFinal)%29;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                else{
                    nDias = (28 - diaInicial) + diaFinal;
                    if(nDias >=28){
                        nDias = ((28 - diaInicial) + diaFinal)%28;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                break;
        }
    }
    else if((diaInicial > diaFinal) && (mesInicial < mesFinal) && (anoInicial == anoFinal)){

        switch(mesInicial){
            case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
                for(i = mesInicial; i < mesFinal; i++){
		    nMeses++;
		}

                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                      cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (31 - diaInicial) + diaFinal;
                if(nDias >= 31){
                    nDias = ((31 - diaInicial) + diaFinal)%31;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                for(i = mesInicial; i < mesFinal; i++){
                    nMeses++;
                }
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (30 - diaInicial) + diaFinal;
                if(nDias >=30){
                    nDias = ((30 - diaInicial) + diaFinal)%30;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 2:
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                if(cont_bis > 0){
                    nDias = (29 - diaInicial) + diaFinal;
                    if(nDias >= 29){
                        nDias = ((29 - diaInicial) + diaFinal)%29;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                else{
                    nDias = (28 - diaInicial) + diaFinal;
                    if(nDias >=28){
                        nDias = ((28 - diaInicial) + diaFinal)%28;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                break;
        }
    }
    else if((diaInicial > diaFinal) && (mesInicial > mesFinal) && (anoInicial < anoFinal)){

        switch(mesInicial){
            case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
                for(i = mesInicial; i < mesFinal; i++){
		    nMeses++;
		}

                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                      cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (31 - diaInicial) + diaFinal;
                if(nDias >= 31){
                    nDias = ((31 - diaInicial) + diaFinal)%31;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                for(i = mesInicial; i < mesFinal; i++){
                    nMeses++;
                }
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                nDias = (30 - diaInicial) + diaFinal;
                if(nDias >=30){
                    nDias = ((30 - diaInicial) + diaFinal)%30;
                }
                else{
                    nDias = nDias;
                    if(nMeses == 1){
                        nMeses = nMeses - 1;
                    }
                    else{
                        nMeses = nMeses;
                    }
                }
                break;
            case 2:
                for(i = anoInicial; i <= anoFinal; i++){
                    if(i%4 == 0 && (i%400 == 0 || i%100 != 0)){
                        cont_bis++;
                    }
                    else{
                        cont_bis = cont_bis;
                    }
                    nAnos++;
                }

                if(cont_bis > 0){
                    nDias = (29 - diaInicial) + diaFinal;
                    if(nDias >= 29){
                        nDias = ((29 - diaInicial) + diaFinal)%29;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                else{
                    nDias = (28 - diaInicial) + diaFinal;
                    if(nDias >=28){
                        nDias = ((28 - diaInicial) + diaFinal)%28;
                    }
                    else{
                        nDias = nDias;
                        if(nMeses == 1){
                            nMeses = nMeses - 1;
                        }
                        else{
                            nMeses = nMeses;
                        }
                    }
                }
                break;
        }
    }

    *qtdDias = nDias;
    *qtdMeses = nMeses;
    *qtdAnos = nAnos - 1;
    return 1;
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    char strMinusculo[250], strMaiusculo[250];
    int qtdOcorrencias=0, i;

    if(isCaseSensitive == 1){

        for(i=0; i<strlen(texto); i++){
            if(c == texto[i]){
                qtdOcorrencias++;
            }
        }
    }
    else{

        for(i=0; i<strlen(texto); i++){
            strMinusculo[i] = texto[i] + 32;
	}
        for(i=0; i<strlen(texto); i++){
	    strMaiusculo[i] = texto[i] - 32;
        }
        for(i=0; i<strlen(texto); i++){
            if(c == strMinusculo[i] || c == strMaiusculo[i] || c == texto[i]){
                qtdOcorrencias++;
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int tamanhoTexto = strlen(strTexto);
    int tamanhoBusca = strlen(strBusca);
    int i = 0, j = 0, x = 0, p = 0;
    int qtdOcorrencias = 0;
    int aux[30];
    for(i = 0; i < tamanhoTexto; i++){

        if(strTexto[i] == strBusca[x]){
            aux[x] = i;
            x++;

            for(j = i+1; j < tamanhoTexto; j++){

                if(strTexto[j] == strBusca[x]){
                    aux[x] = j;
                    x++;
                }
                else{
                    x = 0;
                    break;
                }

                if(x == tamanhoBusca){

                    qtdOcorrencias++;

                    posicoes[p] = aux[0] + 1;
                    p++;
                    posicoes[p] = aux[tamanhoBusca - 1] + 1;
                    p++;
                }
            }
        }
        else{
            x = 0;
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    int inverso=0;
    int mi, cm, dm, m, c, d, u;

    if(num >= 1000000 && num <= 9999999){

        mi = num/1000000;
        cm = ((num%1000000)/100000)*10;
        dm = ((num%100000)/10000)*100;
        m = ((num%10000)/1000)*1000;
        c = ((num%1000)/100)*10000;
        d = ((num%100)/10)*100000;
        u = (num%10)*1000000;

        inverso = mi + cm + dm + m + c + d + u;
    }
    else if(num >= 100000 && num <= 999999){

        cm = num/100000;
        dm = ((num%100000)/10000)*10;
        m = ((num%10000)/1000)*100;
        c = ((num%1000)/100)*1000;
        d = ((num%100)/10)*10000;
        u = (num%10)*100000;

        inverso = cm + dm + m + c + d + u;
    }
    else if(num >= 10000 && num <= 99999){

        dm = num/10000;
        m = ((num%10000)/1000)*10;
        c = ((num%1000)/100)*100;
        d = ((num%100)/10)*1000;
        u = (num%10)*10000;

        inverso = dm + m + c + d + u;
    }
    else if(num >= 1000 && num <= 9999){

        m = num/1000;
        c = ((num%1000)/100)*10;
        d = ((num%100)/10)*100;
        u = (num%10)*1000;

        inverso = m + c + d + u;
    }
    else if(num >= 100 && num <= 999){

        c = num/100;
        d = ((num%100)/10)*10;
        u = (num%10)*100;

        inverso = c + d + u;
    }
    else if(num >= 10 && num <= 99){

        d = num/10;
        u = (num%10)*10;

        inverso = d + u;
    }
    else if(num >= 0 && num <= 9){

        inverso = num;
    }
    return inverso;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias = 0;

    if(numerobase == 0){
        qtdOcorrencias = 0;
    }
    else{
        if(numerobusca > 0 && numerobusca < 10){ // numero com 1 digito
            while(numerobase> 0){
                if(numerobusca == (numerobase%10)){
                    qtdOcorrencias++;
                }
                numerobase = numerobase/10;
            }
        }
        else if(numerobusca > 9 && numerobusca < 100){ // numero com 2 digitos
            while(numerobase> 0){
                if(numerobusca == (numerobase%100)){
                    qtdOcorrencias++;
                }
                numerobase = numerobase/100;
            }
        }
        else if(numerobusca > 99 && numerobusca < 1000){ // numero com 3 digitos
            while(numerobase> 0){
                if(numerobusca == (numerobase%1000)){
                    qtdOcorrencias++;
                }
                numerobase = numerobase/1000;
            }
        }
        else if(numerobusca > 999 && numerobusca < 10000){ //numero com 4 digitos
            while(numerobase> 0){
                if(numerobusca == (numerobase%10000)){
                    qtdOcorrencias++;
                }
                numerobase = numerobase/10000;
            }
        }
        else if(numerobusca > 9999 && numerobusca < 100000){ //numero com 5 digitos
            while(numerobase> 0){
                if(numerobusca == (numerobase%10000)){
                    qtdOcorrencias++;
                }
                numerobase = numerobase/10000;
            }
        }
    }
    return qtdOcorrencias;
}
