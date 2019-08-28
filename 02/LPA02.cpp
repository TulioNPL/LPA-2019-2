#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

int valores[] = {5,10,20,50,100,200,500,1000,2000,5000,10000}; //todos valores convertidos para cents

int main() {
    vector<double> input;
    string str;
    int tam = sizeof(valores)/sizeof(int);
  
    //le as entradas
    do{
        double entrada;
       
        ostringstream strs;

        cin >> entrada;
        input.push_back(entrada);

        strs << entrada;
        str = strs.str();
    }while(str.compare("0") != 0);
    input.pop_back();   //remove o elemento "0.00"

    //caminha pelas entradas e printa os resultados
    for(auto i = input.begin(); i != input.end(); i++) {   
        int aux = (int)(*i*100+0.0001);//corrige a conversao(eh o valor de entrada)
        long long resp[aux+1];  //array auxiliar para calcular
        memset(resp,0,sizeof(resp));    //aloca o espaco necessario na memoria
        
        resp[0] = 1;    //posicao 0 precisa ter valor 1 por conta da "recursividade"
          
        for(int k = 0; k < tam; k++) { 
            for(int j = valores[k]; j <= aux; j++) {
                resp[j] += resp[j-valores[k]];  //soma as possibilidades atuais com as possibilidades dos valores anteriores
            }
        }
        printf("%6.2lf%17lld\n", *i, resp[aux]);        
    }

    return 0;
}