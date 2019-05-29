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

            stringstream va,xa,ya,vb,xb,yb,vc,xc,yc; 
            int counter = 0; 
            double volumeA = 0,PosXA = 0, PosYA = 0,volumeB = 0,PosXB = 0, PosYB = 0,volumeC = 0,PosXC = 0, PosYC = 0; 
            for (ptr = row.begin(); ptr != row.end(); ++ptr)
            {
                counter++;
                if (counter == 9)
                {
                    va << *ptr; 
                    va >> volumeA; 
                    data.push_back(volumeA); 
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
                }else if (counter == 27)
                {
                    vb << *ptr; 
                    vb >> volumeB; 
                    data.push_back(volumeB); 
                }else if (counter == 39)
                {
                    xb << *ptr; 
                    xb >> PosXB; 
                    data.push_back(PosXB); 
                }
                else if (counter == 42)
                {
                    yb << *ptr; 
                    yb >> PosYB; 
                    data.push_back(PosYB); 
                }else if (counter == 45)
                {
                    vc << *ptr; 
                    vc >> volumeC; 
                    data.push_back(volumeC); 
                }else if (counter == 57)
                {
                    xc << *ptr; 
                    xc >> PosXC; 
                    data.push_back(PosXC); 
                }
                else if (counter == 60)
                {
                    yc << *ptr; 
                    yc >> PosYC; 
                    data.push_back(PosYC); 
                }
                       
            }     
        }

        vector<double> buf0, buf1 , buf2, buf3, buf4, buf5, buf6, buf7, buf8; 

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
            }else if (count == 3)
            {
                buf3.push_back(*d_ptr); 
            }else if (count == 4)
            {
                buf4.push_back(*d_ptr); 
            }else if (count == 5)
            {
                buf5.push_back(*d_ptr); 
            }else if (count == 6)
            {
                buf6.push_back(*d_ptr); 
            }else if (count == 7)
            {
                buf7.push_back(*d_ptr); 
            }else if (count == 8)
            {
                buf8.push_back(*d_ptr); 
            }
            count++; 
            if (count > 8)
            {
                count = 0; 
            } 
        }

        count = 0 ;
        
        double avr[9], _stdev[9], _cp[9], _cpk[9], _cpkl[9], _cpku[9], _min[9], _max[9]; 
        avr[0] = cpk.AVR(buf0); 
        avr[1] = cpk.AVR(buf1); 
        avr[2] = cpk.AVR(buf2); 
        avr[3] = cpk.AVR(buf3); 
        avr[4] = cpk.AVR(buf4); 
        avr[5] = cpk.AVR(buf5);
        avr[6] = cpk.AVR(buf6); 
        avr[7] = cpk.AVR(buf7); 
        avr[8] = cpk.AVR(buf8);

        _stdev[0] = cpk.STDEV(buf0);
        _stdev[1] = cpk.STDEV(buf1);
        _stdev[2] = cpk.STDEV(buf2);
        _stdev[3] = cpk.STDEV(buf3);
        _stdev[4] = cpk.STDEV(buf4);
        _stdev[5] = cpk.STDEV(buf5);
        _stdev[6] = cpk.STDEV(buf6);
        _stdev[7] = cpk.STDEV(buf7);
        _stdev[8] = cpk.STDEV(buf8);

        _min[0] = cpk.MIN(buf0);
        _min[1] = cpk.MIN(buf1);
        _min[2] = cpk.MIN(buf2);
        _min[3] = cpk.MIN(buf3);
        _min[4] = cpk.MIN(buf4);
        _min[5] = cpk.MIN(buf5);
        _min[6] = cpk.MIN(buf6);
        _min[7] = cpk.MIN(buf7);
        _min[8] = cpk.MIN(buf8);

        _max[0] = cpk.MAX(buf0); 
        _max[1] = cpk.MAX(buf1); 
        _max[2] = cpk.MAX(buf2);
        _max[3] = cpk.MAX(buf3); 
        _max[4] = cpk.MAX(buf4); 
        _max[5] = cpk.MAX(buf5);
        _max[6] = cpk.MAX(buf6); 
        _max[7] = cpk.MAX(buf7); 
        _max[8] = cpk.MAX(buf8); 

        _cp[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'C'); 
        _cp[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'C'); 
        _cp[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'C');
        _cp[3] = cpk.CPK(_max[3],_min[3],avr[3],_stdev[3],25.0,75.0,'C'); 
        _cp[4] = cpk.CPK(_max[4],_min[4],avr[4],_stdev[4],54.85,55.45,'C'); 
        _cp[5] = cpk.CPK(_max[5],_min[5],avr[5],_stdev[5],78.16,78.76,'C');
        _cp[6] = cpk.CPK(_max[6],_min[6],avr[6],_stdev[6],25.0,75.0,'C'); 
        _cp[7] = cpk.CPK(_max[7],_min[7],avr[7],_stdev[7],54.85,55.45,'C'); 
        _cp[8] = cpk.CPK(_max[8],_min[8],avr[8],_stdev[8],67,67.6,'C');

        _cpkl[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'L'); 
        _cpkl[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'L'); 
        _cpkl[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'L');
        _cpkl[3] = cpk.CPK(_max[3],_min[3],avr[3],_stdev[3],25.0,75.0,'L'); 
        _cpkl[4] = cpk.CPK(_max[4],_min[4],avr[4],_stdev[4],54.85,55.45,'L'); 
        _cpkl[5] = cpk.CPK(_max[5],_min[5],avr[5],_stdev[5],78.16,78.76,'L');
        _cpkl[6] = cpk.CPK(_max[6],_min[6],avr[6],_stdev[6],25.0,75.0,'L'); 
        _cpkl[7] = cpk.CPK(_max[7],_min[7],avr[7],_stdev[7],54.85,55.45,'L'); 
        _cpkl[8] = cpk.CPK(_max[8],_min[8],avr[8],_stdev[8],67,67.6,'L');

        _cpku[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'U'); 
        _cpku[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'U'); 
        _cpku[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'U');
        _cpku[3] = cpk.CPK(_max[3],_min[3],avr[3],_stdev[3],25.0,75.0,'U'); 
        _cpku[4] = cpk.CPK(_max[4],_min[4],avr[4],_stdev[4],54.85,55.45,'U'); 
        _cpku[5] = cpk.CPK(_max[5],_min[5],avr[5],_stdev[5],78.16,78.76,'U');
        _cpku[6] = cpk.CPK(_max[6],_min[6],avr[6],_stdev[6],25.0,75.0,'U'); 
        _cpku[7] = cpk.CPK(_max[7],_min[7],avr[7],_stdev[7],54.85,55.45,'U'); 
        _cpku[8] = cpk.CPK(_max[8],_min[8],avr[8],_stdev[8],67,67.6,'U');

        _cpk[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'N'); 
        _cpk[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'N'); 
        _cpk[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'N');
        _cpk[3] = cpk.CPK(_max[3],_min[3],avr[3],_stdev[3],25.0,75.0,'N'); 
        _cpk[4] = cpk.CPK(_max[4],_min[4],avr[4],_stdev[4],54.85,55.45,'N'); 
        _cpk[5] = cpk.CPK(_max[5],_min[5],avr[5],_stdev[5],78.16,78.76,'N');
        _cpk[6] = cpk.CPK(_max[6],_min[6],avr[6],_stdev[6],25.0,75.0,'N'); 
        _cpk[7] = cpk.CPK(_max[7],_min[7],avr[7],_stdev[7],54.85,55.45,'N'); 
        _cpk[8] = cpk.CPK(_max[8],_min[8],avr[8],_stdev[8],67,67.6,'N');  

        fout << "CPK" << ',' <<"REPORT HADEN ENCLOSURE" << endl; 
        fout << ' ' << ',' << "Norminal Value(cc)" << ',' << 600
            << ',' << "Norminal Value(mm)" << ',' << 34.4
            << ',' << "Norminal Value(mm)" << ',' << 72.11
            << ',' << "Norminal Value(cc)" << ',' << 50
            << ',' << "Norminal Value(mm)" << ',' << 55.15
            << ',' << "Norminal Value(nn)" << ',' << 78.46
            << ',' << "Norminal Value(cc)" << ',' << 50
            << ',' << "Norminal Value(mm)" << ',' << 55.15
            << ',' << "Norminal Value(mm)" << ',' << 67.3 << "\n";

        fout << ' ' << ',' << "Tolerances" << ',' << 300
            << ',' << "Tolerances" << ',' << 0.3
            << ',' << "Tolerances" << ',' << 0.3  
            << ',' << "Tolerances" << ',' << 25
            << ',' << "Tolerances" << ',' << 0.3
            << ',' << "Tolerances" << ',' << 0.3 
            << ',' << "Tolerances" << ',' << 25
            << ',' << "Tolerances" << ',' << 0.3
            << ',' << "Tolerances" << ',' << 0.3 << "\n";
        
        fout << ' ' << ',' << "USL" << ',' << 900
            << ',' << "USL" << ',' << 34.7
            << ',' << "USL" << ',' << 72.41 
            << ',' << "USL" << ',' << 75
            << ',' << "USL" << ',' << 55.45
            << ',' << "USL" << ',' << 78.76 
            << ',' << "USL" << ',' << 75
            << ',' << "USL" << ',' << 55.45
            << ',' << "USL" << ',' << 67.6 << "\n"; 

        fout << ' ' << ',' << "LSL" << ',' << 300
            << ',' << "LSL" << ',' << 34.1
            << ',' << "LSL" << ',' << 71.81
            << ',' << "LSL" << ',' << 25
            << ',' << "LSL" << ',' << 54.85
            << ',' << "LSL" << ',' << 78.16 
            << ',' << "LSL" << ',' << 25
            << ',' << "LSL" << ',' << 54.85
            << ',' << "LSL" << ',' << 67 << "\n"; 
        
        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Std Dev" << ',' << _stdev[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Mean" << ',' << avr[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Maximum" << ',' << _max[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Minimum" << ',' << _min[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Cp" << ',' << _cp[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Cpkl" << ',' << _cpkl[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Cpku" << ',' << _cpku[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Cpk" << ',' << _cpk[i];
        }
        fout << "\n" << "\n"; 

        fout << "Piece" << ',' <<',' << "Volume_A" << ',' << ','<< "PositionX_A" << ',' << ',' << "PositionY_A" 
            << ',' <<',' << "Volume_B" << ',' << ','<< "PositionX_B" << ',' << ',' << "PositionY_B" 
            << ',' <<',' << "Volume_C" << ',' << ','<< "PositionX_C" << ',' << ',' << "PositionY_C" 
            << endl; 
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
                fout << *d_ptr << ',' << ',';
            }
            if (count == 3)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 4)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 5)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 6)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 7)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 8)
            {
                fout << *d_ptr << ',' << "\n";
            }
            count++; 
            if (count > 8)
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

void cpk_haden_co(char *inputfile){
    ifstream fin; 
    ofstream fout; 
    fin.open(inputfile,ios::in);
    fout.open("report_haden_co_cpk.csv",ios::out);

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

            stringstream va,xa,ya,vb,xb,yb,vc,xc,yc; 
            int counter = 0; 
            double volumeA = 0,PosXA = 0, PosYA = 0,volumeB = 0,PosXB = 0, PosYB = 0,volumeC = 0,PosXC = 0, PosYC = 0; 
            for (ptr = row.begin(); ptr != row.end(); ++ptr)
            {
                counter++;
                if (counter == 9)
                {
                    va << *ptr; 
                    va >> volumeA; 
                    data.push_back(volumeA); 
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
                }else if (counter == 27)
                {
                    vb << *ptr; 
                    vb >> volumeB; 
                    data.push_back(volumeB); 
                }else if (counter == 39)
                {
                    xb << *ptr; 
                    xb >> PosXB; 
                    data.push_back(PosXB); 
                }
                else if (counter == 42)
                {
                    yb << *ptr; 
                    yb >> PosYB; 
                    data.push_back(PosYB); 
                }else if (counter == 45)
                {
                    vc << *ptr; 
                    vc >> volumeC; 
                    data.push_back(volumeC); 
                }else if (counter == 57)
                {
                    xc << *ptr; 
                    xc >> PosXC; 
                    data.push_back(PosXC); 
                }
                else if (counter == 60)
                {
                    yc << *ptr; 
                    yc >> PosYC; 
                    data.push_back(PosYC); 
                }
                       
            }     
        }

        vector<double> buf0, buf1 , buf2, buf3, buf4, buf5, buf6, buf7, buf8; 

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
            }else if (count == 3)
            {
                buf3.push_back(*d_ptr); 
            }else if (count == 4)
            {
                buf4.push_back(*d_ptr); 
            }else if (count == 5)
            {
                buf5.push_back(*d_ptr); 
            }else if (count == 6)
            {
                buf6.push_back(*d_ptr); 
            }else if (count == 7)
            {
                buf7.push_back(*d_ptr); 
            }else if (count == 8)
            {
                buf8.push_back(*d_ptr); 
            }
            count++; 
            if (count > 8)
            {
                count = 0; 
            } 
        }

        count = 0 ;
        
        double avr[9], _stdev[9], _cp[9], _cpk[9], _cpkl[9], _cpku[9], _min[9], _max[9]; 
        avr[0] = cpk.AVR(buf0); 
        avr[1] = cpk.AVR(buf1); 
        avr[2] = cpk.AVR(buf2); 
        avr[3] = cpk.AVR(buf3); 
        avr[4] = cpk.AVR(buf4); 
        avr[5] = cpk.AVR(buf5);
        avr[6] = cpk.AVR(buf6); 
        avr[7] = cpk.AVR(buf7); 
        avr[8] = cpk.AVR(buf8);

        _stdev[0] = cpk.STDEV(buf0);
        _stdev[1] = cpk.STDEV(buf1);
        _stdev[2] = cpk.STDEV(buf2);
        _stdev[3] = cpk.STDEV(buf3);
        _stdev[4] = cpk.STDEV(buf4);
        _stdev[5] = cpk.STDEV(buf5);
        _stdev[6] = cpk.STDEV(buf6);
        _stdev[7] = cpk.STDEV(buf7);
        _stdev[8] = cpk.STDEV(buf8);

        _min[0] = cpk.MIN(buf0);
        _min[1] = cpk.MIN(buf1);
        _min[2] = cpk.MIN(buf2);
        _min[3] = cpk.MIN(buf3);
        _min[4] = cpk.MIN(buf4);
        _min[5] = cpk.MIN(buf5);
        _min[6] = cpk.MIN(buf6);
        _min[7] = cpk.MIN(buf7);
        _min[8] = cpk.MIN(buf8);

        _max[0] = cpk.MAX(buf0); 
        _max[1] = cpk.MAX(buf1); 
        _max[2] = cpk.MAX(buf2);
        _max[3] = cpk.MAX(buf3); 
        _max[4] = cpk.MAX(buf4); 
        _max[5] = cpk.MAX(buf5);
        _max[6] = cpk.MAX(buf6); 
        _max[7] = cpk.MAX(buf7); 
        _max[8] = cpk.MAX(buf8); 

// ............... here 
        _cp[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],35,105,'C'); 
        _cp[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],13.12,13.72,'C'); 
        _cp[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],77.18,77.78,'C');
        _cp[3] = cpk.CPK(_max[3],_min[3],avr[3],_stdev[3],35,105,'C'); 
        _cp[4] = cpk.CPK(_max[4],_min[4],avr[4],_stdev[4],13.12,13.72,'C'); 
        _cp[5] = cpk.CPK(_max[5],_min[5],avr[5],_stdev[5],66.02,66.62,'C');
        _cp[6] = cpk.CPK(_max[6],_min[6],avr[6],_stdev[6],175,525,'C'); 
        _cp[7] = cpk.CPK(_max[7],_min[7],avr[7],_stdev[7],33.88,34.48,'C'); 
        _cp[8] = cpk.CPK(_max[8],_min[8],avr[8],_stdev[8],70.83,71.43,'C');

        _cpkl[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'L'); 
        _cpkl[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'L'); 
        _cpkl[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'L');
        _cpkl[3] = cpk.CPK(_max[3],_min[3],avr[3],_stdev[3],25.0,75.0,'L'); 
        _cpkl[4] = cpk.CPK(_max[4],_min[4],avr[4],_stdev[4],54.85,55.45,'L'); 
        _cpkl[5] = cpk.CPK(_max[5],_min[5],avr[5],_stdev[5],78.16,78.76,'L');
        _cpkl[6] = cpk.CPK(_max[6],_min[6],avr[6],_stdev[6],25.0,75.0,'L'); 
        _cpkl[7] = cpk.CPK(_max[7],_min[7],avr[7],_stdev[7],54.85,55.45,'L'); 
        _cpkl[8] = cpk.CPK(_max[8],_min[8],avr[8],_stdev[8],67,67.6,'L');

        _cpku[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'U'); 
        _cpku[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'U'); 
        _cpku[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'U');
        _cpku[3] = cpk.CPK(_max[3],_min[3],avr[3],_stdev[3],25.0,75.0,'U'); 
        _cpku[4] = cpk.CPK(_max[4],_min[4],avr[4],_stdev[4],54.85,55.45,'U'); 
        _cpku[5] = cpk.CPK(_max[5],_min[5],avr[5],_stdev[5],78.16,78.76,'U');
        _cpku[6] = cpk.CPK(_max[6],_min[6],avr[6],_stdev[6],25.0,75.0,'U'); 
        _cpku[7] = cpk.CPK(_max[7],_min[7],avr[7],_stdev[7],54.85,55.45,'U'); 
        _cpku[8] = cpk.CPK(_max[8],_min[8],avr[8],_stdev[8],67,67.6,'U');

        _cpk[0] = cpk.CPK(_max[0],_min[0],avr[0],_stdev[0],300.0,600.0,'N'); 
        _cpk[1] = cpk.CPK(_max[1],_min[1],avr[1],_stdev[1],34.1,34.7,'N'); 
        _cpk[2] = cpk.CPK(_max[2],_min[2],avr[2],_stdev[2],71.81,72.41,'N');
        _cpk[3] = cpk.CPK(_max[3],_min[3],avr[3],_stdev[3],25.0,75.0,'N'); 
        _cpk[4] = cpk.CPK(_max[4],_min[4],avr[4],_stdev[4],54.85,55.45,'N'); 
        _cpk[5] = cpk.CPK(_max[5],_min[5],avr[5],_stdev[5],78.16,78.76,'N');
        _cpk[6] = cpk.CPK(_max[6],_min[6],avr[6],_stdev[6],25.0,75.0,'N'); 
        _cpk[7] = cpk.CPK(_max[7],_min[7],avr[7],_stdev[7],54.85,55.45,'N'); 
        _cpk[8] = cpk.CPK(_max[8],_min[8],avr[8],_stdev[8],67,67.6,'N');  

        fout << "CPK" << ',' <<"REPORT HADEN COVER" << endl; 
        fout << ' ' << ',' << "Norminal Value(cc)" << ',' << 600
            << ',' << "Norminal Value(mm)" << ',' << 34.4
            << ',' << "Norminal Value(mm)" << ',' << 72.11
            << ',' << "Norminal Value(cc)" << ',' << 50
            << ',' << "Norminal Value(mm)" << ',' << 55.15
            << ',' << "Norminal Value(nn)" << ',' << 78.46
            << ',' << "Norminal Value(cc)" << ',' << 50
            << ',' << "Norminal Value(mm)" << ',' << 55.15
            << ',' << "Norminal Value(mm)" << ',' << 67.3 << "\n";

        fout << ' ' << ',' << "Tolerances" << ',' << 300
            << ',' << "Tolerances" << ',' << 0.3
            << ',' << "Tolerances" << ',' << 0.3  
            << ',' << "Tolerances" << ',' << 25
            << ',' << "Tolerances" << ',' << 0.3
            << ',' << "Tolerances" << ',' << 0.3 
            << ',' << "Tolerances" << ',' << 25
            << ',' << "Tolerances" << ',' << 0.3
            << ',' << "Tolerances" << ',' << 0.3 << "\n";
        
        fout << ' ' << ',' << "USL" << ',' << 900
            << ',' << "USL" << ',' << 34.7
            << ',' << "USL" << ',' << 72.41 
            << ',' << "USL" << ',' << 75
            << ',' << "USL" << ',' << 55.45
            << ',' << "USL" << ',' << 78.76 
            << ',' << "USL" << ',' << 75
            << ',' << "USL" << ',' << 55.45
            << ',' << "USL" << ',' << 67.6 << "\n"; 

        fout << ' ' << ',' << "LSL" << ',' << 300
            << ',' << "LSL" << ',' << 34.1
            << ',' << "LSL" << ',' << 71.81
            << ',' << "LSL" << ',' << 25
            << ',' << "LSL" << ',' << 54.85
            << ',' << "LSL" << ',' << 78.16 
            << ',' << "LSL" << ',' << 25
            << ',' << "LSL" << ',' << 54.85
            << ',' << "LSL" << ',' << 67 << "\n"; 
        
        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Std Dev" << ',' << _stdev[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Mean" << ',' << avr[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Maximum" << ',' << _max[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Minimum" << ',' << _min[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Cp" << ',' << _cp[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Cpkl" << ',' << _cpkl[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Cpku" << ',' << _cpku[i];
        }
        fout << "\n"; 

        fout << ' ' ; 
        for (size_t i = 0; i <= 8; i++)
        {
            fout << ',' << "Cpk" << ',' << _cpk[i];
        }
        fout << "\n" << "\n"; 

        fout << "Piece" << ',' <<',' << "Volume_A" << ',' << ','<< "PositionX_A" << ',' << ',' << "PositionY_A" 
            << ',' <<',' << "Volume_B" << ',' << ','<< "PositionX_B" << ',' << ',' << "PositionY_B" 
            << ',' <<',' << "Volume_C" << ',' << ','<< "PositionX_C" << ',' << ',' << "PositionY_C" 
            << endl; 
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
                fout << *d_ptr << ',' << ',';
            }
            if (count == 3)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 4)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 5)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 6)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 7)
            {
                fout << *d_ptr << ',' << ',';
            }
            if (count == 8)
            {
                fout << *d_ptr << ',' << "\n";
            }
            count++; 
            if (count > 8)
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