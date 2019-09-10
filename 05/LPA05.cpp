#include <iostream>
#include<list>
using namespace std;

class Grafo {
    int v; //qtd de vértices
    list <int> *adj; //ponteiro para um vetor contendo lista de adjacencia
    void DFSutil(int v, bool visited[]);

    public:
    Grafo(int v); //contrutor
    void addAresta(int v, int a); //Adiciona aresta
    void DFS(); //chama a busca em profundidade

};

Grafo::Grafo(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Grafo::addAresta(int v, int a){
    adj[v].push_back(a); // add para a lista de V
}

void Grafo::DFSutil(int v, bool visited[]) {
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i]){
            DFSutil(*i, visited);
        }
    }
}

void Grafo::DFS() {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) visited[i] = false;
    
    for(int i = 0; i < v; i++){
        if(visited[i] == false){
            temCaminho = DFSutil(i, visited);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    while(N != 0 && M != 0) {
        Grafo g(N);
        for(int i = 0; i < M; i++) {
            int v, w, p;
            cin >> v >> w >> p;
         
            if(p == 2) {
                g.addAresta(v,w);
                g.addAresta(w,v);
            } else {
                g.addAresta(v,w);
            }
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                if(i != j) {
                    if(!g.DFS(i , j)) {
                        
                    }
                }
            }


        cin >> N >> M;
    }  
    return 0;
}