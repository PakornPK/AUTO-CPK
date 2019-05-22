#include <iostream> 
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std; 

int main(){ 
    
    vector<double> data = {1,2,3,4,5,6,7,8,9,10};
    vector<double> data2 = data; 
    transform(data2.begin()+1,data2.end(),data2.begin()+1,data2.end(),multiplies<double>());

    vector<double>::iterator ptr; 
    for (ptr =data2.begin(); ptr != data2.end(); ++ptr)
    {
        cout << *ptr << endl;
    }
    return 0;
}