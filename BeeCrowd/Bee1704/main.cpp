#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    while (cin >> n >> h) {
        vector<pair<int, int>> tasks(n);
        int total = 0;

        for (int i = 0; i < n; ++i) {
            cin >> tasks[i].first >> tasks[i].second;
            total += tasks[i].first;
        }

        sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        vector<bool> time_slot(h, false);
        int max_value = 0;

        for (const auto& task : tasks) {
            for (int j = min(h, task.second) - 1; j >= 0; --j) {
                if (!time_slot[j]) {
                    time_slot[j] = true;
                    max_value += task.first;
                    break;
                }
            }
        }

        cout << (total - max_value) << "\n";
    }

    return 0;
}

