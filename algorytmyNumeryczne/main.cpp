#include <iostream>
#include <stdlib.h>
#include <fstream>
#include<iomanip>

using namespace std;

void zadanie1(){

    int Nominaly[8] = {200, 100, 50, 20, 10, 5, 2, 1};

    int Reszta, Pom, i = 0;

    cout<<"Podaj wartosc do przeliczenia: ";
    cin>>Reszta;

    while(Reszta>0){
        if(Reszta >= Nominaly[i])
        {
            Pom = Reszta / Nominaly[i];
            Reszta = Reszta - (Nominaly[i]*Pom);
            cout<<Nominaly[i]<<" x "<<Pom<<endl;
        }
        i++;
    }
    system("PAUSE");
}

void findMinMax(int liczba[]){

    int doKiedy, tabilce;

    if(7%2==0){
        doKiedy = 5;
        tabilce = (int)(doKiedy/2);
    }
    else{
        doKiedy = 6;
        tabilce = doKiedy/2;
    }

    int *tabMin = new int[tabilce];
    int *tabMax = new int[tabilce];

    if(liczba[0]>liczba[1]){
        tabMin[0] = liczba[1];
        tabMax[0] = liczba[0];
    }else{
        tabMin[0] = liczba[0];
        tabMax[0] = liczba[1];
    }


    for(int i=2, j = 1; i <doKiedy; i+=2, j++){
        int doPorownania = liczba[i+1];
        if(liczba[i] < doPorownania){
            tabMin[j] = liczba[i];
            tabMax[j] = doPorownania;
        }else{
            tabMin[j] = doPorownania;
            tabMax[j] = liczba[i];
        }
    }

    int minimum = liczba[6], maximum = liczba[6];

    for(int k = 0; k < tabilce; k++){
        if(tabMin[k] < minimum)
            minimum = tabMin[k];
    }

    cout<<"Minimum: "<<minimum<<"\n";

    for(int k = 0; k < tabilce; k++){
        if(tabMax[k] > maximum)
            maximum = tabMax[k];
    }

    cout<<"Maksimum: "<<maximum<<"\n";
    system("PAUSE");
}

void zadanie2(){
    int liczba[7];
    ifstream plik;
    plik.open("plik.txt");
    int i=0;

    while(true){
        if(plik.good()){
            plik >> liczba[i];
            i++;
        }
        else{
            break;
        }
    }
    /*
    cout<<"Liczby to: ";
    for(int i = 0; i <7; i++)
        cout<<liczba[i]<<", ";
    */

    findMinMax(liczba);
}


double wykonaj(double k){
    return k*(k*(k-3)+2)-6; //horner
}

double polowienie(double a, double b, double eps){
    if(wykonaj(a)==0.0)
        return a;
    if(wykonaj(b)==0.0)
        return b;

    double srodek;

    while(b-a > eps){
        srodek  = (a+b)/2;

        if(wykonaj(srodek)==0.0)//if m.0 jest w srodku
            return srodek;

        if(wykonaj(a)*wykonaj(srodek)<0)
            b = srodek;
        else
            a=srodek;
    }
    return (a+b)/2;

}

void zadanie3(){
    double a = -10, b = 10, eps = 0.00001;
    cout<<"\nMiejsce zerowe to: "<<fixed<<setprecision(5)<<polowienie(a,b,eps)<<endl;
}

double wykonaj1(double x){
    return x*x+x+2;
}

double pole1(int a, int b, int k){
    double h = (b-a)/(double)k;
    double suma = 0.0;
    double podstawaA = wykonaj1(a), podstawaB;

    for(int i=1; i<=k;i++)
    {
        podstawaB = wykonaj1(a+h*i);
        suma+= (podstawaA+podstawaB);
        podstawaA = podstawaB;
    }
    return suma*0.5*h;
}

void zadanie4(){

    int a, b, k;
    cout<<"Podaj przedzial od: ";
    cin>>a;

    cout<<"Podaj przedzial do: ";
    cin>>b;

    cout<<"Podaj liczbe trapezow: ";
    cin>>k;

    if(!(a<b))
        cout<<"a nie moze byc mniejsze od b"<<endl;
    else
        cout<<"Pole figury to: "<<fixed<<setprecision(1)<<pole1(a, b, k);
}

int main()
{
    int nrZadania;

    cout<<"Algorytmy numeryczne\n\nNumer zadania: 1 | 2 | 3 | 4 | >> ";
    cin>>nrZadania;

    switch(nrZadania){
        case 1:
            zadanie1();
            break;
        case 2:
            zadanie2();
            break;
        case 3:
            zadanie3();
            break;
        case 4:
            zadanie4();
            break;
        default:
            cout<<"Podaj numer zadania 1-4"<<endl;
            break;
    }
    return 0;
}
