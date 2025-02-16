#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Tarefa {
    int inicio, fim;
    Tarefa(int i, int f) : inicio(i), fim(f) {}
};

bool compararTarefas(Tarefa a, Tarefa b) {
    return a.fim < b.fim;
}

vector<Tarefa> escalonamentoTarefas(vector<Tarefa> &tarefas) {
    sort(tarefas.begin(), tarefas.end(), compararTarefas);
    vector<Tarefa> resultado;
    int ultimaFim = 0;
    for (auto &tarefa : tarefas) {
        if (tarefa.inicio >= ultimaFim) {
            resultado.push_back(tarefa);
            ultimaFim = tarefa.fim;
        }
    }
    return resultado;
}
