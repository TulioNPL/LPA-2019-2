#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

#define N 30000 //maior tamanho possivel de entrada

long long resp[N + 1];  //array que contera as respostas
int valores[] = {5,10,20,50,100,200,500,1000,2000,5000,10000}; //todos valores convertidos para cents

int main() {
    vector<double> input;
    string str;
    int tam;
    memset(resp,0,sizeof(resp));    //aloca o espaco necessario na memoria
  
    //le as entradas
    do{
        double entrada;
       
        ostringstream strs;

        cin >> entrada;
        input.push_back(entrada);

        strs << entrada;
        str = strs.str();
    }while(str.compare("0") != 0);

    tam = sizeof(valores)/sizeof(int);
    resp[0] = 1; //posicao 0 precisa ter valor 1 por conta da "recursividade"

    for(int i = 0; i < tam; i++) {
        for(int j = valores[i]; j <= N; j++) {
            /*if(j == 200){ 
                cout << "resp[" << j << "] = " << resp [j] << endl;
                cout << "resp[" << j-valores[i] << "] = " << resp[j-valores[i]] << endl; 
            }*/
            
            resp[j] += resp[j-valores[i]];
            
            //if(j == 200) cout << "resp["<< j << "] += resp["<<j-valores[i]<<"] = " << resp[j] << endl;
        }
    }

    //caminha pelas entradas e printa os resultados
    for(auto i = input.begin(); i != input.end(); i++) {   
        int aux;
        aux = (int)(*i*100+0.0001);//corrige a conversao
        if(*i > 0.00f){ //somente printa a resposta se o valor for maior do que 0.00
            printf("%6.2lf%17lld\n", *i, resp[aux]);        
        }
    }

    return 0;
}