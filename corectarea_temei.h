#ifndef corectarea_temei.h
#define corectarea_temei.h
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;




//2 A  radar
//realizati un nou sir cu toate cuvintele palindrome
bool cuvantPalindrom(char s[]){
    int n=strlen(s);
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}

void rezolvare2A(){
    char s[100]="ana radar mere";

    char palindrome[100]="";
    char*cuvant=strtok(s," ");
    while(cuvant!=NULL){
        if(cuvantPalindrom(cuvant)){
            strcat(palindrome,cuvant);
            strcat(palindrome," ");
        }
        cuvant=strtok(NULL," ");

    }

    cout<<palindrome;

}

void rezolvare2aFaraSTRTOK(){
    char s[100]="ana text radar mere";
    char palindrome[100]="";
    int start=0;
    for(int i=0;i<=strlen(s);i++){
        char cuvant[100]="";
        int k=0;
        if(s[i]!=' ' && s[i]!='\0'){
            while(s[i]!=' ' && s[i]!='\0'){
                cuvant[k]=s[i];
                i++;
                k++;
            }
            cuvant[k]='\0';

        }

          if(cuvantPalindrom(cuvant)){
                strcat(palindrome,cuvant);
                strcat(palindrome," ");
           }
    }
      cout<<palindrome<<endl;
}

///parcurgere
//char s[100]="ana text radar mere";

//i=0     i<=strlen     k=0       if(s[i]!=' ' && s[i]!='\0')       { while(s[i]!=' ' &&)       cuvant[k]=s[i];          i++           k++   }       if(cuvPalindrom(cuvant))     strcat(palindrome,cuvant)  strcat(palindrome," ")
//0       0<= da        k=0                   da                            da                    cuv[0]=s[0]            1             1
//                                                                          da                    cuv[1]=s[1]            2             2
//                                                                          da                    cuv[2]=s[2]            3             3
//                                                                          nu                                                                       cuv=ana  da este pal              palindrome="ana"         palindrome="ana "
//4       4<=da         k=4                   da                            da                    cuv[4]=s[4]            5             5
//                                                                          da                    cuv[5]=s[5]            6             6
//                                                                          da                    cuv[6]=s[6]            7             7
//                                                                          da                    cuv[7]=s[7]            8             8
//                                                                          nu                                                                       cuv=text nu este palindrom
//9       9<=da         k=9                   da                            da                    cuv[9]=s[9]            10            10
//                                                                          da                    cuv[10]=s[10]          11            11
//                                                                          da                    cuv[11]=s[11]          12            12
//                                                                          da                    cuv[12]=s[12]          13            13
//                                                                          da                    cuv[13]=s[13]          14            14
//                                                                          nu                                                                       cuv=radar da este pal             palindrome="ana radar"   palindrome="ana radar "
//15      15<=da        k=15                  da                            da                    cuv[15]=s[15]          16            16
//                                                                          da                    cuv[16]=s[16]          17            17
//                                                                          da                    cuv[17]=s[17]          18            18
//                                                                          da                    cuv[18]=s[18]          19            19
//                                                                          nu                                                                       cuv=mere nu este pal
//19      19<=strlen nu                  cout<< palindrome == ana radar

//2 B
///afisati cuvantul care are cele mai multe vocale

bool esteVocala(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}
int numaraVocale(char s[100]){
    int ct=0;
    for(int i=0;i<=strlen(s);i++){
        if(esteVocala(s[i])){
            ct++;
        }
    }
    return ct;
}

void frecventaLitere(char text[100],int frecventa[]){
    for(int i=0;i<strlen(text);i++){
        if(text[i]>='a'&&text[i]<='z'){
            frecventa[text[i]]++;
        }
    }

}

void afisareVocale(char s[100]){
    int f[26];
    frecventaLitere(s,f);
    cout<<f[0]+f[4]+f[8]+f[14]+f[20];

}

void rezolvare2B(){
    char text[100]="ana are mere";
    afisareVocale(text);
}


//2 e
//sa se verifice de cate ori apare ultimul cuvant in sir

void ultimulCuvant(char s[100],char ultimulCuv[]){
    int n=strlen(s);
    int start =0;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            start=i+1;
        }
    }
    int cuv=n-start;
    strncpy(ultimulCuv,s+start,cuv);

}

int frecventaCuvant(char s[100],char cuvant[]){
    int ct=0;
    int n=strlen(s);
    int m=strlen(cuvant);
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(s[i+j]==cuvant[j]&&j<m){

            j++;
        }
        if(j==m){
            ct++;
        }
    }
    return ct;
}

void rezolvare2E(){
    char sir[200]="Ana are mere si mai are";
    char ultimul[100];
    ultimulCuvant(sir,ultimul);
    cout<<sir<<endl;
    cout<<"Ultimul cuvant al sirului este: "<<ultimul <<endl;
    cout<<"Apare de  "<<frecventaCuvant(sir,ultimul);
}

///PArcurgere 2E
//Ana are mere si mai are
// n =19 si m=3
/*
//  ct=0      i   i<=n-m     j    { while    (s[i+j]==cuvant[j]&&j<m)   j++ }     if j==m   ct++     i++
      0       0   0<=16      0                  s[0]==a&&0<3 nu                       nu      0       1
      0       1   1<=16      0                  s[1]==a&&0<3 nu                       nu      0       2
      0       2   2<=16      0                  s[2]==a&&0<3 da          1            nu      0       3
                             1                  s[3]==r&&1<3 nu          1            nu      0
      0       3   3<=16      0                  s[3]==a&&0<3 nu                       nu      0       4
      0       4   4<=16      0                  s[4]==a&&0<3 da          1
                             1                  s[5]==r&&1<3 da          2
                             2                  s[6]==e&&2<3 da          3            da      1       5
      1       5   5<=16      0                  s[5]==a&&0<3 nu                       nu      1       6
      1       6   6<=16      0                  s[6]==a&&0<3 nu                       nu      1       7
      1       7   7<=16      0                  s[7]==a&&0<3 nu                       nu      1       8
      1       8   8<=16      0                  s[8]==a&&0<3 nu                       nu      1       9
      1       9   9<=16      0                  s[9]==a&&0<3 nu                       nu      1       10
      1      10  10<=16      0                 s[10]==a&&0<3 nu                       nu      1       11
      1      11  11<=16      0                 s[11]==a&&0<3 nu                       nu      1       12
      1      12  12<=16      0                 s[12]==a&&0<3 nu                       nu      1       13
      1      13  13<=16      0                 s[13]==a&&0<3 nu                       nu      1       14
      1      14  14<=16      0                 s[14]==a&&0<3 da          1
                             1                 s[15]==r&&1<3 da          2
                             2                 s[16]==e&&2<3 da          3            da      2       15
      2      15  15<=16      0                 s[15]==a&&0<3 nu                       nu      2       16
      2      16  16<=16      0                 s[16]==a&&0<3 nu                       nu      2       17
      2      17  17<=16 nu-------
      return Apare de 2
*/




//3 C
//sa se inverseze toate cuvintele ce nu sunt palindrome

void inversare(char cuvant[]){
    int n=strlen(cuvant);
    for(int i=0;i<n/2;i++){
        char aux=cuvant[i];
        cuvant[i]=cuvant[n-1-i];
        cuvant[n-1-i]=aux;
    }
}

void verifCuvant(char cuvant[]){
    if(!cuvantPalindrom(cuvant)){
        inversare(cuvant);
    }
}
void afisareSir(char sir[]){
    char cuvant[50];
    int k=0;
    for(int i=0;i<=strlen(sir);i++){
        if(sir[i]!=' '&&sir[i]!='\0'){
            cuvant[k++]=sir[i];
        }
        else{
            cuvant[k]='\0';
            verifCuvant(cuvant);
            cout<<cuvant;
            if(sir[i]!='\0'){
                cout<<" ";
            }
            k=0;
        }
    }
}



void rezolvare3C(){
    char sir[200]="ana era nu level eram al radar";
    cout<<"Inainte"<<endl;
    cout<<sir<<endl;
    cout<<"Dupa modificare"<<endl;
    afisareSir(sir);

}

///parcurgere 3C
//ana era nu level eram al radar

//     i      i<strlen      if(sir[i]!=' '&&sir[i]!='\0')      cuvant[k++]=sir[i];         else cuvant[k]='\0';    cout<<cuvant     if(sir[i]!='\0')     cout<<" ";
//     0      0<da                     da                              a
//     1      1<da                     da                             an
//     2      2<da                     da                             ana
//     3      3<da                     nu








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

void afisareCuvinte(char sir[],int n){
    cin>>n;
    int k=0;
    char cuvMaiMare[50][50];
    int dimMare=0;
    char cuvMaiMica[59][50];
    int dimMica=0;
    for(int i=0;i<strlen(sir);i++){
         if(sir[i]!=' '){
            char cuvant[100];
            int k=0;
            while(sir[i]!=' '&&i<strlen(sir)){
                cuvant[k++]=sir[i];
                i++;
            }
            cuvant[k]='\0';
            if(strlen(cuvant)>=n){
                //cout<<cuvant<<endl;
               strcpy(cuvMaiMare[dimMare++],cuvant);
            }else{
                //cout<<cuvant<<endl;
               strcpy(cuvMaiMica[dimMica++],cuvant);
            }

         }
    }
    cout<<"n este : "<<n<<endl;
    cout<<"Cuvintele care sunt egale sau mai mari ca n:"<<endl;
    for(int i=0;i<dimMare;i++){
        cout<<cuvMaiMare[i]<<endl;
    }
    cout<<"Cuvintele care sunt egale sau mai mici ca n:"<<endl;
    for(int i=0;i<dimMica;i++){
        cout<<cuvMaiMica[i]<<endl;
    }

}

void rezolvareBAC2020(){
    char sir[100]="Ana are mere rosii si banane";
    int n,total;
    afisareCuvinte(sir,n);



}











#endif // corectarea_temei.h
