#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform() {
    return ((double)rand() + 1.0)/((double)RAND_MAX+2.0);
}
int main(void) {
    srand(time(NULL));
    double lambda = 0.33;
    double repairs[120];
    double u,exponential;
    for (int i = 0; i <120; i++) {
        u = uniform();
        exponential = -(1/lambda)*log(u);
        repairs[i] = exponential;
        printf("\nRepair Time %d: %.3f",i+1,exponential);
    }

    double e=0,e_squared=0,variance;
    for (int i = 0; i <120; i++) {
        e += repairs[i];
    }
    e/=120;

    for (int i = 0; i <120; i++) {
        e_squared += repairs[i]*repairs[i];
    }
    e_squared/=120;

    variance = e_squared - (e*e);

    printf("\nSample Mean: %.3f",e);
    printf("\nSample Variance: %.3f",variance);

}