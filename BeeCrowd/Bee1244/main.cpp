#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void sortByLength(vector<string>& textList) {
    bool found;
    do {
        found = false;
        for (size_t i = 0; i < textList.size() - 1; ++i) {
            if (textList[i].length() < textList[i + 1].length()) {
                swap(textList[i], textList[i + 1]);
                found = true;
            }
        }
    } while (found);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        
        
        istringstream iss(line);
        vector<string> textList;
        string word;
        while (iss >> word) {
            textList.push_back(word);
        }

        
        sortByLength(textList);

        for (size_t j = 0; j < textList.size(); ++j) {
            cout << textList[j];
            if (j != textList.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

