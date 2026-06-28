#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform() {
    return ((double)rand()+1.0) / ((double)RAND_MAX+2.0);
}
int main(void) {
    srand(time(NULL));
    double u;
    double uniforms[1000];
    double min = 0;
    double max = 0;
    double a = 0;
    double b = 1;
    for (int i = 0; i < 1000; i++) {
        u = uniform();
        uniforms[i] = u;
        if (u > max) {
            max = u;
        }
        if (min == 0) {
            min = u;
        }
        if (u < min) {
            min = u;
        }
        printf("\nRandom number %d: %.3f",i+1,u);
    }

    printf("\nMinimum Generated Value: %.3f",min);
    printf("\nMaximum Generated Value: %.3f",max);

    printf("\nTheoretical Mean: %.3f",(b+a)/2);
    printf("\nTheoretical Variance: %.3f",(pow(b-a,2))/12);


    double e=0,e_squared=0,variance;

    for (int i = 0; i < 1000; i++) {
        e += uniforms[i];
    }
    e/=1000;

    for (int i = 0; i < 1000; i++) {
        e_squared += uniforms[i]*uniforms[i];
    }
    e_squared/=1000;

    variance = e_squared - (e*e);
    printf("\nSample Mean: %.3f",e);
    printf("\nSample Variance: %.3f",variance);
}