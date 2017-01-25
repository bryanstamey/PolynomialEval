/**
 * Provides input to naive and horner eval functions
 * and outputs the evaluation of polynomials.
 * @author Bryan T Stamey
 * @since 1/23/17
 * @see Polynomial.h, Polynomial.cpp
 */

#include <cstdlib>
#include "Polynomial.h"
#include <iostream>
#include <chrono>
#include <random>
using namespace std;


int main(int argc, char** argv) {
    
    typedef std::chrono::high_resolution_clock::time_point TimeVar;
    
    //calculate polynomial f
    double f[] = {4, 5, 0, 2, 3, 5, -1};
    Polynomial polyf(f,6);                         //pass polynomial f
    cout << "f: [" << polyf.str() << "]\n";
    cout << "deg f(x) := " << polyf.degree() << endl;
    cout << "Using Horner’s method, f(3) = " << polyf.hornerEval(3) << endl;
    cout << "Using naive method, f(3) = " << polyf.naiveEval(3) << endl << endl;

    //calculate polynomial g
    double g[] = {12.5, 0, 0, -1, 7.2, -9.5};
    Polynomial polyg(g,5);                            //pass polynomial g
    cout << "g: [" << polyg.str() << "]  \n";
    cout << "deg g(x) := " << polyg.degree() << endl;
    cout << "Using Horner’s method, g(-7.25) = " << polyg.hornerEval(-7.25) << endl;
    cout << "Using naive method, g(-7.25) = " << polyg.naiveEval(-7.25) << endl;
    
    cout << endl << endl;
    cout << "Empirical Analysis of Naive vs Horner's Methods \non 10 Polynomials with Random Coefficients\n";
    cout << "================================================\n";
    cout << "Degree    Naive Time (ns)    Horner's Time (ns)\n";
    cout << "------------------------------------------------\n";
    
    for(int i = 1000; i <= 10000; i = i + 1000) {   //1000, 2000, ..., 10000
        double *c = new double[i + 1];
        for(int j = 0; j <= i; j++) {           //loop over exponents
            srand(time(NULL));                  //seeds generator to time
            c[j] = rand() % 6;                  //rand nums [0,5]
        }
        Polynomial polyc(c,i);                    //pass polynomial c
        
        random_device rd;
        default_random_engine generator(rd());
        uniform_real_distribution<double> distribution(0.5,1.2);
        double x = distribution(generator);         //rand eval num [0.5,1.2]
        
        cout << i << "       ";                       //print degree 
        //Naive eval & time
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        polyc.naiveEval(x);
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>( t2 - t1 ).count();
        cout << duration << "            ";          //naive time
        

        //Horner eval & time
        chrono::high_resolution_clock::time_point t3 = chrono::high_resolution_clock::now();
        polyc.hornerEval(x);
        chrono::high_resolution_clock::time_point t4 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::nanoseconds>( t4 - t3 ).count();
        cout << duration1 << "      \n";             //horner time
    }
    
    cout << "------------------------------------------------\n";
    return 0;
}