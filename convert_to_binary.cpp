
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <iostream>

using namespace std;

void convert_to_binary(int n) {
    if (n == 0) {
        return;
    }
    convert_to_binary(n / 2);
    printf("%d", n % 2);
}

void convert_to_hexa(int n) {
    if (n == 0) {
        return;
    }
    convert_to_hexa(n / 6);
    printf("%d", n % 6);
}

// Função para converter diretamente de base 6 para base 2
string base6ParaBase2(const std::string& numeroBase6) {
    // Mapeamento dos dígitos de base 6 para binário
    std::unordered_map<char, std::string> mapaBase6ParaBase2 = {
        {'0', "000"}, {'1', "001"}, {'2', "010"}, 
        {'3', "011"}, {'4', "100"}, {'5', "101"}
    };

    string numeroBase2;
    for (char digito : numeroBase6) {
        numeroBase2 += mapaBase6ParaBase2[digito];
    }

    // Remove os zeros à esquerda
    numeroBase2.erase(0, numeroBase2.find_first_not_of('0'));

    return numeroBase2.empty() ? "0" : numeroBase2;
}

int main() {
    string n;
    cin >> n;

    //convert_to_hexa(n);
    //convert_to_binary(n);
    printf("%s\n", base6ParaBase2(n).c_str());  
}
