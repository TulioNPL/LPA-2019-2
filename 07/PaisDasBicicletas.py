import sys 

INF = sys.maxsize

class Graph(): 
    def __init__(self, vertices): 
        self.V = vertices 
        self.graph = [[INF for column in range(vertices)]  
                      for row in range(vertices)] #inicializa a matriz com todas as distancias infinitas
        for i in range(0,self.V):
            self.graph[i][i] = 0 #A distancia de um vertice para ele mesmo eh zero
    
    #Algoritmo de Floyd Warshall para encontrar o menor caminho entre todos os pares de vertices
    def floydWarshall(self): 
        dist = self.graph

        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j])) 
        return dist

#Driver
n, m = map(int, input().split())
count = 1
while n+m != 0:
    g = Graph(n)
    for iterator in range(0,m):
        i, j, h = map(int, input().split())
        g.graph[i-1][j-1] = h
        g.graph[j-1][i-1] = h

    print("Instancia " + str(count),end='\n')
    resp = g.floydWarshall() #calcula as respostas

    k = int(input())
    for iterator in range(0,k):
        i, j = map(int, input().split())
        print(str(resp[i-1][j-1]))  #printa as respostas
    print()

    n, m = map(int, input().split())
    count+=1