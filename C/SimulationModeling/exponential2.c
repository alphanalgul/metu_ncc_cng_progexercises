#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
double uniform() {
    return ((double)rand() + 1.0) / ((double)RAND_MAX + 2.0);
}

int main() {
    srand(time(NULL));
    double X;
    double lambda = 1.0/4.0;
    double arr[1000];
    int count_02 = 0,count_24 = 0,count_46 = 0,count_68 = 0, count_8greater = 0;
    for (int i = 0; i < 1000; i++) {
        double U = uniform();
        X = -log(U) / lambda;

        arr[i] = X;

        if (X < 2) {
            count_02++;
        }
        else if ( X < 4) {
            count_24++;
        }
        else if ( X < 6) {
            count_46++;
        }
        else if (X < 8) {
            count_68++;
        }
        else {
            count_8greater++;
        }
    }
    printf("\nCount of values in interval [0,2): %d",count_02);
    printf("\nCount of values in interval [2,4): %d",count_24);
    printf("\nCount of values in interval [4,6): %d",count_46);
    printf("\nCount of values in interval [6,8): %d",count_68);
    printf("\nCount of values in interval [8,infinity): %d",count_8greater);

    double mean = 0.0;
    for (int i = 0; i < 1000; i++) {
        mean += arr[i];
    }
    mean /= 1000;
    printf("\nMean is: %.2f",mean);

    double mean_squared = 0.0;
    for (int i = 0; i < 1000; i++) {
        mean_squared += arr[i]*arr[i];
    }
    mean_squared /= 1000;

    double variance = mean_squared - (mean*mean);

    printf("\nVariance is: %.2f",variance);
}