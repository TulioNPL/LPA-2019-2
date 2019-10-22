n, m = map(int, input().split())
while n+m != 0:
	grafo = [] #LISTA DE ARESTAS

	for iterator in range(0,m):
		i, j, h = map(int, input().split())
		grafo.append((i,j,h))
		KruskalMST(grafo,n)
	k = int(input())

	for iterator in range(0,k):
		i, j = map(int, input().split())
		#Pegar menor caminho entre cada par de vertices i e j

	n, m = map(int, input().split())


