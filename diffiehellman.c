#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
 
int prime(int num) {
    int i = 0, j = 0;
    for (i = 2; i < num/2; ++i)
        if (num % i == 0)
            return 0;
    return 1;
}
 
int mod(int base, int expo, int num) {
    int res = 1;
    int i;
    for (i = 1; i <= expo; ++i)
        res = (res * base) % num;
    return res;
}
 
int main() {
    int p, g, a, b, i, j, r1, r2, k1, k2, k3;
    srand(time(NULL));
    p:
        printf("\nEnter values of p & g: or comment this line to take random input ");
        scanf("%d %d", &p, &g);
 
    if (!prime(p) || !prime(g)) {
        printf("\nNumbers are not prime... Enter again...");
        goto p;
    } else {
        srand(time(NULL));
        a = rand() % 50;
        b = rand() % 50;
        printf("\nRandom nos chosen at two ends  : %d %d", a, b);
        r1 = mod(g, a, p); // g^b mod p
        r2 = mod(g, b, p); // g^a mod p
        printf("\nR1 = %d\nR2 = %d\n", r1, r2);
        k1 = mod(r2, a, p); // r2^a mod p
        k2 = mod(r1, b, p); // r1^b mod p
        printf("\nKey1: %d", k1);
        printf("\nKey2: %d", k2);
        k3 = mod(g, a * b, p); // g^a*b mod p
        printf("\nKey3: %d\n", k3);
    }
}
