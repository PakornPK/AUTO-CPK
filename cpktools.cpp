#include "cpktools.hh"

double CPKTools::MAX(vector<double> data){
    double max; 
    return max = *max_element(data.begin(),data.end());
}

double CPKTools::MIN(vector<double> data){
    double min; 
    return min = *min_element(data.begin(),data.end());
}

double CPKTools::AVR(vector<double> data){
    double avr; 
    return avr = accumulate(data.begin(),data.end(),0.0)/data.size(); 
}

double CPKTools::RANGE(vector<double> data){
    double rang,maxx,minn; 
    maxx = *max_element(data.begin(),data.end()); 
    minn = *min_element(data.begin(),data.end());
    return rang = maxx - minn;  
}

double CPKTools::STDEV(vector<double> data){
    vector<double> data2; 
    vector<double>::iterator ptr; 
    double power_num, rtop, rbot, zixma_v2,sum_v,SD_v;

    for (ptr =data.begin(); ptr != data.end(); ++ptr)
    {
        power_num = 0; 
        power_num += pow(*ptr,2);
        data2.push_back(power_num);
    }

    sum_v = accumulate(data.begin(),data.end(),0.0);
    zixma_v2 = accumulate(data2.begin(),data2.end(),0.0);
    rtop = ((data2.size())*zixma_v2)-pow(sum_v,2);
    rbot = data2.size()*(data2.size()-1);
    SD_v = sqrt(rtop/rbot);
    return SD_v; 
}

double CPKTools::CPK(double maxx, double minn , double avr , double stdev, double lsl, double usl, char select){
    vector<double> cpk_select; 
    double cp, cpk, cpkl, cpku; 

    cp = (maxx-minn)/(6*stdev); 
    cpkl = (avr-minn)/(3*stdev);
    cpku = (maxx-avr)/(3*stdev);
    cpk_select.push_back(cpkl);
    cpk_select.push_back(cpku);

    if (select == 'N')
    {
        return cpk  = *min_element(cpk_select.begin(),cpk_select.end());
    }else if (select == 'L')
    {
        return cpkl; 
    }else if (select == 'U')
    {
        return cpku; 
    }else if (select == 'C')
    {
        return cp; 
    }else    
    {
        cout << "Error function : N = normal CPK ,L = lower CPK ,U = Upper CPK ,C = Cp" << endl;
        return -1; 
    }
}

