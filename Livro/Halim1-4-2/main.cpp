#include <bits/stdc++.h>
using namespace std;

void inputMethods() {
    int TC, a, b, c = 0;
    
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
    
    while (scanf("%d %d", &a, &b), (a || b)) {
        printf("%d\n", a + b);
    }
    
    while (scanf("%d %d", &a, &b) == 2) {
        printf("%d\n", a + b);
    }
    
    while (scanf("%d %d", &a, &b) != EOF) {
        if (c > 0) printf("\n"); 
        printf("Case %d: %d\n", ++c, a + b);
    }
}