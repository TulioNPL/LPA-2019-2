#include <iostream>
#include<list>
using namespace std;

class Grafo {
    int V; //qtd de vértices
    list <int> *adj; //ponteiro para um vetor contendo lista de adjacencia
    bool DFSutil(int v, bool visited[], int w);
    bool DFS(int v, int w);
    public:
    Grafo(int v); //contrutor
    void addAresta(int v, int a); //Adiciona aresta
    bool DFS(); //chama a busca em profundidade

};

Grafo::Grafo(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Grafo::addAresta(int v, int a){
    adj[v].push_back(a); // add para a lista de V
}

//Verifica se ha caminho entre v e w
bool Grafo::DFSutil(int v, bool visited[], int w) {
    bool temCaminho = false;
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); !temCaminho && i != adj[v].end(); i++) {
        if(!visited[*i]){
            temCaminho = DFSutil(*i, visited, w);
        }
        if(*i == w) {
            temCaminho = true; 
        }
    }
    return temCaminho;
}

//Reinicia os valores da busca a cada novo par de vertices
bool Grafo::DFS(int v, int w) {
    bool temCaminho = true;

    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) visited[i] = false;

    temCaminho = DFSutil(v, visited, w);

    return temCaminho;
}

//Chama a busca em profudidade para cada par de vertices
bool Grafo::DFS() {
    bool ehConexo = true;

    for(int v = 0; v < V; v++) {
        for(int w = 0; w < V; w++) {
            if(v != w)
                if(!DFS(v,w) || !DFS(w,v)) ehConexo = false;    
        }
    }
   
    return ehConexo;
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
                g.addAresta(v-1,w-1);
                g.addAresta(w-1,v-1);
            } else {
                g.addAresta(v-1,w-1);
            }
        }

        if(g.DFS()) cout << "1" << endl;
        else cout << "0" << endl;

        cin >> N >> M;
    }  
    return 0;
}