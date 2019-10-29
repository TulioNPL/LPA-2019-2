from collections import defaultdict 
class Grafo: 
	def __init__(self, vertices): 
		self.V = vertices
		self.grafo = defaultdict(list) 
  
	def addEdge(self, u, v): 
		self.grafo[u].append(v)
		self.grafo[v].append(u)
  
	def DFSUtil(self, v, visited): 
		visited[v] = True

		for i in self.grafo[v]: 
			if visited[i] == False: 
				self.DFSUtil(i, visited) 

	def DFS(self): 
		resp = -1
		visited = [False] * (self.V) 
		for i in range(self.V):
			if visited[i] == False:
				resp+=1
				self.DFSUtil(i, visited) 


		return resp

T = int(input())
cont = 1
while (T>0):
	N = int(input())
	M = int(input())

	g = Grafo(N)
	for i in range(M):
		X,Y = map(int, input().split())
		g.addEdge(X-1,Y-1)

	faltam = 0
	if M != 0:
		faltam = g.DFS()
	else:
		faltam = N-1

	if faltam == 0:
		print("Caso #" + str(cont) + ": a promessa foi cumprida")
	else:
		print("Caso #" + str(cont) + ": ainda falta(m) " + str(faltam) + " estrada(s)")
	cont+=1
	T-=1