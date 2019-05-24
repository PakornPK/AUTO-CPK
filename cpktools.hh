#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std; 

class CPKTools{
    public: 
        double STDEV(vector<double> data); 
        double AVR(vector<double> data); 
        double RANGE(vector<double> data); 
        double CPK(double max, double min , double avr , double stdev, char select); 
        double MAX(vector<double> data);
        double MIN(vector<double> data);
}; 