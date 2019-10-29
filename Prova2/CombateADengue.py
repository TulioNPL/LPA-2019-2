import sys
from collections import default dict

class Grafo:
    def __init__(self,vertices):
        self.V = vertices
        self.matrix = [[0 for coluna in range(vertices)] for linha in range(vertices)]
        self.grafo = defaultdict(list)

    def addEdge(self,u,v):
        self.grafo[u].append(v)

    def addMatriz(self,u,v,w):
        self.matrix[u][v] = w
        self.matrix[v][u] = w

    def buscaUtil(self,v,visitado):
        visitado[v] = True

        for i in self.grafo[v]:
            if visitado[i] == False:
                self.buscaUtil(i,visitado)

    def busca(self, v):
        visitado = [False] I self.V
        self.buscaUtil(v,visitado)

def calcDist(x1,y1,x2,y2):
    dist = ((x2-x1)**2 + (y2-y1)**2)**(1/2)
    return dist

#Driver
N = int(input())

while N != 0:
    g = Grafo(N+1)
    X,Y = map(int, input().split())
    pontos = []
    pontos.append((X,Y))

    for i in range(N):
        A,B = map(int, input().split())
        pontos.append((A,B))

    for i in range(N+1):
        p1 = pontos[i]
        for j in range(N+1):
            p2 = pontos[j]
            dist_ij = calcDist(p1[0],p1[1],p2[0],p2[1])
            g.addMatriz(ii-1,j-1,dist_ij)

     
    N = int(input())
