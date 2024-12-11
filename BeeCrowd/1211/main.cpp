#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    while (getline(cin, input)) {
        int n = stoi(input);
        vector<string> phonebook(n);

        for (int i = 0; i < n; i++) {
            getline(cin, phonebook[i]);
        }

        sort(phonebook.begin(), phonebook.end());

        string base = phonebook[0];
        int l = base.length();
        int maximum = 0;

        for (int i = 1; i < n; i++) {
            string c = phonebook[i];
            for (int j = 0; j < l; j++) {
                if (base[j] == c[j]) {
                    maximum++;
                } else {
                    break;
                }
            }
            base = c;
        }

        cout << maximum << "\n";
    }

    return 0;
}