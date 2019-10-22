class Grafo():
    def __init__(self,vertices):
        self.numV = vertices
        self.grafo=[[0 for coluna in range(vertices)] for linha in range (vertices)]
    
    def taSafe(self, v, cor, c):
        """Retorna se é seguro colocar a cor C no vértice V"""
        for i in range(self.numV):
            if self.grafo[v][i] == 1 and cor[i] == c:
                return False
        return True

    def coloracaoUtil(self,corMax,cor,v):
        """Função recursiva, retorna se é possivel colorir um grafo com no maximo corMax cores"""
        if v == self.numV:
            return True

        for c in range(1,corMax+1):
            if self.taSafe(v,cor,c) == True:
                cor[v] = c
                if self.coloracaoUtil(corMax,cor,v+1) == True:
                    return True
                cor[v] = 0

    def coloracao(self,corMax):
        cor = [0] * self.numV
        print(cor)
        if self.coloracaoUtil(corMax,cor,0) == None:
            #print("N")
            return False
        #print("Y")
        print(cor[0])
        return True

K,W = map(int, input().split())

while (K+W) != 0:
    if W > 2:
        g = Grafo(K)
        for i in range(0,W):
            A,B = map(int, input().split())
            g.grafo[A-1][B-1] = 1
            g.grafo[B-1][A-1] = 1

        #print(g.grafo)
        g.coloracao(2)
    else:
        print("Y")
    K,W = map(int, input().split())
