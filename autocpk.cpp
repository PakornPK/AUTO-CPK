#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <numeric>

using namespace std;


void cpk_haden_en(char *inputfile){
    ifstream fin; 
    fin.open(inputfile,ios::in);  
    int rollnum (0), roll2 (0), count;
    double sum_v,avr_v,max_v,min_v,SD_v;  
    vector<string> row; 
    vector<double> d_value,d_value2; 
    vector<double>::iterator vptr;
    string line, _word, temp;
    count = 0;
    cout << "Maxvale_A | PositionX_A | PositionY_A" << endl; 
    cout << "-------------------------------------"<< endl; 
    while ( fin >> temp)
    {
        row.clear(); 
        getline(fin,line); 
        stringstream s(line); 

        while (getline(s,_word,','))
        {
            row.push_back(_word);
        }
        
        stringstream va,xa,ya;

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
                va << *ptr; 
                va >> number;
                d_value.push_back(number);
                d_value2.push_back(pow(number,2)); 
                sum_v +=number;
                cout << count << ". "<< number << " | "; 
                number = 0; 
            }
            if (counter == 21)
            {
                xa << *ptr; 
                xa >> number;    
                cout << number << " | ";
                number = 0; 
            }
            if (counter == 24)
            {
                ya << *ptr; 
                ya >> number;    
                cout << number << " | "<< endl; 
                number = 0; 
            }
        } 
        
        count++;                
    }  
    double zixma_v2,rtop,rbot,usl,lsl,cp,cpkl,cpku,cpk;
    vector<double> cpk_select;  
    usl = 900.0; 
    lsl = 540.0; 
    zixma_v2 = accumulate(d_value2.begin(),d_value2.end(),0);
    max_v = *max_element(d_value.begin(),d_value.end()); 
    min_v = *min_element(d_value.begin(),d_value.end()); 
    rtop = ((count-1)*zixma_v2)-pow(sum_v,2);
    rbot = (count-1)*(count-2);
    SD_v = sqrt(rtop/rbot);
    avr_v = sum_v/(count-1);
    cp = (max_v-min_v)/(6*SD_v); 
    cpkl = (avr_v-min_v)/(3*SD_v);
    cpku = (max_v-avr_v)/(3*SD_v);
    cpk_select.push_back(cpkl);
    cpk_select.push_back(cpku); 
    cpk  = *min_element(cpk_select.begin(),cpk_select.end());
 
    cout << "-----------------------------------------" << endl; 
    cout << "AVR = " << avr_v << endl; 
    cout << "SUM = " << sum_v << endl;
    cout << "MAX = " << max_v << endl;
    cout << "MIN = " << min_v << endl;
    cout << "S.D. = " << SD_v << endl;
    cout << "CPK = " << cpk << endl;
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