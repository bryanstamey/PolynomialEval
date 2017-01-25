/**
 * Implementation of functions described in header file
 * to work with polynomials using Horner and Naive methods.
 * @author Bryan T Stamey
 * @since 1/23/17
 * @see Polynomial.h
 */

#include "Polynomial.h"
#include <cstdlib>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

Polynomial::Polynomial() {
    deg = 0;                                        //degree is zero
    coeffs = new double[deg + 1];                   //create 1 coeff
    coeffs[0] = 0;                                  //element equal to zero
}

Polynomial::Polynomial(double c[], int d) {
    deg = d;                                        //set degree
    coeffs = new double[deg + 1];                   //create pointer for coeffs
    for(int i = 0; i <= deg; i++)
        coeffs[i] = c[i];                           //create array of coeffs
}

double Polynomial::hornerEval(double x) const {
    double sum = 0.0;                               //init sum
    for(int i = 0; i <= deg; i++) {
        sum = sum * x + *(coeffs + i);              // multiply sum by x and coeff
    }
    return sum;                                     //return final result
}

double Polynomial::naiveEval(double x) const {
    double sum = 0.0;                               //init sum to 0
    for(int i = 0; i <= deg; i++) {                 //exponent loop
        double m = *(coeffs + i);
        for(int j = 0; j < deg - i; j++) {          //sum loop
            m = m * x;                              //multiply by x
        }
        sum = sum + m;                              //add running sum to calculated value
    }
    return sum;     // return final result
}

int Polynomial::degree() const {
   return deg;                                      //return degree
}

string Polynomial::str() const {
    string s;                                       //create string to store
    stringstream ss;                                //init stringstream
     for(int i = 0; i <= deg-1; i++) {
         ss << fixed;                               
         ss << setprecision(1) << *(coeffs + i) << ", ";    //push coeff onto string
         s = ss.str();
    }
    ss << fixed;
    ss << setprecision(1) << *(coeffs + deg);       //add last coeff without ","
    s = ss.str();
    return s;                                       //return final string
}