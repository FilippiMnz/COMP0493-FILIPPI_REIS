#include <iostream> 
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

//definir a quantidade de vertices
//para um grafo de 4 Vertices

#define V 4

bool aumentante(int grafoResidual[V][V], int u, int t, int parent[], bool jaVisto[]){
    jaVisto[u] = true;
    if(u == t) return true;

    for(int v =0 ; v < V; v++){
        if(!jaVisto[v] && grafoResidual[u][v] > 0 ){
            parent[v] = u;
            if(aumentante(grafoResidual, v, t, parent, jaVisto)) return true;
        }
    }
    return false;
}

int fordFulkerson(int grafo[V][V], int s, int t){
    int grafoResidual[V][V];
    memcpy(grafoResidual, grafo, sizeof(grafoResidual));

    int fMax = 0;
    int parent[V];


    while(true){
        bool jaVisto[V] = {false};

        if(!aumentante(grafoResidual, s, t, parent, jaVisto)) break;
        //veriicar fluxo maximo pelo caminho
        int fluxoCaminho = INT_MAX;
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            fluxoCaminho= min(fluxoCaminho, grafoResidual[u][v]);
        }

        //Atualizar o grafo

        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            grafoResidual[u][v] -= fluxoCaminho;
            grafoResidual[v][u] += fluxoCaminho;
        }

        fMax += fluxoCaminho; //acumular o Fluxo Total
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

    cout << "Fluxo Maximo: " << fordFulkerson(grafo, 0, 3) << endl;
    return 0;
}