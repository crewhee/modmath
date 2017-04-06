#include <stdlib.h>
#include <vector>
#include <cmath>
#include "lab2.h"

using namespace std;
double function_lab_2(double x, double y){
    double result;
    result = (x*y)/(1 + pow(x,2));
    return result;
}

double analitics(double x){
    return 2 * sqrt(pow(x,2) + 1);
}

double eiler(double x, double y, double h){
    double delta_y = h * function_lab_2(x, y);
    double next_y = y + delta_y;
    return next_y;
}


double runge(double x, double y, double h){
    double result;
    double k1 = function_lab_2(x, y);
    double k2 = function_lab_2(x + (h/2), y + (h/2)*k1);
    double k3 = function_lab_2(x + (h/2), y + (h/2)*k2);
    double k4 = function_lab_2(x + h, y + h*k3);
    result = y + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
    return result;
}

void calculate(double h){
    double y_0 = 2.0;
    double a_0 = 0.0;
    double b_0 = 0.5;
    double h_0 = h;
    int size = b_0/h_0;
    vector<double> x;
    double current = a_0;
    x.reserve(int(b_0/h_0));
    for(int i = 0; i < size; i++){
        x[i] = current;
        current += h_0;
    }
    
    
    vector<double> y, y_a, y_eiler;
    y.reserve(size);
    y_a.reserve(size);
    y_eiler.reserve(size);
    y_eiler[0] = 2.0;
    y[0] = y_0;
    for(int i = 0; i < size; i++){
        y_a[i] = analitics(x[i]);
    }
    for(int i = 1; i < size; i++){
        y_eiler[i] = eiler(x[i-1], y_eiler[i-1], h_0);
        y[i] = runge(x[i], y[i-1], h_0);
    }
    
    printf("Аналитическое: \n");
    for(int i = 0; i < size; i++){
        printf("(%f, %f) \n", x[i], y_a[i]);
    }
    
    printf("Эйлера: \n");
    for(int i = 0; i < size; i++){
        printf("%f;", y_eiler[i]);
    }
    
    printf("\nРунге-Кутты: \n");
    for(int i = 0; i < size; i++){
        printf("(%f, %f) \n", x[i], y[i]);
    }
    for(int i = 0; i < size; i++){
        printf("%f\n", x[i]);
    }
    
    
    printf("%f %f \n", eiler(0.5, 2.115304, 0.1), eiler(0.5, 2.171421, 0.05));
    printf("%f %f \n", runge(0.5, 2.224971, 0.1), runge(0.5, 2.233278, 0.05));
    
}

