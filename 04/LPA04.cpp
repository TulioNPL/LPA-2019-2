#include <iostream>
using namespace std;

string trim(string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

string rmWhiteSpaces(string& str) {
    string nova = "";

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
            if(linhas[i].size() > maiorString) maiorString = linhas[i].size();
        }
        cout << maiorString << endl;
        
        for(int i = 0; i < N; i++){
            cout << linhas[i] << endl;
        }
        cout << endl;
        cin >> N;
    }
}
