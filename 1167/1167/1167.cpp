// 1167.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    while (n > 0)
    {
        vector<string> names(n);
        vector<int> chips(n);

        for (int i = 0; i < n; i++)
        {
            string name;
            int chipValue; 

            cin >> name >> chipValue;

            names[i] = name;
            chips[i] = chipValue;
        }

        int currentIndex = 0;
        int currentValue = chips[0];
        int remaining = names.size();

        while (remaining > 1)
        {
            int flow = 0;

            if (currentValue % 2 == 1) flow = 1;
            else flow = 0;

            for (int i = 0; i < currentValue; i++)
            {
                if (flow == 1) 
                    currentIndex++;
                else 
                    currentIndex--;

                if (currentIndex < 0)
                {
                    currentIndex = names.size() - 1;
                }

                if (currentIndex >= names.size())
                {
                    currentIndex = 0;
                }

                if (names[currentIndex] == "")
                    i--;
            }

            currentValue = chips[currentIndex];

            names[currentIndex] = "";
            chips[currentIndex] = 0;

            remaining--;
        }

        int count = 0;

        while (names[count] == "")
            count++;

        cout << "Vencedor(a): " << names[count] << '\n';
        
        cin >> n;
    }
}