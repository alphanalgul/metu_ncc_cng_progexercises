#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform() {
    return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}

int bernoulli(double p) {
    double u = uniform();
    if ( u <= p) {
        return 1;
    }
    else {
        return 0;
    }
}
int main(void) {
    double p = 0.15;
    int num_trials = 0;
    int experiments[150];
    int total_trials = 0;
    for (int i = 0; i < 150; i++) {
        int faulty_check = 0;
        while (faulty_check==0) {
            int result = bernoulli(p);
            if (result == 1) {
                faulty_check = 1;
            }
            num_trials++;
        }
        printf("\nNumber of Trials required until the first faulty sensor is found for Exp"
               "eriment %d: %d",i+1,num_trials);
        experiments[i] = num_trials;
        total_trials += num_trials;
        num_trials = 0;
    }
    printf("\nTotal Number of Trials: %d",total_trials);
    printf("\nAverage Number of Trials Before Success: %.3f",(double)total_trials / 150);

    double e = 0,e_squared = 0,variance;
    for (int i = 0; i < 150; i++) {
        e += experiments[i];
    }
    e /= 150;

    for (int i = 0; i < 150; i++) {
        e_squared += experiments[i] * experiments[i];
    }
    e_squared /= 150;

    variance = e_squared - (e*e);

    printf("\nSample Mean: %.3f",e);
    printf("\nSample Variance: %.3f",variance);
}