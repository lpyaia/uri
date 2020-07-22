// 1514.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector> 

using namespace std;

int main()
{
    int numParticipantes;
    int numProblemas;

    cin >> numParticipantes >> numProblemas;

    while (numParticipantes > 0 || numProblemas > 0)
    {
        int condicaoUm = 0;
        int condicaoDois = 1;
        int condicaoTres = 1;
        int condicaoQuatro = 1;
        int qtdePessoasNaoResolveramTodosOsProblemas = 0;
        vector<int> qtdePessoasResolveramOProblema(numProblemas, numParticipantes);

        for (int participante = 0; participante < numParticipantes; participante++)
        {
            bool naoResolveuTodosOsProblemas = false;
            int qtdeProblemasResolvidos = numProblemas;

            for (int problema = 0; problema < numProblemas; problema++)
            {
                int problemaResolvido;
                cin >> problemaResolvido;

                if (problemaResolvido == 0)
                {
                    naoResolveuTodosOsProblemas = true;
                    qtdePessoasResolveramOProblema[problema]--;
                    qtdeProblemasResolvidos--;
                }
            }

            if (naoResolveuTodosOsProblemas)
                qtdePessoasNaoResolveramTodosOsProblemas++;

            if (qtdeProblemasResolvidos == 0)
                condicaoQuatro = 0;
        }

        condicaoUm = qtdePessoasNaoResolveramTodosOsProblemas == numParticipantes ? 1 : 0;        

        for (int i = 0; i < numProblemas; i++)
        {
            if (qtdePessoasResolveramOProblema[i] == 0)
            {
                condicaoDois = 0;
            }

            if (qtdePessoasResolveramOProblema[i] == numParticipantes)
            {
                condicaoTres = 0;
            }
        }

        cout << (condicaoUm + condicaoDois + condicaoTres + condicaoQuatro) << "\n";

        cin >> numParticipantes >> numProblemas;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
