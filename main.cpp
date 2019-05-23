#include <fstream>
#include <sstream>
#include "cpktools.hh"

using namespace std; 
CPKTools cpk; 

void cpk_haden_en(char *inputfile){
    ifstream fin; 
    ofstream fout; 
    fin.open(inputfile,ios::in);
    fout.open("report_cpk",ios::out);
    int rollnum, roll2, count; 
    vector<double> row; 
    vector<double>::iterator ptr; 
    string line, _word, temp; 
}

int main(int argc, char *argv[]){
    stringstream str_in; 
    str_in << argv[2]; 
    if (argc > 1 && argc <= 3)
    {
        cout << "The program running file : " << argv[1] 
            << "  Vertion of part : " 
            << str_in.str() 
            << endl 
            << endl;
            if (str_in.str() == "HADEN_EN")
            {

            }else{
                cout << "Pleses select Vertion of part ex. HADEN_EN" << endl; 
                return 1; 
            }
            
    }else
    {
        cout << "Error input program" << endl;    
    }   
    return 0; 
}