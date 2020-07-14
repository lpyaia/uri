// 1578.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int n, matrizes = 0;

    cin >> n;

    while (matrizes < n)
    {
        int dim;
        cin >> dim;

        unsigned long long** quadrados = new unsigned long long* [dim];
        string** resultado = new string* [dim];

        for (int width = 0; width < dim; width++)
        {
            quadrados[width] = new unsigned long long[dim];
            resultado[width] = new string[dim];

            for (int height = 0; height < dim; height++)
            {
                unsigned long long value;
                cin >> value;

                quadrados[width][height] = value * value;
            }
        }

        for (int height = 0; height < dim; height++)
        {
            unsigned long long maior = quadrados[0][height];

            for (int width = 1; width < dim; width++)
            {
                if (quadrados[width][height] > maior)
                    maior = quadrados[width][height];
            }

            int qtDigitosMaior = to_string(maior).length();

            for (int width = 0; width < dim; width++)
            {
                int qtDigitos = to_string(quadrados[width][height]).length();
                int espacos = qtDigitosMaior - qtDigitos;
                
                string s = to_string(quadrados[width][height]);
                s.insert(s.begin(), qtDigitosMaior - s.length(), ' ');

                resultado[width][height] = s;
            }
        }

        cout << "Quadrado da matriz #" << (++matrizes) + 3 << ":\n";

        for (int width = 0; width < dim; width++)
        {
            for (int height = 0; height < dim; height++)
            {
                cout << resultado[width][height];

                if (height < dim - 1)
                    cout << " ";
            }

            cout << "\n";
        }

        if(matrizes < n)
            cout << "\n";
    }
}