#ifndef temaBAC.h
#define temaBAC.h
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/*
Să se scrie un program C/C++ care citeşte de la tastatură un cuvânt format din cel mult 20
de caractere, doar litere mici ale alfabetului englez. Programul determină transformarea
cuvântului citit prin înlocuirea fiecărei vocale a cuvântului, cu un şir format din două caractere
şi anume vocala respectivă urmată de litera mare corespunzătoare, restul literelor
nemodificându-se, ca în exemplu. Programul afişează pe ecran cuvântul obţinut, pe o
singură linie. Se consideră vocale literele din mulţimea {a,e,i,o,u}.
Exemplu: pentru cuvântul bacalaureat se va afişa pe ecran: baAcaAlaAuUreEaAt
*/

void r1(){
    char s[250]="bacalaureat";
    char rezultat[200];
    int j=0;
    for(int i=0;i<strlen(s);i++){
       if(strchr("aeiou",s[i])){
        cout<<s[i]<< char(s[i]-32);
       }
       else{
        cout<<s[i];
       }
    }
}
/*
Se consideră un text alcătuit din cel mult 250 de caractere, în care cuvintele sunt formate doar
din litere mici ale alfabetului englez şi sunt separate prin unul sau mai multe caractere *.
Scrieţi un program C/C++ care citeşte de la tastatură textul şi afişează pe ecran, pe câte o
linie, toate secvenţele formate din câte două litere identice, ca în exemplu.
5.
Exemplu: dacă textul citit este:copiii*sunt*la***zoo se afişează
perechile alăturate.
ii
ii
oo
*/

void r2(){
    char s[250]="copiii*sunt*la***zoo";
    int n=strlen(s);
    cout<<s<<endl;
    for(int i=0;i<n;i++){
        if(s[i]!='*'&&s[i+1]!='*'&&s[i]==s[i+1]){
            cout<<s[i]<<s[i+1]<<endl;
        }
    }
}
/*
Scrieţi programul C/C++ care citeşte de la tastatură un şir de cel mult 40 de caractere,
format doar din litere ale alfabetului englez, şi care afişează pe ecran toate şirurile obţinute
prin eliminarea succesivă a câte unei singure litere din şirul citit, ca în exemplu. Şirurile se
vor afişa câte unul pe câte o linie a ecranului.
Exemplu: dacă se citeşte şirul abbc atunci pe ecran se va afişa:
bbc
abc
abc
abb
*/


void r4(){
    char s[41];
    int i,j,n;

    cin>>s;
    n=strlen(s);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                cout<<s[j];
            }
        }
        cout<<'\n';
    }
}

/*
Se consideră un text format doar din spaţii şi litere mici ale alfabetului englez, care începe
cu o literă şi care conţine cel puţin o vocală din multimea {a,e,i,o,u}. Scrieţi programul
C/C++ care citeşte de la tastatură un şir cu cel mult 100 de caractere, ca cel descris mai
sus şi care determină transformarea acestuia prin înlocuirea fiecărei vocale din text cu litera
imediat următoare din alfabet (a se înlocuieşte cu b, e se înlocuieşte cu f ş.a.m.d.).
Programul va afişa pe ecran şirul obţinut.
Exemplu: dacă şirul citit este examen de bacalaureat, după modificare se afişează:
fxbmfn df bbcblbvrfbt
*/

void r5(){
    char s[101];
    int i,n;
    cout<<"introdu un sir: ";
    cin.get(s,101);
    n=strlen(s);

    for(i=0;i<n;i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        {
            s[i]=s[i]+1;
        }
    }

    cout<<s;
}

/*
Un cuvânt s, de cel mult 20 caractere, format doar din litere mici ale alfabetului englez,
conţine cel puţin o consoană şi cel puţin o vocală. Scrieţi programul C/C++ care citeşte de la
tastatură cuvântul s, construieşte în memorie şi afişează pe ecran cuvântul obţinut prin
eliminarea tuturor consoanelor din cuvântul s. Se consideră consoană oricare literă care nu
se află în mulţimea {a, e, i, o, u}.
Exemplu: dacă se citeşte cuvântul bacalaureat, pe ecran se afişează: aaauea
*/



void r6(){
    char s[100]="bacalaureat";
    int i,n;

    n=strlen(s);

    for(i=0;i<n;i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        {
            cout<<s[i];
        }
    }
}

/*
Scrieţi programul C/C++ care citeşte de la tastatură un cuvânt s de cel mult 20 litere mici ale
alfabetului englez, construieşte în memorie şi afişează pe ecran cuvântul s după eliminarea
primei şi a ultimei vocale. Cuvântul s conţine cel puţin două vocale şi cel puţin o consoană. Se
consideră vocale literele: a, e, i, o, u.
Exemplu: dacă se citeşte cuvântul bacalaureat, pe ecran se afişează: bcalauret
*/

void r8(){
    char s[100]="bacalaureat";
    int i,n,prim,ultim;
    n=strlen(s);
    for(i=0;i<n;i++){
        if(strchr("aeiou", s[i]))
        {
            prim=i;
            break;
        }
    }

    for(i=n-1;i>=0;i--){
        if(strchr("aeiou", s[i]))
        {
            ultim=i;
            break;
        }
    }

    for(i=0;i<n;i++){
        if(i!=prim && i!=ultim)
        {
            cout<<s[i];
        }
    }
}

/*
Scrieţi un program C/C++ care citeşte de la tastatură un şir de cel mult 50 de caractere
(cifre, litere ale alfabetului englez şi spaţii; şirul conţine cel puţin o literă), apoi construieşte
în memorie şi afişează pe ecran şirul de caractere obţinut din şirul citit prin eliminarea tuturor
caracterelor care nu sunt litere.
Exemplu: dacă se citeşte şirul: Voi lua 10 la informatica atunci se va afişa:
Voilualainformatica
*/

void r9(){
    char s[100]="Voi lua 10 la informatica";
    int i,n;
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            cout<<s[i];
        }
    }
}

/*
Un şir cu maximum 255 de caractere conţine cuvinte separate prin unul sau mai multe spaţii.
Cuvintele sunt formate numai din litere mici ale alfabetului englez. Scrieţi un program C/C++
care citeşte un astfel de şir şi îl afişează modificat, prima şi ultima literă a fiecărui cuvânt fiind
afişată ca literă mare.
Exemplu: pentru şirul: maine este proba la informatica se va afişa:
MainE EstE ProbA LA InformaticA
*/

void r11(){
    char s[255]="maine este proba la informatica";
    int n=strlen(s);
    cout<<s<<endl;
    for(int i=0;i<n;i++){
        s[0]=s[0]+32;
        if(s[i]==' '){
            s[i+1]=s[i+1]-32;
        }
        if(s[i+1]==' '){
            s[i]=s[i]-32;
        }
        s[n-1]=s[n-1]+32;
    }
    cout<<s;
}


/*
Scrieţi un program C/C++ care citeşte de la tastatură un text de cel mult 255 de caractere,
dintre care cel puţin unul este o literă mică a alfabetului englez, şi afişează pe ecran, pe o
singură linie, despărţite prin câte un spaţiu, toate literele mici ale alfabetului englez care
apar în text. Fiecare literă va fi afişată o singură dată, în ordinea primei ei apariţii în text.
Exemplu: pentru textul:
Calculati valoarea expresiei
 (10p.)
Pe ecran se va afişa:
a l c u t i v o r e x p s
*/


void r12(){
    char s[256]="Calculati valoarea expresiei ";
    int i,n;
    n=strlen(s);
    for(i=0;i<n;i++){
        if(s[i]>='a' && s[i]<='z'){
                cout<<s[i]<<" ";
            }
        }
}


/*
Se consideră variabilele s1 şi s2 de tip şir de caractere. Scrieţi o secvenţă de instrucţiuni
care, în urma executării, afişează pe ecran cele 2 şiruri în ordine lexicografică crescătoare,
separate printr-un spaţiu.
Exemplu: dacă s1 reţine şirul mama şi s2 reţine şirul macara, pe ecran se va afişa
macara mama
*/

void r13(){
    char s1[100]="mama";
    char s2[100]="macara";

    if(strcmp(s1,s2))
    {
        cout<<s2<<" "<<s1;
    }
    else
    {
        cout<<s1<<" "<<s2;
    }
}

/*
5. Scrieţi programul C/C++ care citeşte de la tastatură un cuvânt format din cel mult 50
caractere, doar litere mari ale alfabetului englez, şi afişează pe ecran, fiecare pe câte o linie,
toate sufixele acestuia, în ordine crescătoare a lungimilor. Un sufix de lungime k al unui
cuvânt este un subşir format din ultimele k caractere ale acestuia. (10p.)
Exemplu: dacă se citeşte cuvântul EXAMEN se vor afişa sufixele :
N
EN
MEN
AMEN
XAMEN
EXAMEN
*/


void r14(){
    char s[100]="EXAMEN";
    int n=strlen(s);
    int i,j;

    for(i=1;i<=n;i++){
        for(j=n-i;j<n;j++){
            cout<<s[j];
        }
        cout<<endl;
    }
}

/*
Scrieţi programul C/C++ care citeşte de la tastatură un cuvânt format din cel mult 50 de
caractere, doar litere mari ale alfabetului englez, şi afişează pe ecran, fiecare pe câte o linie,
toate prefixele acestuia, în ordine crescătoare a lungimilor. Un prefix de lungime k al unui
cuvânt este un subşir format din primele k caractere ale acestuia. (10p.)
Exemplu: dacă se citeşte cuvântul BACALAUREAT se vor afişa prefixele:
B
BA
BAC
BACA
BACAL
BACALA
BACALAU
BACALAUR
BACALAURE
BACALAUREA
BACALAUREAT

*/

void r15(){
    char s[100]="BACALAUREAT";
    int n=strlen(s);
    int i,j;

    for(i=1;i<=n;i++){
        for(j=0;j<i;j++)
        {
            cout<<s[j];
        }
        cout<<endl;
    }
}



#endif // temaBAC.h
