#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>

#define exp 2.71828182846
#define lambda 1.1
#define mu 0.97


using namespace std;

double incom_prob(int ticks) 
{
    double res = 1.0 - pow(exp, -(lambda * (double)ticks));
    
    /*if (res == 1.0) {
	return 1;
    } else {
	return 0;
    }*/
    return res;
}

double handl_prob(int ticks)
{
    double res = 1.0 - pow(exp, -(mu * (double)ticks));
    
    /*if (res == 1.0) {
	return 1;
    } else {
	return 0;
    }*/
    return res;
}

int main () 
{
    int queue = 0;
    int stat_req = 0;
    int stat_handl = 0;
    srand(time(NULL));
    bool isBusy = false;
    
    int ticks_incom = 0;
    int ticks_handl = 0;
    for(int i = 0; i < 1000; i++) 
    {
	ticks_incom++;
	ticks_handl++;
	//double p = (double)rand()%RAND_MAX;
	//double p1 = (double)rand()%RAND_MAX;
	
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	
	double p1 = dis(gen);
	double p = dis(gen);
	//cout << p1 << '\n';
	//bool isBusy = incom_prob(ticks_incom);
	if (p < incom_prob(ticks_incom)) {
	    isBusy = true;
	    queue++;
	    stat_req++;
	    ticks_incom = 0;
	}	
	
	if (p1 < handl_prob(ticks_handl) && queue > 0) {
	    isBusy = false;
	    queue--;
	    stat_handl++;
	    ticks_handl = 0;
	}
	if (isBusy) {
	    //cout << "Такт "<< i << "  Принятых задач: "<< stat_req << "  Выполненных задач: " << stat_handl << "  Задач в очереди: "<< queue << '\n';
	    cout << i << '\t' << queue << '\n';
	}
    }
    //cout << "Такт "<< 1000 << "  Принятых задач: "<< stat_req << "  Выполненных задач: " << stat_handl << "  Задач в очереди: "<< queue << '\n';
    cout << 1000 << '\t' << queue << '\n';
    
    return 0;
}