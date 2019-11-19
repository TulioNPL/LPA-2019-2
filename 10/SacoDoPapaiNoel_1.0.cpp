#include <iostream>
#include <math.h>

using namespace std;

int pesoFinal;
int qtdFinal;
int qtdUsados;

void convertePraBits(int num, int numPac, int bitmask[]) {
	//int bitmask[numPac];

	for(int i = 0; i < numPac; i++) {
		bitmask[i] = (num >> i) & 1;
	}
}

void forcaBruta(int numPac, int pesos[], int qtds[]) {
	int numPossib = pow(2,numPac); //representa as possibilidades de combinacoes de pacotes

	for(int i = 0; i < numPossib; i++) {
		int bitMask[numPac];
		convertePraBits(i, numPac, bitMask);
		
		int pesoParcial = 0; 
		int qtdParcial = 0;
		int qtdUsadosParcial = 0;
		for(int j = 0; j < numPac; j++) {

			if(bitMask[j] == 1) {
				pesoParcial += pesos[j];
				qtdParcial += qtds[j];
				qtdUsadosParcial++;
			}
		}

		if(qtdParcial > qtdFinal && pesoParcial < 50){
			qtdFinal = qtdParcial;
			pesoFinal = pesoParcial;
			qtdUsados = qtdUsadosParcial;
		}
			
	}
}

int main() {
	int numTestes;
	cin >> numTestes;

	for(int i = 0; i < numTestes; i++) {
		qtdFinal = 0;
		pesoFinal = 0;

		int numPac;
		cin >> numPac;
		
		int pesos[numPac], qtds[numPac];
		for(int j = 0; j < numPac; j++) {
			int qtd, peso;
			cin >> qtd >> peso;
			pesos[j] = peso;
			qtds[j] = qtd;

		}
		forcaBruta(numPac,pesos,qtds);

		cout << qtdFinal << " brinquedo(s)" << endl << "Peso: " << pesoFinal << " kg" << endl << "sobra(m) " << numPac-qtdUsados << " pacote(s)" << endl << endl;
	}	

	return 0;
}
