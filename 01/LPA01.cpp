#include <iostream>
using namespace std;

int main() {
    int dimension;
    cin >> dimension;
    int matrix[dimension][dimension];

    for(int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++){
            cin >> matrix[i][j];
        }
    }
    
    //Apenas para printar e testar a entrada
    for(int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++){
            cout << matrix[i][j]; 
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}