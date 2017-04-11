#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>

using namespace std;

#define lambda 0.5
double mu;


double prob_inc(int tact)
{
    return (1 - exp(-lambda * (double)tact));
}

double prob_end(int tact)
{
    return (1 - exp(-mu * (double)tact));
}

int main()
{
	
	int Notk, Nobr, Tpr;
	int N_tacts, post;
	double C1, C2, C3, C4, E, E_max;
	double mu_max;
	
	C1 = 1;
	C2 = 0.5;
	C3 = 0.15;
	C4 = 0.2;
	E_max = 0;
	
	N_tacts = 1000;
	mu = 0.1;
	while( mu < 1 )
	{
		int N_tmp = N_tacts;
		Notk = Nobr = Tpr = post = 0;
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<> dist(0.0, 1.0);
		int tact_inc, tact_end;
		tact_inc = tact_end = 0;
		
		bool isBusy = false;
		for(int i = 0; i < N_tmp; i++)
		{
		    tact_inc++;
		    tact_end++;
		    double p1 = dist(gen);
		    double p2 = dist(gen);
		    
		    if( p1 < prob_inc(tact_inc) && !isBusy )
		    {
			isBusy = true;
			tact_inc = 0;
		    } else if( !isBusy )
		    {
			Tpr++;
		    }
		    
		    if( p1 < prob_inc(tact_inc) && isBusy )
		    {
			Notk++;
		    }
		    
		    if( p2 < prob_end(tact_end) && isBusy )
		    {
			Nobr++;
			tact_end = 0;
			isBusy = false;
		    }
		    
		}
		E = (C1 - C2) * Nobr - C3 * Notk - C4 * Tpr;
		//cout << Nobr << " " << Notk << " " << Tpr << " ";
		cout << E << '\t' << lambda/mu << endl;
		if( E > E_max )
		{
			E_max = E;
			mu_max = mu;
		}
		mu += 0.1;
	}
	cout << endl;
	//cout << E_max << " " << mu_max << endl;
	return 0;
}
