/*
# Tarefa aula 1: 
-----
Crie um TAD para o tipo data com a seguinte estrutura: dia, mês e ano.

Desenvolva as seguintes operações:

Receber uma data do usuário
Exibir uma data nos formatos:
DD/MM/YYYY
DD de [mês-por-extenso] de YYYY
YYYY-MM-DD
Checar se uma data é válida
Calcular o intervalo de dias entre 2 datas válidas
------
Estratégias:
- Validar o mês usando if <= 12 
- Validar o dia usando if <= 31 (Para manter mais simples, ignorando que alguns meses tem menos de 31 dias)
- Criar um switch case para cada mês com o nome escrito por extenso
- Transformar as datas em dias (assumindo ano = 365 dias e mês = 30 dias) para calcular o intervalo entre elas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int year;
    int month;
    int day;
} date;

long int dateToDays(date *pDate);
date *daysToDate(long int days);

date *readDate();
void showDate(date *pDate);
void checkValidDate(date *pDate);
char* monthInChar(date *pDate);
long int intervalBetweenDates(date *pDate1, date *pDate2);

int main() {
    date *pDate1, *pDate2;
    
    printf("Date 1: ");
    pDate1 = readDate();

    printf("----------------------\n");

    printf("Date 2: ");
    pDate2 = readDate();

    checkValidDate(pDate1);
    checkValidDate(pDate2);

    printf("----------------------\n");

    printf("Date 1: \n");
    showDate(pDate1);

    printf("----------------------\n");

    printf("Date 2: \n");
    showDate(pDate2);

    printf("----------------------\n");

    printf("The interval between Date 1 and Date 2 is: %ld days\n", intervalBetweenDates(pDate1, pDate2));

    return 0;
}

long int dateToDays(date *pDate)
{
    return pDate->year * 365 + pDate->month * 30 + pDate->day;
}

date *daysToDate(long int days)
{
    date *pDate = (date *)malloc(sizeof(date));

    pDate->year = days / 365;
    days = days % 365;
    pDate->month = days / 30;
    pDate->day = days % 30;
    return pDate;
}

date *readDate()
{
    date *pDate = daysToDate(0);
    printf("Year: ");
    scanf("%d", &pDate->year);
    printf("Month: ");
    scanf("%d", &pDate->month);
    printf("Day: ");
    scanf("%d", &pDate->day);

    return pDate;
}

void showDate(date *pDate)
{
    //DD/MM/YYYY
    printf("%d/%d/%d\n", pDate->day, pDate->month, pDate->year);

    //Month, day, year
    printf("%s %d, %d\n", monthInChar(pDate), pDate->day, pDate->year);
    //YYYY-MM-DD
    printf("%d/%d/%d\n", pDate->year, pDate->month, pDate->day);
}

void checkValidDate(date *pDate)
{
    if (pDate->year < 0)
    {
        printf("Invalid date\n");
        exit(EXIT_SUCCESS);
    }
    else if (pDate->month > 12 || pDate->month < 1)
    {
        printf("Invalid date\n");
        exit(EXIT_SUCCESS);
    }
    else if (pDate->day > 31 || pDate->day < 0)
    {
        printf("Invalid date\n");
        exit(EXIT_SUCCESS);
    }
}

 char* monthInChar(date *pDate)
{
    switch (pDate->month)
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;

    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;

    default:
        break;
    }
}

long int intervalBetweenDates(date *pDate1, date *pDate2)
{
    long int dateToDay1, dateToDay2;
    dateToDay1 = dateToDays(pDate1);
    dateToDay2 = dateToDays(pDate2);
    if (dateToDay1 > dateToDay2)
    {
        return dateToDay1 - dateToDay2;
    }
    else
    {
        return dateToDay2 - dateToDay1;
    }
}