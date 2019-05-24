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
        double CPK(double maxx, double minn , double avr , double stdev, double lsl, double usl, char select); 
        double MAX(vector<double> data);
        double MIN(vector<double> data);
}; 