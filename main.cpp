#include "bellman.h"
#include "tsp.h"

using namespace std;

int main(int argc, char *argv[])
{
    int G[20][20];
    ifstream fin("inputfile.txt");
    int n = 12;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            fin >> G[i][j];
        }
    }
    cout << "Matrix:" << endl;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << setw(6) << G[i][j];
        }
        cout << endl;
    }

    int BFValue[20];
    int BFPrev[20];
    memset(BFValue, -1, sizeof(BFValue));
    memset(BFPrev, -1, sizeof(BFPrev));
    // Bellman
    cout << endl;
    cout << "Bellman-Ford" << endl;
    for (int s = 0; s < n; s += 3)
    {
        cout << "From " << char('A' + s) << endl;
        for (int i = 0; i < 3; i++)
        {
            BF(G, n, s + 'A', BFValue, BFPrev);
            cout << "step" << i + 1 << ":" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << setw(4) << BFValue[j];
            }
            cout << endl;
            for (int j = 0; j < n; j++)
            {
                cout << setw(4) << BFPrev[j];
            }
            cout << endl;
        }
    }
    // Bellman-Ford Path
    cout << endl;
    cout << "Bellman-Ford Path" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << BF_Path(G, n, char(i + 'A'), char(j + 'A')) << endl;
        }
    }
    // The Travelling salesman problem
    cout << endl;
    cout << "The Travelling salesman problem" << endl;
    string output;
    for (int i = 0; i < n; i++)
    {
        output = Traveling(G, n, char(i + 'A'));
        cout << output << endl << endl;
    }
    cout << "You can change the input in inputfile.txt to get another output.";
    return 0;
}