#ifndef PROBLEME_H_INCLUDED
#define PROBLEME_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;





/*
//sa se elimine spatile multiple dintre cuvinte
void eliminaSpatiiMultiple(char text[100],int poz){
    for(int i=poz;i<strlen(text)-1;i++){
        if(text[i]==' '&&text[i+1]==' '){
            stergere(text,i);
            i--;
        }
    }


}*/
void stergere(char x[],int poz){

    for(int i=poz;i<strlen(x)-1;i++){
        x[i]=x[i+1];
    }
    x[strlen(x)-1]='\n';
}

//poz=2 x[100]
//char a[200]="Ana are mere";

// i       i<strlen       x[i]=x[i+1]                 i++   x[strlen(x)-1]='\n'
// 2       2<strlen da       a=' '=> An  are mere                3
// 3       3<strlen da       ' '=a=> An aare mere                4
// 4       4<strlen da       a=r=>   An arre mere                5
// 5       5<strlen da       r=e=>   An aree mere                6
// 6       6<strlen da       e=' '=> An are  mere                7
// 7       7<strlen da     ' '= m => An are mmere                8
// 8       8<strlen da       m=e =>  An are meere                9
// 9       9<strlen da       e=r =>  An are merre                10
// 10     10<strlen da       r=e =>  An are mere                 11
// 11     11<strlen nu                               stop

//afisare : An are mere

//sa se elimine spatile multiple dintre cuvinte
void eliminaSpatiiMultiple(char text[100]){
    for(int i=0;i<strlen(text)-1;i++){
        if(text[i]==' '&&text[i+1]==' '){
            stergere(text,i);
            i--;
        }
    }


}





void ex1A(){
    char p[200]="Ana      are          mere";
    eliminaSpatiiMultiple(p);
    cout<<"Sirul fara spati multiple : "<<endl;
    cout<<p;


}


//Sa se transforme prima litera din fiecare cuvant in litera mare si sa se inlocuiasca ultima litera din fiecare cuvant cu urmatoarea de dupa ea din alfabet


//functie ce primeste ca parametru un caracate

char micLaMare(char c){
    if(c>='a'&&c<='z'){
        c=c-32;
    }
    return c;
}

char urmatorulCaracter(char c){

if(c>='a'&&c<='z'){

        return c+1;

}
return c;

}


void solutieB(char c[]){
    c[0]=micLaMare(c[0]);

    for(int i=1;i<strlen(c)-1;i++){
       if(c[i-1]==' '){
            c[i]=micLaMare(c[i]);
       }
       if(c[i+1]==' '){
            c[i]=urmatorulCaracter(c[i]);
       }

    }

    c[strlen(c)-1]=urmatorulCaracter(c[strlen(c)-1]);
    cout<<c;

}

///subpunctul   C
//Dublati toate vocalele mari si stergeti toate vocalele mici


bool esteVocalaMare(char c){
     if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
        return 1;
     }
     return 0;
}

bool esteVocalaMica(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        return 1;
    }
    return 0;
}

void stergeVocaleMici(char sir[]){
    int lung=strlen(sir);
    for(int i=0;i<strlen(sir);i++){
        if(esteVocalaMica(sir[i])){
            stergere(sir,i);
            i--;
            lung--;
        }
    }
}
void inserareCaracter(char sir[],int poz,int car){
    for(int i=strlen(sir)-1;i>=poz;i--){
       sir[i+1]=sir[i];
    }
    sir[poz]=car;

}

void dubleazaVocaleleMari(char sir[]){
    int lung=strlen(sir);
    for(int i=0;i<strlen(sir);i++){
        if(esteVocalaMare(sir[i])){
            inserareCaracter(sir,i+1,sir[i]);
            i++;
            lung++;
        }
    }
}

void ex1C(){
    char sir[300]="Ana arE mEre si cAIse";
    stergeVocaleMici(sir);
    dubleazaVocaleleMari(sir);
    cout<<"Sirul va arata : "<<sir<<endl;
}






#endif // PROBLEME_H_INCLUDED
