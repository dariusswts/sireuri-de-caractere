#ifndef siruri_de_caractere.h
#define siruri_de_caractere.h
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;





void declarare(){
    char p[100]="Ana are mere";

    char x[100]="";
    cin.getline(x,100);
    cout<<p<<endl;
    cout<<x<<endl;


}


void lungime(){
    char p[100]="Ana are mere";
    cout<<strlen(p);

}

void copiaza(){
    char p1[100]="ana";
    char p2[100]="are mere";

    strcpy(p1,p2);

    cout<<p1<<endl;
}
void alipire (){
    char p1[100]="ana ";
    char p2[100]="are mere";

    strcat(p1,p2);

    cout<<p1<<endl;
}

void alipeste_cat_doresti(){
    // adauga de la sursa cat doresti in rest e la fel ca prog copiaza
    char p1[100]="ana";
    char p2[100]="are mere";
    strncat(p1,p2,5);
    cout<<p2;

}


void cauta_caracterul(){
    //couat caracterul si si citeste pana la el dupa afiseaza de la stanga la dreapta de unde a gasit caracterul
    char p1[100]="ana";
    char p2[100]="are mere";
    strchr(p2,'e');
    cout<<strchr(p2,'e');
}


void ultima_aparitie(){
    //are acelasi rol ca cel de sus doar ca returneaza ultima aparitie a caracterului
    char p1[100]="ana are mere";
    cout<<strrchr(p1,'a');
}

void compara(){
    //compara alfabetic adica ia a cu a dupa r cu x r<x si tot asa
    char p1[100]="ax";
    char p2[100]="are mere";
    strcmp(p1,p2);
    cout<<strcmp(p1,p2);
}

void verifica_daca_este_subsir(){
    //acesta verifica daca p1 este subsir al lui p2 iar daca este afiseaza p2
    char p1[100]="are";
    char p2[100]="are mere";
    strstr(p1,p2);
    cout<<strstr(p2,p1);
}

void compara_dar_nu_face_dif_litMariSiMici(){
    //acelasi ro ca stremp doar ca nu face diferenta intre literele mari si cele mici
    char p1[100]="axx";
    char p2[100]="are mere";
    //stricmp(p1,p2);
    cout<<stricmp(p1,p2);
}

void separa(){

    char p1[100]="Ana are mere";
    char*cuvant=strtok(p1," ");
     while(cuvant!=NULL){
        cout<<cuvant<<endl;
        cuvant=strtok(NULL," ");

    }
}
///exemplu la separare cuvinte cu vector de cuvinte
void vectorCuv(char sir[100],char cuvinte[100][100]){
    int n=0;
    cin.getline(sir,100);
    char*p=strtok(sir," ");
    while(p!=NULL){
        strcpy(cuvinte[n],p);
        cout<<p<<endl;
        n++;
        p=strtok(NULL," ");

    }
}













#endif // siruri_de_caractere.h
