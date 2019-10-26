import sys

INF = sys.maxsize

class Grafo:
    def __init__(self,vertices):
        self.numV = vertices
        self.grafo = []

    def addAresta(self,u,v,w):
        self.grafo.append([u,v,w])

    def findSet(self,pais,i):
        if pais[i] == i:
            return i
        return self.findSet(pais,pais[i])

    def union(self, pais, rank, x, y):
        raizx = self.findSet(pais, x)
        raizy = self.findSet(pais,y)

        if rank[raizx] < rank[raizy]:
            pais[raizx] = raizy
        elif rank[raizx] > rank[raizy]:
            pais[raizy] = raizx
        else:
            pais[raizy] = raizx
            rank[raizx] += 1

    def kruskal(self):
        resultado = []

        i=0
        e=0
        self.grafo = sorted(self.grafo,key=lambda item: item[2])

        pai = [] ; rank = []

        for no in range(self.numV):
            pai.append(no)
            rank.append(0)

        while e < self.numV-1:
            u,v,w = self.grafo[i]
            i+=1
            x = self.findSet(pai,u)
            y = self.findSet(pai,v)

            if x!=y:
                e+=1
                resultado.append([u,v,w])
                self.union(pai,rank,x,y)
        
        return resultado

def organizaArestas(MST):

    if MST[0][0] < MST[0][1]:
        MST[0][0],MST[0][1] = MST[0][1],MST[0][0]

    u = MST[0][0]
    v = MST[0][1]

    for i in range(1,len(MST)):
        if(MST[i][0] != v):
            MST[i][0],MST[i][1] = MST[i][1],MST[i][0]

    return MST

    

def econTempoMax(MST, V, maxDist, maxUso, A):
    resultado = 0
    caminhos = []
    caminho = []
    caminho.append(MST[0])

    for u,v,w in MST:
        if u < A:
            caminho.append([u,v,w])
        else:
            caminhos.append(caminho)

    for caminho in caminhos:
        print(caminho)

    return resultado


#Driver
T = int(input())
while T > 0:
    A,B,M,L,K = map(int, input().split())
    g = Grafo(A+B)

    for i in range(0,M):
        Xi,Yi,Li = map(int, input().split())
        g.addAresta(Xi-1,Yi-1,Li)

    #Pega a AGM
    MST = g.kruskal()
    newMST = sorted(MST,key=lambda item:(item[1],item[0]),reverse=True)
    newMST = organizaArestas(newMST)

    tempo = 0
    for u,v,w in newMST:
        print("%d--%d       %d" %(u+1,v+1,w))
        tempo += w


    #Calcular a maior distancia que pode ser percorrida em um uso das botas
    #Calcular o tempo total - tempo economizado pelo uso das botas
    tempoFinal = tempo - econTempoMax(newMST, A+B,L,K, A)
    #print(str(tempoFinal))   
    #Printar resultado    
    T-=1