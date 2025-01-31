#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Component {
public:
    int id;
    char color; 
    vector<Component*> link;

    Component(int id) : id(id), color('W') {}

    void addLink(Component* component) {
        link.push_back(component);
    }
};

bool looping;

void DFS_findCycle(Component* c) {
    c->color = 'G';
    for (Component* child : c->link) {
        if (child->color == 'G') {
            looping = true;
            return;
        }
        if (child->color == 'W') {
            DFS_findCycle(child);
        }
    }
    c->color = 'B';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n, m, a, b;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        map<int, Component*> component;

        while (m--) {
            cin >> a >> b;
            if (a > n || b > n) continue;
            if (component.find(a) == component.end()) {
                component[a] = new Component(a);
            }
            if (component.find(b) == component.end()) {
                component[b] = new Component(b);
            }
            component[a]->addLink(component[b]);
        }

        looping = false;
        for (auto& entry : component) {
            if (entry.second->color == 'W') {
                DFS_findCycle(entry.second);
                if (looping) break;
            }
        }

        cout << (looping ? "SIM\n" : "NAO\n");

      
        for (auto& entry : component) {
            delete entry.second;
        }
    }

    return 0;
}

