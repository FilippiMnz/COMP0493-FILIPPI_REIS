#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <sstream>

using namespace std;

struct Car {
    int arrival, exit;
};

int n, k;
int frontIndex;
list<Car> cars;
priority_queue<int, vector<int>, greater<int>> firstOut;
stack<int> parking;

void coming(int exitTime) {
    parking.push(exitTime);
    firstOut.push(exitTime);
}

int main() {
    string input;
    while (getline(cin, input) && input != "0 0") {
        stringstream ss(input);
        ss >> n >> k;

        frontIndex = -1;
        cars.clear();
        firstOut = priority_queue<int, vector<int>, greater<int>>();
        parking = stack<int>();

        bool isPossible = true;
        int time = 1;

        for (int i = 0; i < n; ++i) {
            getline(cin, input);
            stringstream carStream(input);
            int arrival, exit;
            carStream >> arrival >> exit;

            if (arrival == time) {
                if (parking.size() == k) {
                    isPossible = false;
                    break;
                }
                coming(exit);
            } else {
                cars.push_back({arrival, exit});
            }
        }

        while (isPossible && (!cars.empty() || !parking.empty())) {
            if (!parking.empty() && time == firstOut.top()) {
                firstOut.pop();
                bool remove = false;
                while (!parking.empty() && parking.top() == time) {
                    parking.pop();
                    remove = true;
                }
                if (!remove) {
                    isPossible = false;
                    break;
                }
            }

            while (!cars.empty() && time == cars.front().arrival) {
                if (parking.size() == k) {
                    isPossible = false;
                    break;
                }
                coming(cars.front().exit);
                cars.pop_front();
            }
            ++time;
        }

        cout << (isPossible ? "Sim" : "Nao") << endl;
    }

    return 0;
}
