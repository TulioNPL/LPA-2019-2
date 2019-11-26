#include <iostream>

using namespace std;

/*Retorna o meior entre dois inteiros*/
int MAX(int a, int b) {
    int resp;

    if (a > b) resp = a;
    else resp = b;

    return resp;
}

/*Problema da mochila - Dinamico*/
int mochila(int N, int P, int tempo[], int pizzas[]) {
    int K[N+1][P+1];

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= P; j++){
            if(i == 0 || j == 0)
                K[i][j] = 0;
            else{
                if(pizzas[i] > j)
                    K[i][j] = K[i - 1][j];
                else
                    K[i][j] = MAX(K[i - 1][j - pizzas[i]] + tempo[i], K[i - 1][j]);
            }
        }
    }

    return K[N][P];
}

//Driver
int main() {
    int n;
    cin >> n;

    while(n != 0) {
        int tmps[n];
        int qtds[n];
        int p;
        cin >> p;

        tmps[0] = 0;
        qtds[0] = 0;
        for(int i = 1; i <= n; i++) {
            int tmp, qtd;
            cin >> tmp >> qtd;
            tmps[i] = tmp;
            qtds[i] = qtd;
        }

        int resp = mochila(n,p,tmps,qtds);
        cout << resp << " min." << endl;

        cin >> n;
    }

    return 0;
}