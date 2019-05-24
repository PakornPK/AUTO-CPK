#include "cpktools.hh"

using namespace std; 
CPKTools cpk; 

void cpk_haden_en(char *inputfile){
    ifstream fin; 
    ofstream fout; 
    fin.open(inputfile,ios::in);
    fout.open("report_haden_en_cpk.csv",ios::app);


     
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
        // fout << "Valume_A" << ',' << ','
        //     << "PositionX_A" << ',' << ','
        //     << "PositionY_A" << ',' << "\n";

        for (d_ptr = data.begin(); d_ptr != data.end(); ++d_ptr)
        {   
            if (count == 0)
            {
                //fout << *d_ptr << ','<< ',';
            }else if (count == 1)
            {
                //fout << *d_ptr << ','<< ',';
            }else if (count == 2)
            {
                //fout << *d_ptr << ','<< "\n";
            }

            count++; 
            if (count > 2)
            {
                count = 0; 
            } 
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