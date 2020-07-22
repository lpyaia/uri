#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    double raio;

    scanf(" %lf", &raio);
    printf("VOLUME = %.3lf\n", (4.0 / 3) * 3.14159 * (raio * raio * raio));

    return 0;
}