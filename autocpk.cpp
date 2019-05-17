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
    int rollnum (0), roll2 (0), count;
    double sum,avr;  
    count =0; 
    sum = 0;
    avr =0; 
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
        //copy(row.begin(), row.end(),ostream_iterator<string>(cs,"\n"));

        int counter;
        double number;
        counter = 0;
        number = 0;  
        vector<string>::iterator ptr;
        for(ptr = row.begin(); ptr != row.end(); ++ptr)
        {
            counter++;
            if (counter == 9)
            {
                cs << *ptr; 
                cs >> number;
                sum +=number;
                cout << count << ". "<< number << endl; 
                number = 0; 
            }
            
        } 
        count++;                
    }  
    avr = sum/count;
    cout << "-----------------------------------------" << endl; 
    cout << "AVR = " << avr << endl; 
    cout << "SUM = "<< sum << endl; 
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