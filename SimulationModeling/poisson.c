#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform() {
    return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}

double exponential(double lambda) {
    double u = uniform();
    return -(1/lambda)*log(u);
}

int main(void) {
    srand(time(NULL));
    double lambda = 6;
    double y;
    int arrivals[100];
    for (int i = 0; i < 100; i++) {
        int count = 0;
        double s = 0;
        while (s <= 1) {
            y = exponential(lambda);
            s += y;
            count++;
        }
        arrivals[i] = count - 1;
        printf("\nHour %d Arrivals: %d",i+1,count);
    }

    printf("\nTheoretical Mean: %.3f",lambda);
    printf("\nTheoretical Variance: %.3f",lambda);

    double e = 0, e_squared = 0, variance;
    for (int i = 0; i < 100; i++) {
        e += arrivals[i];
    }
    e /= 100;

    for (int i = 0; i < 100; i++) {
        e_squared += arrivals[i] * arrivals[i];
    }
    e_squared /= 100;

    variance = e_squared - (e*e);

    printf("\nSample Mean: %.3f",e);
    printf("\nSample Variance: %.3f",variance);
}