class Grafo:
    def __init__(self,vertices):
        self.V=vertices
        self.grafo = {i:[] for i in range(1,self.V+1)}
    
    def addEdge(self,u,v):
        """Adiciona arestas ao grafo(naoorientado)"""
        self.grafo[u].append(v)
        self.grafo[v].append(u)

    def DFSUtil(self, v,u,visited,caminho):
        """Retorna o numero de arestas de um caminho entre dois vertices"""
        soma = 0
        visited[v]= True
        caminho.append(v)
        if v==u:
            soma = len(caminho) -1
        else:
            for i in self.grafo[v]:
                if visited[i]==False:
                    soma += self.DFSUtil(i,u,visited,caminho)
        caminho.pop()
        visited[u] = False
        return soma

    def DFS(self, v, u):
        """Faz busca em profundidade no grafo entre dois pares de vertices"""
        visited =[False]*(len(self.grafo)+1)
        caminho=[]
        soma = self.DFSUtil(v,u,visited,caminho)
        return soma

#Driver
N = int(input())
C = list(map(int,input().split()))
g = Grafo(N)
for i in range(N-1):
    A,B = map(int, input().split())
    g.addEdge(A,B)

#faz a busca em profundidade entre dois pares de vertices
#Soma o tamanho dos caminhos entre todos pares de vertices com rotulo igual
soma = 0
for i in range(len(C)):
    for j in range(i,len(C)):
        if C[i] == C[j] and i!=j:
            soma += g.DFS(i+1,j+1)

print(soma)