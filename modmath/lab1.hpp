//
//  lab1.hpp
//  modmath
//
//  Created by Antony Sudov on 06.04.17.
//  Copyright © 2017 Antony Sudov. All rights reserved.
//

#ifndef lab1_hpp
#define lab1_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

double squares_left(double *a, long length);
double squares_right(double *a, long length);
double squares(double *a, long length);
double trap(double *a, long length);
double simpson(double *a, const long length);
double montecarlo(long length, long precision);
double montecarlographic(long length, long precision);
double precision_squares(long precision);
double precision_squares_center(long precision);
double precision_trapezium(long precision);
double precision_simpson(long precision);
void do_lab1();

#endif /* lab1_hpp */
