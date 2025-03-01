#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    vector<string> a;
    string input;
    while (true) {
        getline(cin, input);
        stringstream ss(input);
        string temp;
        a.clear();
        while (ss >> temp) {
            a.push_back(temp);
        }
        
        if (a == vector<string>{"0", "0"}) break;
        
        string x = string(a[0].rbegin(), a[0].rend()) + "00000000";
        string y = string(a[1].rbegin(), a[1].rend()) + "00000000";
        
        int soma = 0, carry = 0;
        for (int i = 0; i < 9; i++) {
            int t = (x[i] - '0') + (y[i] - '0') + carry;
            carry = t / 10;
            soma += (carry > 0);
        }
        
        if (soma == 0) {
            cout << "No carry operation." << endl;
        } else if (soma == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << soma << " carry operations." << endl;
        }
    }
    return 0;
}
