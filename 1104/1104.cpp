// 1104.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int qtdeCartasAlice, qtdeCartasBeatriz;

	cin >> qtdeCartasAlice >> qtdeCartasBeatriz;

	while (qtdeCartasAlice != 0 || qtdeCartasBeatriz != 0)
	{
		int cartasUnicasAlice[100001] = { 0 };
		int cartasUnicasBeatriz[100001] = { 0 };
		int qtdeCartasUnicasAlice = 0;
		int qtdeCartasUnicasBeatriz = 0;
		int cartasTrocadas = 0;

		for (int i = 0; i < qtdeCartasAlice; i++)
		{
			int value;
			cin >> value;

			if (cartasUnicasAlice[value] == 0)
			{
				cartasUnicasAlice[value] = 1;
				qtdeCartasUnicasAlice++;
			}
		}

		for (int i = 0; i < qtdeCartasBeatriz; i++)
		{
			int value;
			cin >> value;

			if (cartasUnicasBeatriz[value] == 0)
			{
				cartasUnicasBeatriz[value] = 1;
				qtdeCartasUnicasBeatriz++;
			}
		}

		cartasTrocadas = qtdeCartasUnicasAlice;

		if (qtdeCartasUnicasAlice > qtdeCartasUnicasBeatriz)
			cartasTrocadas = qtdeCartasUnicasBeatriz;

		for (int i = 0; i < 100001; i++)
		{
			if (cartasUnicasBeatriz[i] == 1 && cartasUnicasAlice[i])
				cartasTrocadas--;
		}
		
		cout << cartasTrocadas << "\n";

		cin >> qtdeCartasAlice >> qtdeCartasBeatriz;
	}
}