#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int mdc(int a, int b) {
    if (a > b) return mdc(b, a - b);
    if (a == b) return a;
    return mdc(b, a);
}

int main() {
    string entrada;
    while (getline(cin, entrada)) {
        stringstream ss(entrada);
        vector<int> num;
        int temp;
        
        while (ss >> temp) {
            num.push_back(temp);
        }
        
        sort(num.begin(), num.end());
        int cateto1 = num[0], cateto2 = num[1], hipotenusa = num[2];
        
        if (pow(cateto1, 2) + pow(cateto2, 2) != pow(hipotenusa, 2)) {
            cout << "tripla" << endl;
        } else if (mdc(mdc(cateto1, cateto2), hipotenusa) == 1) {
            cout << "tripla pitagorica primitiva" << endl;
        } else {
            cout << "tripla pitagorica" << endl;
        }
    }
    return 0;
}
