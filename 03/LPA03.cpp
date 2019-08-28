#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int N, M;
        cin >> N;
        cin >> M;

        int matrix[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) matrix[i][j] = 0;

        for(int i = 0; i < N; i++) { 
            for(int j = 0; j < N; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        for(int i = 0; i < M; i++) {
            int a,b;
            cin >> a;
            cin >> b;
            matrix[a-1][b-1] = 1;
        }

        for(int i = 0; i < N; i++) { 
            for(int j = 0; j < N; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}