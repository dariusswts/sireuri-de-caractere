#ifndef pbinfo_BAC.h
#define pbinfo_BAC.h
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/*
Sesiunea iunie – 13 iunie 2025
Un cuvânt semioglindit se obţine dintr-un cuvânt cu 2·k (k∈[1,102]) litere, prin interschimbarea în
acesta a secvenței formate din primele k litere cu secvența formată din ultimele k litere.
Exemplu: din cuvântul platim se obţine cuvântul semioglindit timpla.
Într-un text de cel mult 200 de caractere, cuvintele sunt formate din litere mici ale alfabetului englez și sunt
separate prin câte un spaţiu. Scrieţi un program C/C++ care citeşte de la tastatură un text de tipul precizat,
pe care îl transformă în memorie, prin înlocuirea fiecărui cuvânt cu număr par de litere, cu cel semioglindit
obținut din acesta, ca în exemplu. Programul afișează pe ecran textul obținut, sau mesajul nu exista,
dacă toate cuvintele au număr impar de litere.
Exemplu: pentru textul am facut fotografii unei flori mari
se afişează pe ecran textul ma facut rafiifotog eiun flori rima

*/

bool estePar(int lungime){
    return lungime%2==0;
}


void CuvantSemioglindit(char cuv[], int lungime){
    int k=lungime/2;
    for(int i=0;i<k;i++){
        char aux=cuv[i];
        cuv[i]=cuv[i+k];
        cuv[i+k]=aux;
    }
}


bool transformareSir(char s[]){
    bool verifica=false;
    int n=strlen(s);
    int i=0;
    while(i<n){
        int start=i;
        while(i<n&&s[i]!=' '){
            i++;
        }
        int lungime=i-start;
        if(estePar(lungime)&&lungime>0){
                verifica=true;
                CuvantSemioglindit(s+start,lungime);
        }
        i++;
    }
    return verifica;

}

void bac1(){
    char s[200]="am facut fotografii unei flori mari";
    cout<<"Sirul initial: "<<s<<endl;
    if(transformareSir(s)){
        cout<<s;
    }else{
        cout<<"Nu exista ";
    }
}

///Sesiunea specială – 26 mai 2025
/*
Într-un text de cel mult 100 de caractere cuvintele sunt formate doar din litere mici ale alfabetului englez și
sunt separate prin unul sau mai multe spații. Textul are cel puțin două cuvinte.
Scrieți un program C/C++ care citește de la tastatură un text de tipul precizat mai sus și îl transformă în
memorie prin eliminarea sau inserarea unor spații și a unor cratime (simbolul -), astfel încât între oricare
două cuvinte consecutive în text să fie câte o cratimă, încadrată la stânga și la dreapta de câte un spațiu,
ca în exemplu. Programul afișează pe ecran textul obținut.
Exemplu: pentru textul
anul acesta devin student
se obține
anul – acesta – devin - student
*/

bool literaMica(char c){
    return (c>='a'&&c<='z');
}
//algoritmul de inserare
void introducereV2(char s[]){
    int n=strlen(s);
    int i=0;
    while(i<n){
        if(s[i]==' '){
            for(int j=n;j>=i+1;j--){
                s[j+1]=s[j];
            }
            s[i+1]='-';
            n++;
            for(int j=n;j>=i+2;j--){
                s[j+1]=s[j];
            }
            s[i+2]=' ';
            n++;
        }
    }
}
////////////////////////////////////////////////////////////
void introducereCratima(char s[]){
    int n=strlen(s);
    int i=0;
    while(i<n){
        if(s[i]==' '){
            for(int j=n;j>=i+1;j--){
                s[j+2]=s[j];
            }
            s[i]=' ';
            s[i+1]='-';
            s[i+2]=' ';
            n=n+2;
            i=i+3;
        }
        else{
            i++;
        }
    }
}
void bac2Var2(){
    char s[200]="anul acesta devin student";
    cout<<"sirul initial: "<<s<<endl;
    introducereV2(s);
    cout<<"sirul final scris: "<<s;
}
///////////////////////////////////////////////////
void bac2(){
    char s[200]="anul acesta devin student";
    cout<<"sirul initial: "<<s<<endl;
    introducereCratima(s);
    cout<<"sirul final scris: "<<s;
}

///Simulare – 26 martie 2025
/*
Două cuvinte se numesc asemenea dacă sunt distincte și au același număr de vocale. Se
consideră vocale literele a, e, i, o, u.
Scrieți un program C/C++ care citește de la tastatură un număr natural n (n[1,102]),
apoi n cuvinte, separate prin Enter. Fiecare cuvânt este format din cel mult 20 de
caractere, numai litere mici ale alfabetului englez. Programul afișează pe ecran, separate
prin câte un spațiu, toate cuvintele asemenea cu ultimul cuvânt citit, sau mesajul
nu exista dacă nu există astfel de cuvinte.
Exemplu: dacă se citesc datele alăturate, se afișează pe ecran, nu neapărat în această
ordine, cuvintele:
lalelele brandusele
*/


int nrVocale(char cuv[]){
    int cnt=0;
    for(int i=0;cuv[i]!='\0';i++){
        char c=cuv[i];
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            cnt++;
        }
    }
    return cnt;
}

bool esteAsemenea(char cuv1[],char cuv2[]){
    if(strcmp(cuv1,cuv2)==0){
        return false;
    }
    return nrVocale(cuv1)==nrVocale(cuv2);
}

void comparareCuvinte(){

}





#endif // pbinfo_BAC.h
