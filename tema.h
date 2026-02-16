#ifndef TEMA_H_INCLUDED
#define TEMA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


///ex2
//a
bool palindrom(char w[]) {
    int i = 0, j = strlen(w) - 1;
    while (i < j) {
        if (w[i] != w[j]) return false;
        i++; j--;
    }
    return true;
}
void cuvintePalindrom(char s[]) {
    char copie[205];
    strcpy(copie, s);
    char sep[200];

    char p = strtok(copie, sep);
    cout << "Palindroame: ";
    while (p) {
        if (palindrom(p)) cout << p << " ";
        p = strtok(NULL, sep);
    }
    cout << endl;
}


//c
void stergeCuvinteScurte(char s[]) {
    char copie[205];
    strcpy(copie, s);
    char sep[200];

    char rez[205] = "";
    char *p = strtok(copie, sep);

    while (p) {
        if (strlen(p) >= 4) {
            strcat(rez, p);
            strcat(rez, " ");
        }
        p = strtok(NULL, sep);
    }
    strcpy(s, rez);
}

//d
void alTreileaCuvant(char s[]) {
    char copie[205];
    strcpy(copie, s);
    char sep[200];

    char *p = strtok(copie, sep);
    int k = 1;

    while (p) {
        if (k == 3) {
            cout << "Al 3-lea cuvant: " << p << endl;
            return;
        }
        k++;
        p = strtok(NULL, sep);
    }
}

//f
void dubleazaTriplete(char s[]) {
    char rez[405];
    int j = 0;
    char sep[200];

    for (int i = 0; s[i]; i++) {
        rez[j++] = s[i];
        if (s[i] && s[i] == s[i + 1] && s[i] == s[i + 2]) {
            rez[j++] = s[i];
            rez[j++] = s[i];
            rez[j++] = s[i];
        }
    }
    rez[j] = 0;
    strcpy(s, rez);
}

void rezolvareEX2(){
    char s[205];
    cin.getline(s, 200);
    cout << "a) ";
    cuvintePalindrom(s);

    stergeCuvinteScurte(s);
    cout << "c) " << s << endl;

    cout << "d) ";
    alTreileaCuvant(s);

    dubleazaTriplete(s);
    cout << "f) " << s << endl;
}

///ex3

//a
void eliminaSpatiiMultiple(char text[100]){
    for(int i=0;i<strlen(text)-1;i++){
        if(text[i]==' '&&text[i+1]==' '){
            stergere(text,i);
            i--;
        }
    }


}
//b
char micLaMar(char c){
    if(c>='a'&&c<='z'){
        c=c-32;
    }
    return c;
}

char urmatorulCar(char c){

if(c>='a'&&c<='z'){

        return c+1;

}
return c;

}


void rezB(char c[]){
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



//d
int aparitii(char s[], char w[]) {
    char copie[205];
    strcpy(copie, s);

    char *p = strtok(copie, sep);
    int cnt = 0;

    while (p) {
        if (strcmp(p, w) == 0) cnt++;
        p = strtok(NULL, sep);
    }
    return cnt;
}
void cuvinteUnice(char s[]) {
    char copie[205];
    strcpy(copie, s);

    char *p = strtok(copie, sep);
    cout << "Cuvinte unice: ";

    while (p) {
        if (aparitii(s, p) == 1)
            cout << p << " ";
        p = strtok(NULL, sep);
    }
    cout << endl;
}

//e
void modificaLitere(char s[], char C, char D) {
    char rez[405];
    int j = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == C) continue;

        rez[j++] = s[i];

        if (s[i] == D)
            rez[j++] = s[i];
    }

    rez[j] = 0;
    strcpy(s, rez);
}

void rezolvareEX3(){
    char s[205];
    cin.getline(s, 200);

    eliminaSpatiiMultiple(s);
    cout << "a "<<s<< endl;

    rezB(s);
    cout << "b "<<s<< endl;

    cout << "d ";
    cuvinteUnice(s);

    char C, D;
    cin >> C>>D;
    modificaLitere(s, C, D);
    cout << "e) " << s << endl;
}









#endif // TEMA_H_INCLUDED
