#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    vector<double> input;
    string str;
  
    do{
        double entrada;
       
        ostringstream strs;

        cin >> entrada;
        input.push_back(entrada);

        strs << entrada;
        str = strs.str();
    }while(str.compare("0") != 0);

    for(auto i = input.begin(); i != input.end(); i++) {
        printf("%.2f\n", *i);
    }

    return 0;
}