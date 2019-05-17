#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
using namespace std; 

void cpk_haden_en(char *inputfile){
    ifstream fin; 
    fin.open(inputfile,ios::in);  
    int rollnum (0), roll2 (0), count (0); 
    vector<string> row; 
    string line, word, temp; 
    while ( fin >> temp)
    {
        row.clear(); 
        getline(fin,line); 
        stringstream s(line); 

        while (getline(s,word,','))
        {
            row.push_back(word);
        }
        
        stringstream cs;
        copy(row.begin(), row.end(),ostream_iterator<string>(cs,"\n"));
  
        if (roll2 == rollnum) { 
            cout << cs.str() ; 
        } 
    }  
}
int main(int argc, char *argv[]){
    stringstream str_in;
    str_in << argv[2]; 
    if (argc > 1 && argc <=3)
    {
        cout << "The program running file : " << argv[1] << "  Vertion of part : " << str_in.str() << endl;
        if (str_in.str() == "HADEN_EN")
        {
            cpk_haden_en(argv[1]);
        }else
        {
            cout << argv[2] << endl; 
            cout << "Pleses select Vertion of part ex. HADEN_EN" << endl; 
            return 1; 
        }
    }
    else
    {
        cout << "Error input program" << endl;
    }
    
    return 0; 
}