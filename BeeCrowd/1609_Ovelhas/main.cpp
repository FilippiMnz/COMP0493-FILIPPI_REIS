/*
    BEE 1609 
    contando carneirinhos
    Entrada
    Na primeira linha você terá um inteiro T (T = 100*) indicando o número de casos de teste.
    Na primeira linha de cada caso teremos o número inteiro N (1 ≤ N ≤ 100* ou 1 ≤ N ≤ 104​**), indicando o número de carneirinhos. 
    Na próxima linha teremos N inteiros separados por espaço indicando a sequência de carneirinhos.
    Os identificadores dos carneiros irão de 0 até 109, inclusive.
    *Ocorre em aproximadamente 90% dos casos de teste;
    **Ocorre nos demais casos de teste.
    Saída
    Imprima o número de carneirinhos distintos para cada caso.
*/


#include <iostream>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
int main(){
    int T, N, O;
    cin >> T; //recebe numero de casos base
    cin.ignore();
    for(int i = 0; i < T; i++){
        cin >> N;
        cin.ignore();
        string Linha;
        getline(cin, Linha);
        istringstream ListaOve(Linha);
        set<int> Ovelhas;
        for(int j = 0; j < N; j++){
            ListaOve >> O;
            Ovelhas.insert(O);
        }       
        cout << Ovelhas.size() <<endl;
    }
    return 0;

}