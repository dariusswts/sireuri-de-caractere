#ifndef TEMA_H_INCLUDED
#define TEMA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


///ex3

//a)
void sterge(char x[],int poz){

    for(int i=poz;i<strlen(x)-1;i++){
        x[i]=x[i+1];
    }
    x[strlen(x)-1]='\n';
}
void eliminaSpatiiMulti(char text[100]){
    for(int i=0;i<strlen(text)-1;i++){
        if(text[i]==' '&&text[i+1]==' '){
            sterge(text,i);
            i--;
        }
    }


}

void rezolvare3A(){
    char p[100]="Azi            a              fost     o     zi     frumoasa";
    cout<<p<<endl;
    eliminaSpatiiMulti(p);
    cout<<"Dupa stergerrea spatilor multiple:"<<endl;
    cout<<p;
}

//b)

char literaMare(char x){
    if(x>='a'&&x<='z'){
        x=x-32;
    }
    return x;
}

char urmatoareaDupaAlfabet(char x){
    if(x=='z'){
        return 'a';
    }
    if(x=='Z'){
        return 'A';
    }
    if((x>='a'&&x<='z')||(x>='A'&&x<='Z')){
        return x+1;
    }
    return x;
}

void rezolvare3B(){
    char p[100]="Ana are mere";
    cout<<p<<endl;
    for(int i=0;i<strlen(p);i++){
        if(p[i-1]==' '&&p[i]!=' '){
            p[i]=literaMare(p[i]);
        }
        if(p[i]!=' '&&p[i+1]==' '){
            p[i]=urmatoareaDupaAlfabet(p[i]);
        }
    }
    p[strlen(p)-1]=urmatoareaDupaAlfabet(p[strlen(p)-1]);
    cout<<"Sirul la final este :"<<p<<endl;
}


//e)

void inserareCar(char p[],int poz,int car){
    for(int i=strlen(p)-1;i>=poz;i--){
       p[i+1]=p[i];
    }
    p[poz]=car;

}
void rezolvare3E(){
    char p[100]="Costel da de mancare la catel";
    cout<<p<<endl;
    char C='c';
    char D='d';
    for(int i=0;i<strlen(p);i++){
        if(p[0]=='C'){
        sterge(p,i);
        }
        if(p[i]==C){
            sterge(p,i);
            i--;
        }
        else if(p[i]==D){
            inserareCar(p,i,p[i]);
            i++;
        }
    }
    cout<<"Rezultatul : "<<p<<endl;
}



///ex 2


//b)




//c)
bool maiMic4(char p[]){
    return strlen(p)>=4;
}

void afiseazaMin4(char p[]){
    char cuv[50];
    for(int i=0;i<=strlen(p);i++){
        if(maiMic4(cuv)){
            cout<<cuv<<" ";
        }
    }
}

void rezolvare2C(){
    char p[200]="Ana da de mancare la catel";
    cout<<p<<endl;
    afiseazaMin4(p);
}



//d)
void alTreilea(char s[]){
    int nr=0;

    for(int i=0;i<strlen(s);i++){
        if(s[i]!=' ' && (i==0 || s[i-1]==' ')){
            nr++;
            if(nr==3){
                for(int j=i;j<strlen(s) && s[j]!=' ';j++)
                    cout<<s[j];
            }
        }
    }
    cout<<"Nu exista 3 cuvinte";
}
void rezolvare2D(){
    char p[200]="Ana da de mancare la catel";
    cout<<p<<endl;
    alTreilea(p);
    cout<<p;
}


//f)
void dubleazaTriplu(char s[]){
    for(int i=0;i<strlen(s)-2;i++){
        if(s[i]!=' ' && s[i]==s[i+1] && s[i]==s[i+2]){
            int n=strlen(s);
            for(int j=n;j>=i+3;j--){
                s[j+3]=s[j];
            }
            s[i+3]=s[i];
            s[i+4]=s[i];
            s[i+5]=s[i];

            i=i+5;
        }
    }
}

void rezolvare2F(){
    char p[200]="Copiii dau mancare la catel";
    cout<<p<<endl;
    dubleazaTriplu(p);
    cout<<p;
}


//g)
void ultimaMare(char s[]){
    for(int i=0;i<strlen(s);i++){
        if(s[i]!=' ' && (i==strlen(s)-1 || s[i+1]==' ')){
            if(s[i]>='a' && s[i]<='z')
                s[i]-=32;
        }
    }
}

void rezolvare2G(){
    char p[200]="Ana da de mancare la catel";
    cout<<p<<endl;
    ultimaMare(p);
    cout<<p;
}


/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
//Se citește un șir. Să se afișeze numărul de vocale
int numaraVocale(char s[]) {
    int cnt=0;
    for(int i=0; s[i]!=0; i++){
       // if(esteVocala(s[i])){
            cnt++;
        }

    return cnt;
}

void rezolvare1(){
    char s[200];
    cin.getline(s,200);
    cout<<numaraVocale(s);
}

//Să se afișeze câte litere mari are șirul.

bool literamare(char c) {
    return c>='A' && c<='Z';
}

int numaraLitereMari(char s[]) {
    int cnt=0;
    for(int i=0; s[i]!=0; i++){
        if(literaMare(s[i])){
                cnt++;
        }
    }
    return cnt;
}

void rezolvare2(){
    char s[200];
    cin.getline(s,200);
    cout<<numaraLitereMari(s);
}

//Cuvintele sunt separate prin spații. Să se afișeze numărul lor.

int numaraCuvinte(char s[]) {
    int cnt=0;
    for(int i=0; s[i]!=0; i++){
        if(s[i]!=' ' && (i==0 || s[i-1]==' ')){
            cnt++;
        }
    }
    return cnt;
}

void rezolvare3(){
    char s[256];
    cin.getline(s,256);
    cout<<numaraCuvinte(s);
}

//Se citește un șir. Eliminați toate vocalele din el și afișați șirul rezultat.

void stergeVocale(char s[]) {
    int k=0;
    for(int i=0; s[i]!=0; i++){
       // if(!esteVocala(s[i])){
            s[k++]=s[i];
        }

    s[k]=0;
}

void rezolvare4(){
    char s[256];
    cin.getline(s,256);
    stergeVocale(s);
    cout<<s;
}


//Se citește un șir și o literă c. Afișați de câte ori apare litera în șir (indiferent de majuscule/minuscule).

char mic(char c){
    if(c>='A' && c<='Z') return c+32;
    return c;
}

int frecventa(char s[], char c) {
    int cnt=0;
    c = mic(c);
    for(int i=0; s[i]!=0; i++){
        if(mic(s[i])==c){
            cnt++;
        }
    }
    return cnt;
}

void rezolvare5(){
    char s[256], c;
    cin.getline(s,256);
    cin>>c;
    cout<<frecventa(s,c);
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////


/*
Într-un text, de cel mult 100 de caractere, cuvintele sunt formate din litere ale alfabetului englez și sunt
separate prin câte un spațiu. Textul are cel puțin două cuvinte.
Scrieți un program C/C++ care citește de la tastatură un text de tipul precizat mai sus și afișează pe ecran
mesajul DA și un număr natural n, separate printr-un spațiu, dacă toate cuvintele din text au câte n litere,
sau mesajul NU în cazul în care nu toate cuvintele au același număr de litere.
Exemplu: dacă textul citit este Ana are cel mai bun mar se afișează pe ecran DA 3
iar dacă textul citit este Ana are cel mai dulce mar se afișează pe ecran NU

*/

int lungimePrim(char s[])
{
    int i=0, lun=0;
    while(s[i]!=' '&& s[i] != '\0')
    {
        lun++;
        i++;
    }
    return lun;
}

int toateEgale(char s[], int lun)
{
    int cuv = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i]!=' '){
            cuv++;
        }
        else{
            if(cuv!= lun) return 0;
            cuv= 0;
        }
    }

    if(cuv!=lun) return 0;
    return 1;
}


void prob1(){
    char s[101]="Ana are cel mai bun mar";
    int lun = lungimePrim(s);
    cout<<s<<endl;
    if(toateEgale(s, lun))
        cout << "DA " << lun;
    else
        cout << "NU";

}
///Simulare – 29 martie 2023

/*
Într-un text de cel mult 100 de caractere cuvintele sunt separate prin câte un spațiu și sunt formate din litere
mari ale alfabetului englez, iar dacă sunt scrise prescurtat sunt urmate de caracterul . (punct). Textul
reprezintă denumirea științifică a unei păsări și doar cuvintele din mulțimea {FAMILIA, GENUL, SPECIA},
specifice sistemului de clasificare a organismelor, sunt mereu prescurtate, prin eliminarea ultimelor lor litere.
Scrieţi un program C/C++ care citeşte de la tastatură un text de tipul precizat și construiește în memorie,
apoi afișează pe ecran denumirea științifică, în care pentru cuvintele specifice sistemului de clasificare a
organismelor se păstrează doar primele trei litere, scrise cu litere mici, și urmate de punct, ca în exemplu.
Exemplu: pentru textul FAMIL. PHASIANIDAE GEN. MELEAGRIS SP. GALLOPAVO
sau pentru textul FAM. PHASIANIDAE G. MELEAGRIS SPECI. GALLOPAVO
se obține fam. PHASIANIDAE gen. MELEAGRIS spe. GALLOPAVO
*/

char MIC(char c)
{
    if(c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

void proceseazaCuv(char cuv[])
{
    int len = strlen(cuv);
    if(cuv[len - 1] == '.'){
        for(int i = 0; i < 3; i++)
            cout << mic(cuv[i]);
        cout << ".";
    }
    else
        cout << cuv;
}

void proceseazaText(char s[])
{
    char cuv[101];
    int k=0;
    for(int i=0; ;i++)
    {
        if(s[i]!=' '&&s[i]!='\0')
        {
            cuv[k++]=s[i];
        }
        else
        {
            cuv[k] = '\0';
            if(k>0)
            {
                proceseazaCuv(cuv);
                cout<<" ";
            }
            k=0;
            if(s[i]=='\0')break;
        }
    }
}

void prob2(){
    char s[] = "FAMIL. PHASIANIDAE GEN. MELEAGRIS SP. GALLOPAVO";
    proceseazaText(s);
}

/*Se consideră o vocală oarecare a alfabetului englez, notată cu v, și o consoană oarecare a alfabetului englez,
notată cu c. Litera v se numeşte vocală prietenă a lui c dacă în şirul literelor alfabetului englez, ordonat
lexicografic, v îl precede pe c, iar între v și c nu există nicio vocală. Se consideră vocale literele a, e, i, o, u.
Exemplu: e este vocală prietenă pentru consoanele f, g și h, dar nu este vocală prietenă pentru
consoanele d și j.
Un elev vrea să transmită unui prieten o parolă, codificată. Parola este formată dintr-un singur cuvânt de
cel mult 50 de caractere, litere mici ale alfabetului englez, cel puțin una fiind consoană. Codificarea se
face prin înlocuirea fiecărei consoane cu vocala sa prietenă, ca în exemplu.
Scrieţi un program C/C++ care citeşte de la tastatură un cuvânt, reprezentând o parolă de tipul precizat şi
determină, în memorie, forma codificată a acesteia. Programul afişează pe ecran parola codificată obţinută.
Exemplu: pentru parola rame se afişează oaie, iar pentru parola sport se afișează ooooo

*/


int esteVocala(char c)
{
    return c=='a'||c=='e' || c=='i' || c=='o' || c=='u';
}

char vocalaPrietena(char c)
{
    char v[] = {'a','e','i','o','u'};

    for(int i = 4; i>=0;i--)
        if(v[i] < c)
            return v[i];
}

void modifica(char s[])
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(!esteVocala(s[i])){
            s[i] = vocalaPrietena(s[i]);
        }
    }
}

void prob4(){
    char s[50]="rame";
    modifica(s);
    cout<<s;
}



/*
Un text, de cel mult 250 de caractere, reprezintă o listă cu date de identificare ale invitaților la o petrecere;
fiecare invitat are un prenume și un nume, care apar în listă în această ordine, urmate de simbolul ;
(punct și virgulă), ca în exemplu. Numele și prenumele sunt formate din câte un singur cuvânt, compus din
litere mari ale alfabetului englez, și sunt separate printr-un spațiu.
Scrieți un program C/C++ care citește de la tastatură un text de tipul precizat mai sus apoi, de pe rândul
următor, un cuvânt, x, și afișează pe ecran, separate prin câte un spațiu, numele tuturor invitaților care au
prenumele x, ca în exemplu, sau mesajul NU dacă nu există astfel de invitați.
Exemplu: dacă lista este DAN MARIS; DANILA PREPELEAC; DAN POPA; EDANA DAN;
și cuvântul x este DAN se afișează pe ecran MARIS POPA

*/


bool ultimaVocala(char cuv[]){
    int len = strlen(cuv);
    return esteVocala(cuv[len-1]);
}

void prob5(){
    int n, k;
    cin >> n >> k;

    char cuv[15];
    int cnt = 0;

    for(int i=0; i<n; i++){
        cin >> cuv;

        if(ultimaVocala(cuv) && cnt < k){
            cout << cuv << endl;
            cnt++;
        }
    }

    if(cnt < k)
        cout << "nu exista";

}

/*
Două cuvinte distincte se numesc în oglindă dacă fiecare dintre ele se obține prin citirea literelor celuilalt de la dreapta la stânga. Exemplu:
animate și etamina sunt în oglindă, iar pentru cuvântul reper nu există un cuvânt cu care să fie în oglindă. Se consideră un text cu cel mult 100 de caractere,
 în care cuvintele sunt formate din litere mici ale alfabetului englez și sunt separate prin câte un spațiu. Scrieți un program C/C++
 care citește de la tastatură un text de tipul menționat mai sus și îl transformă în memorie, înlocuind fiecare cuvânt cu număr impar de litere cu acel cuvânt cu care el
 este în oglindă, dacă acesta există, ca în exemplu. Programul afișează pe ecran textul obținut sau mesajul nu exista, dacă în text nu s-a înlocuit niciun cuvânt. Exemplu:
 pentru textul era o selectie reper de desene animate prezenta se obține textul
 are o selectie reper de desene etamina prezenta iar pentru textul un reper pentru desene se afișează pe ecran mesajul nu exista
*/

bool impar(char cuv[]){
    int i=0;
    while(cuv[i]!='\0') i++;
    return i%2==1;
}

void invers(char sir[], char x[]){
    int n=0;
    while(sir[n]!='\0') {
            n++;
    }
    int k=0;
    for(int i=n-1;i>=0;i--){
        x[k++]=sir[i];
    }
    x[k]='\0';
}

///
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

void prob7(){
    char s[200]="am facut fotografii unei flori mari";
    cout<<"Sirul initial: "<<s<<endl;
    if(transformareSir(s)){
        cout<<s;
    }else{
        cout<<"Nu exista ";
    }
}
/*
Un text are cel mult 100 de caractere, iar cuvintele sale sunt formate numai din litere mici ale alfabetului
englez și sunt separate prin câte un spațiu. Scrieți un program C/C++ care citește de la tastatură un număr
natural n (n∈[1,102]), apoi un text de tipul precizat mai sus, și afișează pe ecran cuvintele acestuia, pe
rânduri separate, astfel încât primele poziții să fie ocupate de mulțimea formată de cele care au cel puțin n
litere, iar următoarele poziții, în continuarea acestora, să fie ocupate de mulțimea celorlalte cuvinte.
Cuvintele din aceeași mulțime sunt afișate într-o ordine oarecare, iar dacă una dintre
cele două mulțimi este vidă, se afișează pe ecran doar mesajul nu exista.
Exemplu: pentru n=5 și textul el mergea tot spre aleea pietruita
datele afișate pot fi cele alăturate. (10p.)
mergea
aleea
pietruita
el
tot
spre
*/





int lungime(char cuv[]){
    int i=0;
    while(cuv[i]!='\0') {
            i++;
    }
    return i;
}

/*
Într-un text cu cel mult 100 de caractere cuvintele sunt formate numai din litere mari și mici ale
alfabetului englez și sunt separate prin câte un spațiu. Scrieţi un program C/C++ care citeşte de la
tastatură un text de tipul precizat, apoi un număr natural, n (n∈[1,102)), şi afişează pe ecran, pe linii
separate, cuvintele din text care au exact n litere. Cuvintele sunt afişate în ordinea apariţiei lor în
text, iar dacă nu există niciun astfel de cuvânt, se afișează pe ecran mesajul nu exista.
Exemplu: dacă se citește textul Fat Frumos este cel mai viteaz
iar n=6, se afişează pe ecran:
Frumos
viteaz
*/




bool afiseazaExact(char cuv[], int nr, int n){
    bool exista=false;
    for(int i=0;i<nr;i++){
        if(lungime(cuv[i])==n){
            cout << cuv[i] << endl;
            exista=true;
        }
    }
    return exista;
}
void prob10(){
    int n;
    char sir[105]="Fat Frumos este cel mai viteaz"
    cin >> n;


}





#endif // TEMA_H_INCLUDED
