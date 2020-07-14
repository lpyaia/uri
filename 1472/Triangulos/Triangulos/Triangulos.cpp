// Triangulos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    
    while (cin >> n)
    {
        vector<int> arcos(n);
        set<int> soma;

        for (int i = 0; i < n; i++)
            cin >> arcos[i];

        for (int i = 1; i < arcos.size(); i++)
        {
            int currentSum = arcos[i] + arcos[i - 1];
            arcos[i] = currentSum;
            soma.insert(currentSum);
        }

        int triangulos = 0;
        int somaTotal = arcos[arcos.size() - 1] / 3;

        for (int i = 0; i < n; i++)
        {
            int pt1 = arcos[i];
            int pt2 = pt1 + somaTotal;
            int pt3 = pt1 + 2 * somaTotal;

            if (soma.find(pt2) != soma.end() &&
                soma.find(pt3) != soma.end())
                triangulos++;
        }

        cout << triangulos << '\n';
    }
}
