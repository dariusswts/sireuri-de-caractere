#include <iostream>
#include <fstream>
#include "pbinfo_BAC.h"
using namespace std;
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

int main()
{
    bac2019ultimul();




    return 0;
}
