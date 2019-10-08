class Grafo:
    def __init__(self, vertices):
        self.nVer = vertices
        self.grafo = {i: [] for i in range(n)}

    def addAresta(self,u,v,peso):
        """Adiciona uma aresta no grafo"""
        self.grafo.append([u,v,peso])
    def kruskal():
        """Acha a árvore geradora mínima"""


def calcDist(a,b):
    x1 = a[0]
    y1 = a[1]
    x2 = b[0]
    y2 = b[1]
    
    dist = ((x2-x1)**2 + (y2-y1)**2)**(1/2)
    return dist

c = int(input())

while c > 0:
    n = int(input())
    coord = []
    g = Grafo(n)

    cont = 0
    while cont < n:
        x, y = map(int, input().split())
        coord.append((x,y))
        cont+=1

    for i in range(n):
        for j in range(n):
            if i != j:
                dist = calcDist(coord[i],coord[j])
                g.addAresta(i,j,dist)

    #Calcular as distâncias e usá-las com peso na árvore

    #Usar kruskal para achar a árvore geradora mínima

    #Somar os valores das arestas da AGM e printar com precisao de 2 casas decimais
    
    c-=1

