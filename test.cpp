#include <iostream>
using namespace std;

int dodaj(int a,int b)
{
    return a+b;
}

int main()
{
    int menu;
    int a,b;
    int wynik;

    cout<<"1) Dodawanie"<<endl;
    cout<<"2) Odejmowanie"<<endl;
    cout<<"3) Mnozenie"<<endl;
    cout<<"4) Dzielenie"<<endl;
    cout<<"5) Pierwiastek"<<endl;
    cout<<"6) Potega"<<endl;
    cin>>menu;
    cout<<"Podaj 1 liczbe: ";
    cin>>a;
    cout<<"Podaj 2 liczbe: ";
    cin>>b;

    switch(menu)
    {
    case 1:
        wynik=dodaj(a,b);
        break;
    }

    cout<<wynik;

    getchar();
    return 0;
}
