#include "cpktools.hh"

double CPKTools::MAX(vector<double> data){
    double max; 
    return max = *max_element(data.begin(),data.end());
}

double CPKTools::MIN(vector<double> data){
    double min; 
    return min = *min_element(data.begin(),data.end());
}

double CPKTools::AVR(vector<double> data){
    double avr; 
    return avr = accumulate(data.begin(),data.end(),0.0)/data.size(); 
}

double CPKTools::RANGE(vector<double> data){
    double rang,maxx,minn; 
    maxx = *max_element(data.begin(),data.end()); 
    minn = *min_element(data.begin(),data.end());
    return rang = maxx - minn;  
}

double CPKTools::STDEV(vector<double> data){
    
}