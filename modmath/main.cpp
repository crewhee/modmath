#include <iostream>
#include <cmath>
#include <vector>
#include <array>

using namespace std;

double squares_left(double *a, long length){
    double result = 0.0;
    double h = 2/(double(length / 2));
    for(int i = 0; i < length; i+=2){
        result = result + (h * a[i]);
    }
    return result;
}

double squares_right(double *a, long length){
    double result = 0.0;
    double h = 2/(double(length / 2));
    for(int i = 1; i < length; i+=2){
        result = result + (h * a[i]);
    }
    return result;
}

double squares(double *a, long length){
    double result = 0.0;
    double h = 2/(double(length / 2));
    for(int i = 0; i < length -1 ; i+=2){
        result = result + ( h * (a[i] + a[i+1])/2 );
    }
    return result;
}

double trap(double *a, long length){
    double result = 0.0;
    double h = 2/(double(length));
    for(int i = 0; i < length - 1; i++){
        result = result + (h * (a[i] + a[i + 1]));
    }
    return result / 2;
}

double simpson(double *a, const long length){
    double result = 0.0;
    double h = 2/(double(length));
    for(int i = 2; i < length/2; i++){
        result = result + (h * (a[2*i - 2] + 4 * a[2*i - 1] + a[2*i]));
    }
    return result / 3;
}

double montecarlo(long length, long precision){
    double result = 0.0;
    vector<double> random_dotes;
    random_dotes.reserve(precision);
    for(int i = 0; i < precision; i++){
        random_dotes[i] = (rand() % precision)/(precision/2.0) - 1;
    }
    for(int i = 0; i < precision; i++){
        result = result + (2 * random_dotes[i] * atan(random_dotes[i]));
    }
    return result / precision;
}

double montecarlographic(long length, long precision){
    double result = 0.0;
    vector<double> random_dotes_x, random_dotes_y;
    random_dotes_x.reserve(precision);
    random_dotes_y.reserve(precision);
    long counter = 0;
    long dotes_number = 0;
    for(int i = 0; i < precision; i++) {
        random_dotes_x[i] = (rand() % precision) / (precision/2.0) - 1;
        random_dotes_y[i] = (rand() % precision) / (precision / (M_PI  / 4));
        dotes_number++;
        if(random_dotes_y[i] <= (random_dotes_x[i] * atan(random_dotes_x[i])) ){
            counter++;
        }
    }
    result = double(counter) / double(dotes_number) * (M_PI / 2);
    return result;
}

/*
 В функциях для расчета точности тех или иных методов формулы приведены в уже сокращенном виде
 Дело в том, что максимумы функций четные, длина отрезка интегрирования равна двум и это все 
 прекрасно сокращается с коэффициентами
 step = количество точек от 0 до 1 - промежуточная переменная
 */

double precision_squares(long precision){
    double result;
    double step = precision / 2;
    result = (2 + M_PI)/4*(double(1/step));
    return result;
}

double precision_squares_center(long precision){
    double result;
    double step = precision / 2;
    result = 6 * (pow((1.0 / step), 2));
    return result;
}

double precision_trapezium(long precision){
    double result;
    double step = precision / 2;
    result = 1 / 3 * pow(1 / step, 2);
    return result;
}

double precision_simpson(long precision){
    double result;
    double step = precision / 4;
    result = (16/180.0) * pow(1/step, 4);
    return result;
    
}


int main(int argc, const char * argv[]) {
    
    time_t t;
    srand((unsigned) time(&t));
    long length = 1000000;
    double step = 1 / (double(length));
    double start = step;
    
    
    double A[length];
    for(int i = 1; i < length; i++){
        A[i] = (start * 2) - 1;
        start += step;
    }
    for(int i = 0; i < length; i++){
        A[i] = A[i] * atan(A[i]);
    }
    
    printf("Точное аналитическое = %f \n", (M_PI - 2)/2.0);
    printf("%f \n", squares_right(A, length));
    printf("%f \n", squares_left(A,length));
    printf("%f \n", squares(A, length));
    printf("%f \n", trap(A, length));
    printf("%f \n", simpson(A, length));
    double montecarlo_result;
    for(int i = 0; i < 10; i++){
        montecarlo_result += pow(montecarlo(length, 1000000), 2);
    }
    montecarlo_result = montecarlo_result / 10.0;
    printf("%f \n", sqrt(montecarlo_result));
    double montecarlo_result_graph;
    for(int i = 0; i < 10; i++){
        montecarlo_result_graph += pow(montecarlographic(length, 1000000), 2);
    }
    montecarlo_result_graph = montecarlo_result_graph / 10.0;
    printf("%f \n \n end \n", sqrt(montecarlo_result_graph));
    
    //написать погрешность решения
    printf("%f \n", precision_squares(length));
    printf("%f \n", precision_squares_center(length));
    printf("%f \n", precision_trapezium(length));
    printf("%f \n", precision_simpson(length));
    
    return 1;
}
