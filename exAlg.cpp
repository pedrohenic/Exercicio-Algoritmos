#include <iostream>
#include <windows.h> // para usar portugues no console

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); // para usar portugues no console

    cout << fixed;     // para mostrar as médias com 2 casas decimais
    cout.precision(2); // para mostrar as médias com 2 casas decimais

    int totalAlunos;
    int maxAlunos = 5;
    float medias[maxAlunos];
    float notas[maxAlunos][3];
    string nomes[maxAlunos];

    while (true)
    {
        cout << "Quantos alunos você deseja cadastrar? ";
        cin >> totalAlunos;

        if (totalAlunos >= 1 && totalAlunos <= 5)
        {
            break;
        }
        cout << "Inválido, tente novamente \n";
    }

    string situacao[totalAlunos];
    int alunoMM = 0;

    for (int i = 0; i < totalAlunos; i++)
    {

        cout << "Digite o nome do aluno " << (i + 1) << ":";
        cin >> nomes[i];

        for (int l = 0; l < 3; l++)
        { // 3 = numero notas
            cout << "Digite a nota " << (l + 1) << ":";
            cin >> notas[i][l];
        }

        medias[i] = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;

        if (medias[i] >= 7.0f)
        {
            situacao[i] = "Aprovado!";
        }
        else
        {
            situacao[i] = "Reprovado.";
        }

        if (medias[i] > medias[alunoMM])
        {
            alunoMM = i;
        }
    }

    cout << "Aluno      Nota 1  Nota 2  Nota 3  Média    Situação \n";

    for (int i = 0; i < totalAlunos; i++)
    {
        cout << nomes[i] << "       " << notas[i][0] << "   " << notas[i][1] << "   " << notas[i][2] << "   " << medias[i] << "     " << situacao[i] << endl;
    } // caro professor, eu tentei organizar a tabela, mas não consegui deixar tudo alinhado, desculpe. (ia sugeriu esse texto, enquanto falava em voz alta oque qria escrever).

    cout << "O aluno com a maior média é: " << nomes[alunoMM] << " com média " << medias[alunoMM] << endl;

    return 0;
}
