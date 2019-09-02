#include<iostream>
#include<list>
using namespace std;

class Grafo { 
	int V;    // qtd de vertices 
	list<int> *adj;    // Ponteiro para um vetor contendo lista de adjacencia 
	int DFSUtil(int v, bool visited[], int numAmigos); 
	public: 
	Grafo(int V);   // Construtor 
	void addAresta(int v, int a);   // funcao para add aresta 
	void DFS();    // printa DFS 
}; 

Grafo::Grafo(int V) { 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Grafo::addAresta(int v, int a) { 
	adj[v].push_back(a); // Add a para a lista de V. 
} 

int Grafo::DFSUtil(int v, bool visitado[], int numAmigos) {  
	visitado[v] = true; 
    //cout << "numAmigos atual = " << numAmigos << endl;
 
	list<int>::iterator i; 
	for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		if(!visitado[*i]) 
			numAmigos = DFSUtil(*i, visitado,numAmigos+1);

    return numAmigos;
} 

void Grafo::DFS() {
    int maxAmigos = 0;

	// Seta todos vertices para nao visitados 
	bool *visitado = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visitado[i] = false; 

	for (int i = 0; i < V; i++) { 
        int numAmigos;
		if (visitado[i] == false) { 
			numAmigos = DFSUtil(i, visitado, 1);
            if(numAmigos > maxAmigos) maxAmigos = numAmigos;
		}
	} 
    cout << maxAmigos << endl;
} 

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int N, M;
        cin >> N;
        cin >> M;

        //cria a matriz de adjacencia e seta os valores para 0
        /* int matrix[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) matrix[i][j] = 0;
        */
        Grafo g(N);
        for(int i = 0; i < M; i++) {
            int a,b;
            cin >> a;
            cin >> b;
            //matrix[a-1][b-1] = 1;
            g.addAresta(a-1, b-1);
            g.addAresta(b-1, a-1);
        }

        /* for(int i = 0; i < N; i++) { 
            for(int j = 0; j < N; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        */
       g.DFS();
    }
    return 0;
}