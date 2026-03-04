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


/*
Fiind date două șiruri de caractere a şi b, îl numim pe a sufix al lui b dacă a este egal cu b sau
dacă b se poate obţine din a prin alipirea la stânga a unor noi caractere.
Variabilele a şi b pot memora câte un șir cu cel mult 20 de caractere. Scrieţi o secvenţă de
instrucţiuni în urma executării căreia variabila a să memoreze un sufix al lui b format din trei
caractere, sau șirul nedeterminat, dacă nu există un astfel de sufix.
Exemplu: dacă b memorează şirul centaur, atunci a memorează şirul aur, iar dacă b memorează
şirul au, atunci a memorează şirul nedeterminat.

*/

void sufix3Litere(char a[],char b[]){
    int n=strlen(b);
    if(n<3){
        strcpy(a,"nedeterminat");
    }
    else{
        a[0]=b[n-3];
        a[1]=b[n-2];
        a[2]=b[n-1];
    }
}

void bac2019(){
    char a[100];
    char b[100];
    cin>>b;
    sufix3Litere(a,b);
    cout<<"Sufixul lui b transmis in a :";
    cout<<a;
}
///Simulare bacalaureat, martie 2019
/*
Într-un text de cel mult 50 de caractere cuvintele sunt separate prin câte un spațiu și sunt formate din
litere mari ale alfabetului englez, urmate eventual de caracterul . (punct), dacă sunt scrise prescurtat.
Textul reprezintă numele unei instituții de învățământ și doar cuvintele din mulțimea
{COLEGIUL, LICEUL, NATIONAL, TEORETIC} pot fi prescurtate, eliminându-se ultimele lor litere.
Scrieţi un program C/C++ care citeşte de la tastatură un text de tipul precizat și construiește în
memorie, apoi afișează pe ecran, numele instituției scris fără prescurtări.
Exemplu: dacă se citește textul COLEG. NATIONAL DE INFORMATICA sau textul
COLEG. NAT. DE INFORMATICA se obține COLEGIUL NATIONAL DE INFORMATICA

*/

void estePrescurtat(char cuv[100]){
    if(strcmp(cuv,"COLEG")==0){
        strcpy(cuv,"COLEGIUL");
    }
    if(strcmp(cuv,"LICE")==0){
        strcpy(cuv,"LICEUL");
    }
    if(strcmp(cuv,"NAT")==0){
        strcpy(cuv,"NATIONAL");
    }
}
void bac2019ultimul(){

    char sir[100]="COLEG. NAT. DE INFORMATICA";
    char cuvinte[100][100];
    int n=0;
    char*p=strtok(sir," .");
    while(p!=NULL){
        strcpy(cuvinte[n],p);
        n++;
        p=strtok(NULL," .");
    }
    for(int i=0;i<n;i++){
        estePrescurtat(cuvinte[i]);
        cout<<cuvinte[i];
        cout<<" ";
    }


}

///2018, 28 iunie
/*
Fiind dat un cuvânt s, format numai din litere, și un cod c, de aceeași lungime cu s, format
numai din cifre, numim codificare a lui s pe baza codului c operația de construire a unui
nou șir, în care inițial se copiază prima literă din s, apoi, parcurgând de la stânga la dreapta
restul șirului s, se adaugă litera curentă la începutul noului șir, dacă cifra corespunzătoare
de pe aceeași poziție în c este pară, sau la finalul noului șir, în caz contrar.
Exemplu: dacă șirul s este etalon, iar codul este 025843 se obține cuvântul oltean
(inițial șirul conține litera e, apoi se adaugă, în ordinea parcurgerii lui s, literele t, l și o la
început, iar restul literelor la final).
Scrieţi un program C/C++ care citeşte de la tastatură două cuvinte, notate cu s și c, fiecare
având cel mult 102
 caractere, s fiind format doar din litere mici ale alfabetului englez, iar c
fiind format doar din cifre. După primul cuvânt se tastează Enter. Programul construiește în
memorie și afișează pe ecran cuvântul obținut prin codificarea lui s pe baza lui c, dacă cele
două cuvinte au aceeași lungime, sau mesajul cod incorect, în caz contrar.
Exemplu: dacă se citesc cuvintele alăturate, se afişează pe ecran cuvântul
oltean
*/

void codifiaca(char s[],char c[],char rezultat[]){
    for(int i=1;i<n;i++){
        char lit=s[i];
        char cif=c[i];
        if(cif%2==0){
            char aux[200];
            strcpy(aux,rezultat);
            rezultat[0]=lit;
            strcpy(rezutlat+1,aux);
        }
        else{
            int lungime=strlen(rezultat);
            rezultat[lungime]=lit;
            rezultat[]
        }
    }
}
















#endif // pbinfo_BAC.h
