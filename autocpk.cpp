#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std; 

void cpk(char *inputfile){
    ifstream fin(inputfile); 
    
    if (fin.is_open() && fin.good())
    {
        string line; 
        while (getline(fin,line))
        {
            cout << line;
        }
        
    }
    
}
int main(int argc, char *argv[]){
    if (argc > 1)
    {
        cout << "The program running file : " << argv[1] << endl;
        cpk(argv[1]);
    }
    else
    {
        cout << "plese input your file" << endl;
    }
    
    return 0; 
}