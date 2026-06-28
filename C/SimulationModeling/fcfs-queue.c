#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double uniform() {
    return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}

double arrival_rate(double lambda) {
    double u = uniform();
    return (-1.0/lambda)*log(u);
}

double service_rate(double mu) {
    double u = uniform();
    return (-1.0/mu)*log(u);
}
int main() {
    srand(time(NULL));
    double lambda,mu;
    printf("\nEnter the Customer Arrival Rate:");
    scanf("%lf",&lambda);
    printf("\nEnter Customer Service Rate:");
    scanf("%lf",&mu);

    double arrival[5],service[5],start[5],finish[5],wait[5],system[5];
    for (int i = 0; i < 5; i++) {
        arrival[i] = 0,service[i] = 0,start[i] = 0,finish[i] = 0,wait[i] = 0,system[i] = 0;
    }

    double arrival_time = 0;
    double service_time = 0;
    printf("\nCustomer  |  Arrival  | Service |  Start  |  Finish  |  Wait  |  System");
    for (int i = 0; i < 5; i++) {
        arrival_time = arrival_rate(lambda);
        service_time = service_rate(mu);

        if (i==0) {
            arrival[i] = arrival_time;
        }
        else {
            arrival[i] = arrival_time + arrival[i-1];
        }

        service[i] = service_time;

        if (i==0) {
            start[i] = arrival_time;
        }
        else {
            if (arrival[i] > finish[i-1]) {
                start[i] = arrival[i];
            }
            else {
                start[i] = finish[i-1];
            }
        }

        finish[i] = start[i] + service[i];
        wait[i] = start[i] - arrival[i];
        system[i] = finish[i] - arrival[i];

        printf("\n%d  \t\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f",i+1,arrival[i],service[i],start[i],
            finish[i],wait[i],system[i]);
    }

    double total_waiting=0,total_system=0;
    for (int i = 0; i < 5; i++) {
        total_waiting += wait[i];
        total_system += system[i];
    }

    printf("\nAverage Wait Time: %.4f",total_waiting/5);
    printf("\nAverage Syst3em Time: %.4f",total_system/5);
}