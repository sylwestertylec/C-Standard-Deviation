//
//  main.cpp
//  C++ SD
//
//  Created by Sylwester Tylec on 15/06/2022.
//

#include <cmath>
#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std;

double calculateSD(double data[]);
int main() {
    
    double data[]={1,2,3,4,5,6,7,8,9,10};

  cout << endl << "Standard Deviation = " << calculateSD(data);

  return 0;
}

double calculateSD(double data[]) {
    
    auto start = chrono::steady_clock::now();
  double sum = 0.0, mean, standardDeviation = 0.0;
  int i;

  for(i = 0; i < 10; ++i) {
    sum += data[i];
  }

  mean = sum / 10;

  for(i = 0; i < 10; ++i) {
    standardDeviation += pow(data[i] - mean, 2);
  }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: "
    << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
    << " ns" << endl;
  return sqrt(standardDeviation / 10);
}
