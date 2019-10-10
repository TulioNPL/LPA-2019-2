class Grafo:
    def __init__(self, vertices):
        self.nVer = vertices
        self.grafo = []

    def addAresta(self,u,v,peso):
        """Adiciona uma aresta no grafo"""
        self.grafo.append([u,v,peso])

    def findSet(self, pai, i):
        """Acha o set do vertice i"""
        if pai[i] == i:
            return i
        return self.findSet(pai,pai[i])

    def union(self, a, b, nivel, pai):
        """Une dois subgrafos"""

        raizA = self.findSet(pai,a)
        raizB = self.findSet(pai,b)

        if nivel[raizA] < nivel[raizB]:
            pai[raizA] = raizB
        elif nivel[raizA] > nivel[raizB]:
            pai[raizB] = raizA
        else:
            pai[raizB] = raizA
            nivel[raizA] += 1

    def kruskal(self):
        """Encontra a soma das arestas da AGM"""
        AGM = []
        i = j = 0
        
        self.grafo = sorted(self.grafo,key=lambda item:item[2])

        pai = []
        nivel = []

        for vertice in range(self.nVer):
            pai.append(vertice)
            nivel.append(0)

        while j < self.nVer-1:
            u,v,w = self.grafo[i]
            i+=1
            a = self.findSet(pai,u)
            b = self.findSet(pai,v)

            if a!=b:
                j+=1
                AGM.append([u,v,w])
                self.union(a,b,nivel,pai)
        resp = 0
        for u,v,w in AGM:
            resp += w
        print('%.2f' % (resp/100))

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

    g.kruskal()
    c-=1

