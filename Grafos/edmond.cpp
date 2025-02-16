#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

//para 4 vertices
#define V 4
//aumentantes procurando o caminho mais curto
bool Aumentantes(int grafoResidual[V][V], int Fonte, int Sumi, int parent[]){
    bool jaVisto[V];
    memset(jaVisto, 0, sizeof(jaVisto));

    queue<int> fila;
    fila.push(Fonte);
    jaVisto[Fonte] = true;
    parent[Fonte] = -1;

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        for(int v =0; v < V; v++){
            if(!jaVisto[v] && grafoResidual[u][v] > 0){
                fila.push(v);
                parent[v] = u;
                jaVisto[v] = true;

                if(v == Sumi ) return true;
            }
        }
    }
    return false;
}

int Edmond(int grafo[V][V], int fonte, int Sumidouro){
    int u, v;
    int grafoResidual[V][V];

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            grafoResidual[u][v] = grafo[u][v];

    int parent[V];  
    int fMax = 0;  
    while (Aumentantes(grafoResidual, fonte,Sumidouro , parent)) { 
        int fluxoCaminho = INT_MAX;

        for (v = Sumidouro; v != fonte; v = parent[v]) {
            u = parent[v];
            fluxoCaminho = min(fluxoCaminho, grafoResidual[u][v]);
        }

        for (v = Sumidouro; v != fonte; v = parent[v]) {
            u = parent[v];
            grafoResidual[u][v] -= fluxoCaminho;
            grafoResidual[v][u] += fluxoCaminho; 
        }

        fMax += fluxoCaminho;
    }
    return fMax;
}


int main(){
    int grafo[V][V] = {
        {0, 15, 10, 0}, //Capacidade de S
        {0, 0, 20, 15}, //capaciadde de A
        {0, 0, 0, 10}, //Capacidade de B
        {0, 0, 0, 0}  //capacidade de T
    };

    cout << "Fluxo Maximo: " << Edmond(grafo, 0, 3) << endl;
    return 0;
}
