#include <iostream>
#include <stdlib.h>

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


int main()
{
    int nrZadania;

    cout<<"Algorytmy numeryczne\n\nNumer zadania: 1 | 2 | 3 | 4"<<endl;
    cin>>nrZadania;

    switch(nrZadania){
        case 1:
            zadanie1();
            break;
        default:
            cout<<"Podaj numer zadania 1-4"<<endl;
            break;
    }
    return 0;
}
