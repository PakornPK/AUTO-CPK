#include "cpktools.hh"

double CPKTools::MAX(vector<double> data){
    double max; 
    return max = *max_element(data.begin(),data.end());
}

double CPKTools::MIN(vector<double> data){
    double min; 
    return min = *min_element(data.begin(),data.end());
}