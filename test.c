#include <stdio.h>

void complexFunction(int n) {
    int i, j, k;
    
    // First loop: O(N)
    for (i = 1; i <= n; i++) {
        
        // Nested loop: O(N)
        for (j = 1; j <= n; j++) {
            
            // Logarithmic loop: O(log N)
            for (k = 1; k <= n; k *= 2) {
                printf("i=%d, j=%d, k=%d\n", i, j, k);
            }
        }
    }
}

int main() {
    int n = 10;
    complexFunction(n);
    return 0;
}
