from collections import defaultdict
import sys

class Grafo():
    def __init__(self, vertices):
        self.grafo = defaultdict(list)
        self.pesos = {}
        self.matriz = [[sys.maxsize for i in range(vertices+1)] for j in range(vertices+1)]
    
    def addAresta(self, u, v, w):
        self.grafo[u].append(v)
        self.grafo[v].append(u)
        self.pesos[(u, v)] = w
        self.pesos[(v, u)] = w

    def addMatriz(self, u,v,w):
        self.matriz[u][v] = w
        self.matriz[v][u] = w

def djikstra(grafo, u, end):

    shortest_paths = {u: (None, 0)}
    atual = u
    visited = set()
    
    while atual != end:
        visited.add(atual)
        vertices = grafo.grafo[atual]
        pesoAtual = shortest_paths[atual][1]

        for prox in vertices:
            w = grafo.pesos[(atual, prox)] + pesoAtual
            if prox not in shortest_paths:
                shortest_paths[prox] = (atual, w)
            else:
                current_shortest_weight = shortest_paths[prox][1]
                if current_shortest_weight > w:
                    shortest_paths[prox] = (atual, w)
        
        next_destinations = {node: shortest_paths[node] for node in shortest_paths if node not in visited}
        if not next_destinations:
            return False

        atual = min(next_destinations, key=lambda k: next_destinations[k][1])
    
    path = []
    while atual is not None:
        path.append(atual)
        prox = shortest_paths[atual][0]
        atual = prox

    path = path[::-1]
    return path

def pegaTempo(resp,grafo):
    tempo = 0
    for i in range(0,len(resp)-1):
        tempo += grafo.matriz[int(resp[i])][int(resp[i+1])]
    return tempo

#Driver 
C,E = map(int, input().split())
while C+E != 0:
    g = Grafo(C)

    for i in range(E):
        A,B,W = map(int, input().split())
        g.addAresta(A,B,W)
        g.addMatriz(A,B,W)
    D = int(input())

    resp = djikstra(g,D,1)
    caminho = ''
    for no in resp:
        caminho += ' ' +  str(no)
    tempo = pegaTempo(resp,g)

    if(tempo < 120):
        print("Will not be late. Travel time - " + str(tempo) + " - best way -" + caminho)
    else:
        atraso = tempo - 120
        print("It will be " + str(atraso) + " minutes late. Travel time - " + str(tempo) + " - best way -"+ caminho)

    C,E = map(int, input().split())

