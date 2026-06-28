#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform() {
    return ((double) rand() + 1.0) / ((double) RAND_MAX + 2.0);
}
int main(void) {
    srand(time(NULL));
    double p = 0.8;
    int packets[200];
    double u;
    int num_successes;
    int max_successes = 0;
    int min_successes = 0;
    int total_successes = 0;

    for (int i = 0; i <200; i++) {
        num_successes = 0;
        for (int j = 0; j <10; j++) {
            u = uniform();
            if (u <= p) {
                num_successes++;
            }
        }

        packets[i] = num_successes;
        total_successes += num_successes;

        if (num_successes>max_successes) {
            max_successes = num_successes;
        }
        if (min_successes == 0) {
            min_successes = num_successes;
        }
        if (num_successes < min_successes) {
            min_successes = num_successes;
        }

        printf("\nRound %d Successes: %d",i+1,num_successes);
    }

    printf("\nTotal Number of Successes: %d",total_successes);
    printf("\nMaximum Number of Successes in a Single Round: %d",max_successes);
    printf("\nMinimum Number of Successes in a Single Round: %d",min_successes);
    printf("\nSuccess Percentage: %.3f",(double)total_successes / 2000);

    double e = 0,e_squared = 0,v;
    for (int i = 0; i < 200; i++) {
        e += packets[i];
    }
    e /= 200;

    for (int i = 0; i < 200; i++) {
        e_squared += packets[i] * packets[i];
    }

    e_squared /= 200;

    v = e_squared - (e*e);

    printf("\nSample Mean: %.3f",e);
    printf("\nSample Variance: %.3f",v);

}