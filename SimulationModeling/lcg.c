#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void lcg(int a, int c, int m, int seed, int num_values) {
    double total = 0;
    double arr[num_values];
    printf("\ni\tXi\tUi");
    for (int i = 0; i <num_values; i++) {
        seed = ((a*seed)+c) % m;
        arr[i] = (double)seed / m;
        total += arr[i];

        printf("\n%d\t%d\t%.4f",i+1,seed,arr[i]);
    }

    double mean = total / num_values;
    double variance = 0;
    for ( int i = 0; i < num_values; i++) {
        variance += pow(arr[i]-mean,2);
    }
    variance /= num_values;
    printf("\nMean is: %.4f",mean);
    printf("\nVariance is: %.4f",variance);
}

int main() {
    int a,c,m,seed,n;
    printf("Enter a,c,m,seed and number of values: ");
    scanf("%d%d%d%d%d",&a,&c,&m,&seed,&n);
    lcg(a,c,m,seed,n);
}