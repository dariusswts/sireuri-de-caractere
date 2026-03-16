#ifndef tema2.h
#define tema2.h
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


//8
void micaMare(char s[])
{
    for(int i=0;i<strlen(s);i++)
    {
        if(i==0 || s[i-1]==' '){
            if(s[i]>='a' && s[i]<='z'){
                s[i]=s[i]-32;
            }
        }
    }
}

void rezolvare8(){
    char s[256];
    cin.getline(s,256);

    char *p=strtok(s,".");

    while(p!=NULL)
    {
        micaMare(p);
        cout<<p<<endl;
        p=strtok(NULL,".");
    }
}

///9
int fata(char s[])
{
    if(s[strlen(s)-1]=='a')
        return 1;
    return 0;
}
void mare(char s[]){
    for(int i=0;i<strlen(s);i++)
        if(s[i]>='a' && s[i]<='z')
            s[i]=s[i]-32;
}


///10

int vocala(char c)
{
    if(strchr("aeiou", c)){
        return 1;
    }
    return 0;
}

char silaba(char s[])
{
    for(int i=strlen(s)-1;i>=0;i--){
        if(vocala(s[i])){
            return s+i;
        }
    }
    return s;
}

void rezolvare10(){
    char a[100],b[100];
    cin>>a>>b;
    if(strcmp(silaba(a),silaba(b))==0)
        cout<<"Rimeaza";
    else
        cout<<"Nu rimeaza";
}


///11



///12
int numar(char s[])
{
    for(int i=0;i<strlen(s);i++)
        if(s[i]<'0' || s[i]>'9')
            return 0;
    return 1;
}

void rezolvare12(){
    char s[256]="Ana are 7 mere si 223 de pere";
    char *p=strtok(s," ");
    while(p!=NULL)
    {
        if(numar(p)==1)
            cout<<p<<" ";

        p=strtok(NULL," ");
    }

}












#endif // tema2.h
