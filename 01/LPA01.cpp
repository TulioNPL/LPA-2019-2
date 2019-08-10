#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Le a entrada e seta os valores na matrix
 */
void leEntrada(int *matrix, int dimension) {
    for(int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++){
            cin >> *((matrix + i*dimension) + j);   //Na memoria a matriz eh armazenada como um array continuo
        }
    }
}//end leEntrada()

/**
 * Calcula o valor da soma do retangulo com maior soma dentro da matriz
 */
int calcMaiorSoma(int *matrix, int dimension) {
    int soma = 0;
    int maiorSoma = INT_MIN;
    int iteracoes = 0;

    //Os 4 for externos limitam linhas e colunas
    for(int i = 0; i < dimension; i++) {
        for(int j = 0; j < dimension; j++) {
            for(int k = 0; k < dimension; k++) {
                for(int l = 0; l < dimension; l++) {

                    //Os 2 for internos caminham pela matriz fazendo as somas
                    for(int m = i; m <= k; m++) {
                        for(int n = j; n <= l; n++) {
                            soma += *((matrix + m*dimension) + n);
                            iteracoes++;
                            
                            if(soma > maiorSoma) {
                                maiorSoma = soma;
                            }
                        }
                    }
                    
                    //cout << "Soma: " << soma << "       maiorSoma: " << maiorSoma << endl;
                     
                    soma = 0;
                }
            }
        }
    }

    //cout << iteracoes << endl;

    return maiorSoma;
}//end calcMaiorSoma()

int main() {
    int dimension;
    int maiorSoma;

    cin >> dimension;
    int matrix[dimension][dimension];
    
    leEntrada(*matrix, dimension);

    maiorSoma = calcMaiorSoma(*matrix, dimension);

    cout << maiorSoma << endl;
    return 0;
}//end main()