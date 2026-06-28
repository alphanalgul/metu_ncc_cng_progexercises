#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double uniform() {
    return ((double)rand() + 1.0) / ((double)RAND_MAX + 2.0);
}

int main() {
    srand(time(NULL));
    double p = 0.6;
    int coins[200];
    int num_heads = 0;
    int num_tails = 0;
    double u;
    for (int i = 0; i < 200; i++) {
        u = uniform();
        if ( u <= p) {
            coins[i] = 1;
            num_heads++;
        }
        else {
            coins[i] = 0;
            num_tails++;
        }
    }

    printf("\nTotal Number of Heads: %d",num_heads);
    printf("\nTotal Number of Tails: %d",num_tails);
    printf("\nProportion of Heads: %.3f",(double)num_heads / 200);

    printf("\nTheoretical Mean: %.3f",p);
    printf("\nTheoretical Variance: %.3f",p*(1-p));

    double e = 0,e_squared = 0,v;
    for (int i = 0; i <200; i++) {
        e += coins[i];
    }
    e /= 200;

    for (int i = 0; i <200; i++) {
        e_squared += coins[i] * coins[i];
    }
    e_squared /= 200;

    v = e_squared - (e * e);

    printf("\nSample Mean: %.3f",e);
    printf("\nSample Variance: %.3f",v);
}