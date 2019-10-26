from collections import defaultdict 
  
class Grafo(): 
    def __init__(self,vertices): 
        self.grafo = defaultdict(list) 
        self.V = vertices 
  
    def addEdge(self,u,v): 
        self.grafo[u].append(v) 
  
    def temCicloUtil(self, v, visitado, pilha): 

        visitado[v] = True
        pilha[v] = True

        for vizinho in self.grafo[v]: 
            if visitado[vizinho] == False: 
                if self.temCicloUtil(vizinho, visitado, pilha) == True: 
                    return True
            elif pilha[vizinho] == True: 
                return True

        pilha[v] = False
        return False
  
    def temCiclo(self): 
        visitado = [False] * self.V 
        pilha = [False] * self.V 
        for no in range(self.V): 
            if visitado[no] == False: 
                if self.temCicloUtil(no,visitado,pilha) == True: 
                    return True
        return False

#main
K,W = map(int, input().split())
while (K+W) != 0:
    if W != 0:
        g = Grafo(K)

        for i in range(0,W):
            A,B = map(int, input().split())
            A-=1
            B-=1
            g.addEdge(A,B)
            g.addEdge(B,A)

        #Se tiver ciclo no grafo, nao eh possivel realizar o desejo das criancas
        if g.temCiclo() == True:
            #Caso o numero de criancas seja menor que quatro ou
            #O numero de desejos seja menor que dois
            #Certamente sera sempre possivel realizar os desejos das criancas
            if W > 2 and K > 3:
                print("N")
            else:
                print("Y")
        else:
            print("Y")
    else:
        print("Y")
    K,W = map(int, input().split())
    
