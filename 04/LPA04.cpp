#include <iostream>
#include <iomanip>
using namespace std;

/*
Pega o substring para retirar os espacos em branco no inicio e no fim
*/
string trim(string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

/*
Remove os espacos em branco no meio da String
*/
string rmWhiteSpaces(string& str) {
    string nova = "";

    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            nova += str[i];
            while(str[i] == ' ') i++;
            nova += str[i];
        } else {
            nova += str[i];
        }
    }

    return nova;
}

int main(){
    int N; 
    string trash;

    cin >> N;
    while(N != 0) {
        string linhas[N];
        getline(cin,trash);
        int maiorString = 0;

        for(int i =0; i < N; i++) {
            getline(cin,linhas[i]);
            linhas[i] = trim(linhas[i]);
            linhas[i] = rmWhiteSpaces(linhas[i]);
            if(linhas[i].size() > maiorString) maiorString = linhas[i].size();  //salva o tamanho da maiorString
        }
        
        for(int i = 0; i < N; i++){
            cout << right << setw(maiorString) << linhas[i] << endl;
        }
        cout << endl;
        cin >> N;
    }
}
