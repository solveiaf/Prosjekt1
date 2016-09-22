#include <ctime>
#include <iostream>
#include <cmath>
#include <fstream>
#include "time.h"
#include<string>
using namespace std;

ofstream ofile;

void GaussElim(double a[],double b[],double c[],double d[], int n, double v[]){
    //Forward Substitution
    double m;
    for (int k=2; k<=n; k++) {
        m = a[k]/b[k-1];
        b[k] = b[k] - m*c[k-1];
        d[k] = d[k] - m*d[k-1];
    }

    //Backward Substitution
    v[n]= d[n]/b[n];

    for (int k= n-1; k>0; k--) {
        v[k] = (1.0/b[k])*(d[k] - c[k]*v[k+1]);
    }

    v[0] = 0;
    v[n+1] = 0;
}

void function(int n, double b_i[]){
    double h, c, h_squared, x_i[n+1];
    h = 1./(n+1);
    h_squared = h*h;
    for (int k=0;k<=n+1; k++)  {
            x_i[k] = (k)*h;
            c = 100*exp(-10*x_i[k]);
            b_i[k] = h_squared*c;


    }
    //delete [] x_i;



}



int main(){

    //Declaring variables
    int n, a_value, b_value, c_value;

    cout << "Number of gridpoints: ";
    cin >> n;

    double h, a[n], b[n], c[n], points[n+1];

    a_value = -1;
    b_value = 2;
    c_value = -1;
    h = 1.0/(n+1);
    //making the vectors
    for (int k=0; k<=n; k++){
        a[k] = a_value;
        b[k] = b_value;
        c[k] = c_value;

    }

    for (int k=0; k<=n+1; k++){
        points[k] = k*h;
    }

    //declaring the array sfor the solution of the f(x) and the differential eq
    double f[n+1];
    double v[n+1];

    //getting the values for the f(x)=100*e^(-10x)
    function(n, f);

    //start the clock
    clock_t start, finish;
    start = clock();

    //Do the gaussian elimination
    GaussElim(a,b,c, f,n,v);

    //stop clock
    finish =clock();
    double t = ((finish-start));
    double seconds = t/CLOCKS_PER_SEC;
    cout << "seconds:" << seconds;

    //writing to file
    string outfilename;

    cout << "Please enter a file name to write: ";
    cin >> outfilename;

    ofile.open(outfilename);
    int i;
    ofile << "x:  " <<"computed_derivative" << "n = "<< n << "runtime: "<< seconds << endl;
    for (i=0; i<=n+1; i++){
        ofile << points[i] << "   " << v[i] << "\n";
    }
    ofile.close();

    return 0;

}


