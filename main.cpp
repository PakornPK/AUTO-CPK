#include "cpktools.hh"

using namespace std; 
CPKTools cpk; 

void cpk_haden_en(char *inputfile){
    ifstream fin; 
    ofstream fout; 
    fin.open(inputfile,ios::in);
    fout.open("report_haden_en_cpk.csv",ios::out);

    if (fout.is_open() && fin.is_open())
    { 
        int rollnum, roll2, count=0; 
        vector<string> row; 
        vector<string>::iterator ptr;
        vector<double> data;
        vector<double>::iterator d_ptr;  
        string line, _word, temp, word;

        while (fin >> temp)
        {
            row.clear();
            getline(fin,line);
            stringstream s(line);

            while(getline(s,_word,','))
            {
                row.push_back(_word); 
            }

            stringstream va,xa,ya; 
            int counter = 0; 
            double valmeA = 0,PosXA = 0, PosYA = 0; 
            for (ptr = row.begin(); ptr != row.end(); ++ptr)
            {
                counter++;
                if (counter == 9)
                {
                    va << *ptr; 
                    va >> valmeA; 
                    data.push_back(valmeA); 
                }else if (counter == 21)
                {
                    xa << *ptr;
                    xa >> PosXA;
                    data.push_back(PosXA);
                }else if (counter == 24)
                {
                    ya << *ptr;
                    ya >> PosYA;
                    data.push_back(PosYA);
                }       
            }     
        }

        vector<double> buf0, buf1 , buf2; 

        for (d_ptr = data.begin(); d_ptr != data.end(); ++d_ptr)
        {   
            if (count == 0)
            {
                buf0.push_back(*d_ptr); 
            }else if (count == 1)
            {
                buf1.push_back(*d_ptr); 
            }else if (count == 2)
            {
                buf2.push_back(*d_ptr); 
            }
            count++; 
            if (count > 2)
            {
                count = 0; 
            } 
        }

        count = 0 ;
        
        double avr[3], _stdev[3], _cp[3], _cpk[3], _cpkl[3], _cpku[3], _min[3], _max[3]; 
        avr[0] = cpk.AVR(buf0); 
        avr[1] = cpk.AVR(buf1); 
        avr[2] = cpk.AVR(buf2); 

        _stdev[0] = cpk.STDEV(buf0);
        _stdev[1] = cpk.STDEV(buf1);
        _stdev[2] = cpk.STDEV(buf2);

        _min[0] = cpk.MIN(buf0);
        _min[1] = cpk.MIN(buf1);
        _min[2] = cpk.MIN(buf2);

        _max[0] = cpk.MAX(buf0); 
        _max[1] = cpk.MAX(buf1); 
        _max[2] = cpk.MAX(buf2); 

        _cp[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'C'); 
        _cp[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'C'); 
        _cp[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'C');

        _cpkl[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'L');  
        _cpkl[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'L'); 
        _cpkl[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'L');

        _cpku[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'U');
        _cpku[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'U');
        _cpku[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'U');

        _cpk[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'N');
        _cpk[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'N');
        _cpk[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'N');  

        fout << "CPK" << ',' <<"REPORT HADEN ENCLOSURE" << endl; 
        fout << ' ' << ',' << "Norminal Value(cc)" << ',' << 600
            << ',' << "Norminal Value(mm)" << ',' << 34.4
            << ',' << "Norminal Value(nn)" << ',' << 72.11 << "\n";

        fout << ' ' << ',' << "Tolerances" << ',' << 300
            << ',' << "Tolerances" << ',' << 0.3
            << ',' << "Tolerances" << ',' << 0.3 << "\n"; 
        
        fout << ' ' << ',' << "USL" << ',' << 900
            << ',' << "USL" << ',' << 34.7
            << ',' << "USL" << ',' << 72.41 << "\n"; 

        fout << ' ' << ',' << "LSL" << ',' << 300
            << ',' << "LSL" << ',' << 34.1
            << ',' << "LSL" << ',' << 71.81 << "\n"; 
        
        fout << ' ' ; 
        for (size_t i = 0; i < 3; i++)
        {
            fout << ',' << "Std Dev" << ',' << _stdev[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i < 3; i++)
        {
            fout << ',' << "Mean" << ',' << avr[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i < 3; i++)
        {
            fout << ',' << "Maximum" << ',' << _max[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i < 3; i++)
        {
            fout << ',' << "Minimum" << ',' << _min[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i < 3; i++)
        {
            fout << ',' << "Cp" << ',' << _cp[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i < 3; i++)
        {
            fout << ',' << "Cpkl" << ',' << _cpkl[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i < 3; i++)
        {
            fout << ',' << "Cpku" << ',' << _cpku[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i < 3; i++)
        {
            fout << ',' << "Cpk" << ',' << _cpk[i];
        }
        fout << "\n" << "\n"; 

        fout << "Piece" << ',' <<',' << "Volume_A" << ',' << ','<< "PositionX_A" << ',' << ',' << "PositionY_A" << "\n" ; 
        int picec =0; 
        for (d_ptr = data.begin(); d_ptr != data.end(); ++d_ptr)
        {   
            if (count == 0)
            {
                picec ++;
                fout << picec ;
                fout << ',' << ','<< *d_ptr << ',' << ',';  
            }
            if (count == 1)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 2)
            {
                fout << *d_ptr << ',' << "\n";
            }
            count++; 
            if (count > 2)
            {
                count = 0; 
            } 
            // cout << picec << "---->"; 
            // picec +=1;
            // cout << picec << endl;
        }


        cout << "Complete" << endl;;       
    }else
    {
        cout << "File can not open" << endl;    
    }
    fout.close();
    fin.close(); 
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
                cpk_haden_en(argv[1]); 
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