#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
#define INF INT_MAX

typedef vector<int> vi;

/*Algoritmo para resolver o problema das moedas*/
/*A solucao desse algoritmo eh analoga ao problema dos blocos*/
int moedas(int N, int M, int comp[]) {
    vi dp(M+1, INF); //vetor para guardar os valores ja calculados inicializado com INFINITO

    dp[0] = 0;
    for(int i = 1; i <= M; i++) { 
        for(int j = 1; j<= N; j++) {
            if(0 <= i - comp[j]){ //Se i - comprimento de J >= 0
                dp[i] = min(dp[i], dp[i-comp[j]] + 1);  //dp[i] assume o menor valor entre o obtido atualmente e entre dp[i-comp[j]]+1
            }
        }
    }

    return dp[M];
}

//Driver
int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;

        int comp[N]; //vetor com comprimentos dos blocos
        for(int j = 1; j <=N; j++) {
            cin >> comp[j];
        }

        int resp = moedas(N,M,comp);
        cout << resp << endl;

    }

    return 0;
}