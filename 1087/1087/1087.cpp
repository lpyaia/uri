// 1087.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int x1 = 1, y1 = 1, x2 = 1, y2 = 1;

    while (true)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) 
            break;
        
        int xt = abs(x1 - x2);
        int yt = abs(y1 - y2);
        
        if (xt == 0 && yt == 0)
            cout << '0' << '\n';
        else if (yt == 0 || xt == 0)
            cout << '1' << '\n';
        else if (xt == yt)
            cout << '1' << '\n';
        else
            cout << '2' << '\n';
    }
}