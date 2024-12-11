#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        int count = 0;
        bool incorrect = false;

        for (char now : line) {
            if (now == '(') {
                count++;
            } else if (now == ')') {
                if (count == 0) {
                    incorrect = true;
                    break;
                }
                count--;
            }
        }

        if (!incorrect && count == 0) {
            cout << "correct\n";
        } else {
            cout << "incorrect\n";
        }
    }

    return 0;
}
