#include <iostream>
#include <vector>

using namespace std;

vector<int> resp;

int calcPeso(int wt[]) {
	int soma = 0;

	for(int i = 0; i < resp.size(); i++) {
		soma += wt[resp[i]-1];
	}
	return soma;
}

int max(int a, int b) { 
	return (a > b)? a : b; 
}  

int knapSack(int W, int wt[], int val[], int n) { 
	int i, w; 
	int K[n+1][W+1]; 
	int best[n+1][W+1];

	for(int i = 0; i < n+1; i++) {
		for(int j = 0; j < W+1; j++) {
			best[i][j] = 0;
		}
	}

	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i==0 || w==0) {
				K[i][w] = 0; 
				best[i][w] = 0;
			}
			else if (wt[i-1] <= w) 
				if(K[i-1][w] < val[i-1] + K[i-1][w-wt[i-1]]) {
					K[i][w] = val[i-1] + K[i-1][w-wt[i-1]];
					best[i][w] = i;
				} else {
					K[i][w] = K[i-1][w];
					//best[i][w] = best[i-1][w];
				} 
				else
					K[i][w] = K[i-1][w]; 
		} 
	} 

	resp.push_back(best[n][W]);

	int l = n-1;
	int peso = wt[best[n][W]-1];
	int c = w - peso;

	while(l > 0) {
		if(best[l][c] != 0) { 
			resp.push_back(best[l][c]);
			peso = wt[best[l][c]-1];
			c = c - peso;
			l--;
		} else {
			l--;
		}
	}

	return K[n][W]; 
}

// Driver code  
int main() {  
	int n;
	int W = 50;
	cin >> n;

	for(int cases = 0; cases < n; cases++) {
		resp.clear();
		int numP;
		cin >> numP;

		int val[numP];
		int wt[numP];

		for(int i = 0; i < numP; i++) {
			int qt, peso;
			cin >> qt >> peso;
			val[i] = qt;
			wt[i] = peso;
		}

		int tam = sizeof(val)/sizeof(val[0]);
		cout << knapSack(50, wt, val, tam);  
		cout << " brinquedos" << endl;
		cout << "Peso: ";
		cout << calcPeso(wt);
		cout << " kg" << endl;
		cout << "sobra(m) ";
		cout << numP - resp.size();
		cout << " pacote(s)" << endl << endl;


	}

	return 0;  
}
