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
        if(esteVocala(s[i])){
            cnt++;
        }
    }
    return cnt;
}

void rezolvare1(){
    char s[200];
    cin.getline(s,200);
    cout<<numaraVocale(s);
}

//Să se afișeze câte litere mari are șirul.

bool literaMare(char c) {
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
        if(!esteVocala(s[i])){
            s[k++]=s[i];
        }
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









#endif // TEMA_H_INCLUDED
