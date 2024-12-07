#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{   while(true)
    {
        int N, M, A, B;
        cin >> N >> M;   //N Linha M Coluna
        if(N == 0 && M == 0)break;
        vector<string> DesenhoOriginal(N);
        for(int i= 0; i < N; i++){
            cin >> DesenhoOriginal[i];
        }
        cin >> A >> B; //desenho user

        int linha = A/N;
        int coluna = B/M;

        vector<string> DesenhoRedimensionado(A);
        for(int i =0; i< N; i++){
            string LinhaExpandida = "";
            for(char c: DesenhoOriginal[i]){
                LinhaExpandida += string(coluna, c); 
            }
            for(int j = 0; j < linha; j++){
                DesenhoRedimensionado[i * linha + j] = LinhaExpandida;
            }
        }

        for(const string & row: DesenhoRedimensionado){
            cout << row << endl;
        }
        cout << endl;   
    }
    return 0;
}
