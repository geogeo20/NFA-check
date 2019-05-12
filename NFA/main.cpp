#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

typedef struct tranzitie
{
    int counter=0;
    char a[30];
} trans;
trans afn[100][100];  // matricea de tranzitii

int fin[100]; // vector de stari finale
int q,s,t1,t2; // q - nr stari, s -  nr stari finale
int qini = 0; // qini - stare initiala
bool ok = false;

int isfin(int stare)
{
    for(int i=0;i<s;i++) // verificare daca starea este stare finala
        if(fin[i]==stare)
            return 1;
    return 0;
}

bool verificare(string s, int stare, int q)
{
    int x,y;
    if(s.length()==0 && isfin(stare)==1 )
    {
        ok = true; // daca cuvantul nu mai are litere si se afla in stare finala este acceptat
        return true; // se opreste cand cuvantul este null
    }
    else if(s.length()==0)
        return false;
    for(int i=0;i<q;i++)                        //verifica fiecare tranzitie de la o stare primita la restul
    {
        cout<<s<<" "<<stare<<" "<<i<<"\n";
        for(int j=0;j<afn[stare][i].counter;j++)   //daca exista tranzitie, taie o litera din cuvant si intra in urmatoare stare
        if(afn[stare][i].a[j] == s[0])             //fiind o functie recursiva, va intra prin toate tranziitiile posibile
        {

            verificare(s.substr(1), i,q);
        }
    }
    return false;

}

int main()
{
    ifstream f("date.in");
    f>>q>>s;
    for(int i=0;i<s;i++)
    {
        f>>fin[i]; //citest starile finale
    }
    while(!f.eof())
    {
        f>>t1>>t2;
        f>>afn[t1][t2].a[afn[t1][t2].counter++]; //citest tranzitiile
    }
    string cuv;
    cout<<"Introduceti cuvantul pentru verificare:  ";
    cin>>cuv;
    bool start = verificare(cuv,qini,q); // am folosit bool vezi mai sus
    if(ok)
        cout<<"Cuvant acceptat\n";
    else
        cout<<"Cuvant invalid\n";
    return  0;
}
