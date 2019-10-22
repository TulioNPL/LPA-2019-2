import sys 
  
class Graph(): 
  
    def __init__(self, vertices): 
        self.V = vertices 
        self.graph = [[0 for column in range(vertices)]  
                      for row in range(vertices)] 
  
    def printSolution(self, dist,sink): 
        print(dist[sink])
  
    def minDistance(self, dist, sptSet): 
  
        min = sys.maxsize 
  
        for v in range(self.V): 
            if dist[v] < min and sptSet[v] == False: 
                min = dist[v] 
                min_index = v 
  
        return min_index 
  
    def dijkstra(self, src, sink): 
  
        dist = [sys.maxsize] * self.V 
        dist[src] = 0
        sptSet = [False] * self.V 
  
        for cout in range(self.V): 
  
            u = self.minDistance(dist, sptSet) 
  
            sptSet[u] = True
  
            for v in range(self.V): 
                if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]: 
                        dist[v] = dist[u] + self.graph[u][v] 
  
        self.printSolution(dist,sink)
        print(dist)

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

	k = int(input())
	for iterator in range(0,k):
		i, j = map(int, input().split())
		g.dijkstra(i-1,j-1)

	n, m = map(int, input().split())
	count+=1
