
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <iostream>

using namespace std;


//Não recursivo
int algoritmo_euclides(int a, int b) {

    int r = a % b;

    while(r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int MMC(int a, int b) {
    return (a * b) / algoritmo_euclides(a, b);
}

//Recursivo
int MDC(int a, int b) {

    if (b == 0) {
        return a;
    }

    return MDC(b, a % b);
}   

int main() {
    int a, b;
    cin >> a >> b;

    int mdc = MDC(a, b);

    printf("MDC: %d\n", mdc);
    printf("MMC: %d\n", MMC(a, b));

    return 0;
}
