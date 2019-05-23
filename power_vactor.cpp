#include <iostream> 
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std; 

int main(){ 
    
    vector<double> data = {1,2,3,4,5,6,7,8,9,10};
    vector<double> data2 ; 
    double power; 

    vector<double>::iterator ptr; 
    for (ptr =data.begin(); ptr != data.end(); ++ptr)
    {
        power =0; 
        power += pow(*ptr,2);
        data2.push_back(power);
    }

    for (ptr = data2.begin(); ptr != data2.end(); ++ptr)
    {
        cout << *ptr << ',';
    }
    
    return 0;
}