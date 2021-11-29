#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//Program napisany w ramach portfolio dla firmy GlobalLogic
//autor: Mateusz Famulski
//Gra w kółko i krzyżyk

int wygrana=0, runda=0;
void rozgrywka();
char plansza[11][23]=
{
    {"       |       |       "},
    {"       |       |       "},
    {"      1|      2|      3"},
    {"-------+-------+-------"},
    {"       |       |       "},
    {"       |       |       "},
    {"      4|      5|      6"},
    {"-------+-------+-------"},
    {"       |       |       "},
    {"       |       |       "},
    {"      7|      8|      9"}

};
void wyswietlanie()
{
    int i,j;
    for(i=0;i<=10;i++)
    {
        for(j=0;j<=22;j++)
        {
            printf("%c",plansza[i][j]);
        }
        printf("\n");
    }
}

void pierwszy_ruch()
{
    int i=1 , j=3, ruch=0;
    while(i<=9)
    {
        while(j<=19)
        {
            plansza[i][j]=' ';
            j=j+8;
        }
        i=i+4;
        j=3;
    }

    srand(time(NULL));
    ruch=rand()%4;
    if(ruch==0) plansza[1][3]='O';
    if(ruch==1) plansza[1][19]='O';
    if(ruch==2) plansza[9][3]='O';
    if(ruch==3) plansza[9][19]='O';
    printf("Oto moj ruch\n");
    wyswietlanie();
}

void wygrana_przegrana()
{
    wygrana=1;
        //pierwszy rzad
    if(plansza[1][3]!=' ' && plansza[1][3]==plansza[1][11] && plansza[1][3]==plansza[1][19]) printf("Wygrywa %c\n",plansza[1][3]);
        //drugi rzad
    else if(plansza[5][3]!=' ' && plansza[5][3]==plansza[5][11] && plansza[5][3]==plansza[5][19]) printf("Wygrywa %c\n",plansza[5][3]);
        //trzeci rzad
    else if(plansza[9][3]!=' ' && plansza[9][3]==plansza[9][11] && plansza[9][3]==plansza[9][19]) printf("Wygrywa %c\n",plansza[9][3]);
        //pierwsza kolumna
    else if(plansza[1][3]!=' ' && plansza[1][3]==plansza[5][3] && plansza[1][3]==plansza[9][3]) printf("Wygrywa %c\n",plansza[1][3]);
        //druga kolumna
    else if(plansza[1][11]!=' ' && plansza[1][11]==plansza[5][11] && plansza[1][11]==plansza[9][11]) printf("Wygrywa %c\n",plansza[1][11]);
        //trzecia kolumna
    else if(plansza[1][19]!=' ' && plansza[1][19]==plansza[5][19] && plansza[1][19]==plansza[9][19]) printf("Wygrywa %c\n",plansza[1][19]);
        //pierwszy skos
    else if(plansza[1][3]!=' ' && plansza[1][3]==plansza[5][11] && plansza[1][3]==plansza[9][19]) printf("Wygrywa %c\n",plansza[1][3]);
            //drugi skos
    else if(plansza[1][19]!=' ' && plansza[1][19]==plansza[5][11] && plansza[1][19]==plansza[9][3]) printf("Wygrywa %c\n",plansza[1][19]);
    else wygrana=0;

    if (wygrana==1)
    {
        printf("Nacisnij dowolny klawisz aby zagrac jeszcze raz\n");
        while(!getch());
        wygrana=0;
        rozgrywka();
    }
}

void ruch_gracz()
{
    int pole=0;
    printf("Na ktorym polu chcesz postawic X?\n");
    scanf("%d",&pole);
    if(pole<1 || pole>9)
    {
        printf("Brak takiego pola na planszy - wybierz wlasciwe\n");
        ruch_gracz();
    }
    else if(pole==1 && plansza[1][3]==' ') plansza[1][3]='X';
    else if(pole==2 && plansza[1][11]==' ') plansza[1][11]='X';
    else if(pole==3 && plansza[1][19]==' ') plansza[1][19]='X';
    else if(pole==4 && plansza[5][3]==' ') plansza[5][3]='X';
    else if(pole==5 && plansza[5][11]==' ') plansza[5][11]='X';
    else if(pole==6 && plansza[5][19]==' ') plansza[5][19]='X';
    else if(pole==7 && plansza[9][3]==' ') plansza[9][3]='X';
    else if(pole==8 && plansza[9][11]==' ') plansza[9][11]='X';
    else if(pole==9 && plansza[9][19]==' ') plansza[9][19]='X';
    else
    {
        printf("Pole zajete - sprobuj jeszcze raz\n");
        ruch_gracz();
    }
    if(pole>0 && pole<10)
    {
        printf("Twoj ruch\n");
        wyswietlanie();
        wygrana_przegrana();
    }

}

void strategia()
{
    if(runda==0 && (plansza[1][11]=='X' || plansza[5][3]=='X' || plansza[5][19]=='X' || plansza[9][11]=='X'))
    {
        plansza[5][11]='O';
        runda++;
    }
    else if(runda==1)
    {
        if(plansza[1][11]==' ' && plansza[5][3]==' ') plansza[1][3]='O';
        else if(plansza[1][11]==' ' && plansza[5][19]==' ') plansza[1][19]='O';
        else if(plansza[9][11]==' ' && plansza[5][3]==' ') plansza[9][3]='O';
        else if(plansza[9][11]==' ' && plansza[5][19]==' ') plansza[9][19]='O';
    }

    else if(runda==0 && (plansza[1][3]=='X' || plansza[9][3]=='X' || plansza[1][19]=='X' || plansza[9][19]=='X'))
    {
        if(plansza[1][3]=='O' || plansza[9][19]=='O')
           {
                if(plansza[9][3]==' ') plansza[9][3]='O';
                else plansza[1][19]='O';
           }
        else if (plansza[9][3]=='O' || plansza[1][19]=='O')
        {
                if(plansza[1][3]==' ') plansza[1][3]='O';
                else plansza[9][19]='O';
        }
        runda++;
    }
    else if(runda==1)
    {
        if(plansza[1][3]==' ') plansza[1][3]='O';
        else if(plansza[9][3]==' ') plansza[9][3]='O';
        else if(plansza[1][19]==' ') plansza[1][19]='O';
        else if(plansza[9][19]==' ') plansza[9][19]='O';
    }

    else if(runda==0 && plansza[5][11]=='X')
    {
        if(plansza[1][3]=='O') plansza[9][19]='O';
        else if(plansza[9][3]=='O') plansza[1][19]='O';
        else if(plansza[1][19]=='O') plansza[9][3]='O';
        else if(plansza[9][19]=='O') plansza[1][3]='O';
    }
}

void ruch_komuter()
{
    //sprawdzamy czy możemy wygrać, jeśli nie to sprawdzamy czy możemy zablokować wygraną przeciwnika
        //sprawdzenie pierwszego rzêdu
    if(plansza[1][3]=='O' && plansza[1][11]=='O' && plansza[1][19]==' ') plansza[1][19]='O';
    else if(plansza[1][3]=='O' && plansza[1][19]=='O' && plansza[1][11]==' ') plansza[1][11]='O';
    else if(plansza[1][11]=='O' && plansza[1][19]=='O' && plansza[1][3]==' ') plansza[1][3]='O';
        //sprawdzenie drugiego rzêdu
    else if(plansza[5][3]=='O' && plansza[5][11]=='O' && plansza[5][19]==' ') plansza[5][19]='O';
    else if(plansza[5][3]=='O' && plansza[5][19]=='O' && plansza[5][11]==' ') plansza[5][11]='O';
    else if(plansza[5][11]=='O' && plansza[5][19]=='O' && plansza[5][3]==' ') plansza[5][3]='O';
        //sprawdzenie trzeciego rzêdu
    else if(plansza[9][3]=='O' && plansza[9][11]=='O' && plansza[9][19]==' ') plansza[9][19]='O';
    else if(plansza[9][3]=='O' && plansza[9][19]=='O' && plansza[9][11]==' ') plansza[9][11]='O';
    else if(plansza[9][11]=='O' && plansza[9][19]=='O' && plansza[9][3]==' ') plansza[9][3]='O';
        //sprawdzenie pierwszej kolumny
    else if(plansza[1][3]=='O' && plansza[5][3]=='O' && plansza[9][3]==' ') plansza[9][3]='O';
    else if(plansza[1][3]=='O' && plansza[9][3]=='O' && plansza[5][3]==' ') plansza[5][3]='O';
    else if(plansza[5][3]=='O' && plansza[9][3]=='O' && plansza[1][3]==' ') plansza[1][3]='O';
        //sprawdzenie drugiej kolumny
    else if(plansza[1][11]=='O' && plansza[5][11]=='O' && plansza[9][11]==' ') plansza[9][11]='O';
    else if(plansza[1][11]=='O' && plansza[9][11]=='O' && plansza[5][11]==' ') plansza[5][11]='O';
    else if(plansza[5][11]=='O' && plansza[9][11]=='O' && plansza[1][11]==' ') plansza[1][11]='O';
        //sprawdzenie trzeciej kolumny
    else if(plansza[1][19]=='O' && plansza[5][19]=='O' && plansza[9][19]==' ') plansza[9][19]='O';
    else if(plansza[1][19]=='O' && plansza[9][19]=='O' && plansza[5][19]==' ') plansza[5][19]='O';
    else if(plansza[5][19]=='O' && plansza[9][19]=='O' && plansza[1][19]==' ') plansza[1][19]='O';
        //sprawdzenie pierwszego skosku
    else if(plansza[1][3]=='O' && plansza[5][11]=='O' && plansza[9][19]==' ') plansza[9][19]='O';
    else if(plansza[1][3]=='O' && plansza[9][19]=='O' && plansza[5][11]==' ') plansza[5][11]='O';
    else if(plansza[5][11]=='O' && plansza[9][19]=='O' && plansza[1][3]==' ') plansza[1][3]='O';
        //sprawdzenie drugiego skosku
    else if(plansza[1][19]=='O' && plansza[5][11]=='O' && plansza[9][3]==' ') plansza[9][3]='O';
    else if(plansza[1][19]=='O' && plansza[9][3]=='O' && plansza[5][11]==' ') plansza[5][11]='O';
    else if(plansza[9][3]=='O' && plansza[5][11]=='O' && plansza[1][19]==' ') plansza[1][19]='O';

        //sprawdzanie pierwszego rzędu
    else if(plansza[1][3]=='X' && plansza[1][11]=='X' && plansza[1][19]==' ') plansza[1][19]='O';
    else if(plansza[1][3]=='X' && plansza[1][19]=='X' && plansza[1][11]==' ') plansza[1][11]='O';
    else if(plansza[1][11]=='X' && plansza[1][19]=='X' && plansza[1][3]==' ') plansza[1][3]='O';
        //sprawdzenie drugiego rzêdu
    else if(plansza[5][3]=='X' && plansza[5][11]=='X' && plansza[5][19]==' ') plansza[5][19]='O';
    else if(plansza[5][3]=='X' && plansza[5][19]=='X' && plansza[5][11]==' ') plansza[5][11]='O';
    else if(plansza[5][11]=='X' && plansza[5][19]=='X' && plansza[5][3]==' ') plansza[5][3]='O';
        //sprawdzenie trzeciego rzêdu
    else if(plansza[9][3]=='X' && plansza[9][11]=='X' && plansza[9][19]==' ') plansza[9][19]='O';
    else if(plansza[9][3]=='X' && plansza[9][19]=='X' && plansza[9][11]==' ') plansza[9][11]='O';
    else if(plansza[9][11]=='X' && plansza[9][19]=='X' && plansza[9][3]==' ') plansza[9][3]='O';
        //sprawdzenie pierwszej kolumny
    else if(plansza[1][3]=='X' && plansza[5][3]=='X' && plansza[9][3]==' ') plansza[9][3]='O';
    else if(plansza[1][3]=='X' && plansza[9][3]=='X' && plansza[5][3]==' ') plansza[5][3]='O';
    else if(plansza[5][3]=='X' && plansza[9][3]=='X' && plansza[1][3]==' ') plansza[1][3]='O';
        //sprawdzenie drugiej kolumny
    else if(plansza[1][11]=='X' && plansza[5][11]=='X' && plansza[9][11]==' ') plansza[9][11]='O';
    else if(plansza[1][11]=='X' && plansza[9][11]=='X' && plansza[5][11]==' ') plansza[5][11]='O';
    else if(plansza[5][11]=='X' && plansza[9][11]=='X' && plansza[1][11]==' ') plansza[1][11]='O';
        //sprawdzenie trzeciej kolumny
    else if(plansza[1][19]=='X' && plansza[5][19]=='X' && plansza[9][19]==' ') plansza[9][19]='O';
    else if(plansza[1][19]=='X' && plansza[9][19]=='X' && plansza[5][19]==' ') plansza[5][19]='O';
    else if(plansza[5][19]=='X' && plansza[9][19]=='X' && plansza[1][19]==' ') plansza[1][19]='O';
        //sprawdzenie pierwszego skosku
    else if(plansza[1][3]=='X' && plansza[5][11]=='X' && plansza[9][19]==' ') plansza[9][19]='O';
    else if(plansza[1][3]=='X' && plansza[9][19]=='X' && plansza[5][11]==' ') plansza[5][11]='O';
    else if(plansza[5][11]=='X' && plansza[9][19]=='X' && plansza[1][3]==' ') plansza[1][3]='O';
            //sprawdzenie drugiego skosku
    else if(plansza[1][19]=='X' && plansza[5][11]=='X' && plansza[9][3]==' ') plansza[9][3]='O';
    else if(plansza[1][19]=='X' && plansza[9][3]=='X' && plansza[5][11]==' ') plansza[5][11]='O';
    else if(plansza[9][3]=='X' && plansza[5][11]=='X' && plansza[1][19]==' ') plansza[1][19]='O';

    else strategia();

    printf("Oto moj ruch\n");
    wyswietlanie();
    wygrana_przegrana();


}


void rozgrywka()
{
    int i=0;
    runda=0;
    pierwszy_ruch();
    while(wygrana==0)
    {
        ruch_gracz();
        ruch_komuter();
        i++;
        if(i==4)
        {
            printf("REMIS\n");
            printf("Nacisnij dowolny klawisz aby zagrac jeszcze raz\n");
            while(!getch());
            rozgrywka();
        }
    }
}

int main()
{

    printf("Program napisany dla GlobalLogic\n\n");
    printf("\tMateusz Famulski\n\n");
    printf("  K-O-L-K-O   I   K-R-Z-Y-Z-Y-K\n\n");
    printf("   O-Komouter          X-Gracz\n\n");
    printf("Aby rozpoczac kliknij dowolny klawisz\n\n");
    while(!getch());
    rozgrywka();



    return 0;
}
