#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int maxand=0;
    int maxor = 0;
    int maxxor = 0;
    
    for(int a=1; a<=n; a++) {
        for(int b=1; b<=n; b++) {
            if(b==a)
                continue;
            
            int ra = (a & b);
            int ro = (a | b);
            int rxor = (a ^ b);
            
            if((ra < k) && (ra > maxand))
                maxand = ra;
            if((ro < k) && (ro > maxor))
                maxor = ro;
            if((rxor < k) && (rxor > maxxor))
                maxxor = rxor;
        }
    }
    
    printf("%d\n", maxand);
    printf("%d\n", maxor);
    printf("%d\n", maxxor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
