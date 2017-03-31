#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <sys/time.h>

#define N 4

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main() 
{
    srand(time(NULL));
    std::vector<std::pair<int, int> > vecPair(N);
    std::pair <int, int> A;
    double way = 0;
    double min_way = 500;
    A.first = rand()%100 + 1;
    A.second = rand()%100 + 1;
    //std::cout << "(" << A.first << "," << A.second << ")\n";

    for(int i = 0; i < N; i++)
    {
        vecPair[i].first = rand()%100 + 1;    
	vecPair[i].second = rand()%100 + 1;
    }

    /*for(int i = 0; i < vecPair.size(); i++)
    {
        std::cout << "(" << vecPair[i].first << "," << vecPair[i].second << ")\n";
    }
    std:: cout << "\n";*/

    /*
    do {
	for(int i = 0; i < vecPair.size(); i++)
	{
    	    std::cout << "(" << vecPair[i].first << "," << vecPair[i].second << ")\n";
	}
	std:: cout << "\n";
    } while(std::next_permutation(vecPair.begin(), vecPair.end()));
    */  
    double t = wtime();
    sort(vecPair.begin(), vecPair.end());  
    do {
	int i = 0;
	way += (double)sqrt(pow((vecPair[i].first - A.first), 2) + pow((vecPair[i].second - A.second), 2));
	while(i != N - 1) {
	    way += (double)sqrt(pow((vecPair[i+1].first - vecPair[i].first), 2) + pow((vecPair[i+1].second - vecPair[i].second), 2));
	    i++;
	}
	way += (double)sqrt(pow((A.first - vecPair[i].first), 2) + pow((A.second - vecPair[i].second), 2));
	
	for(int i = 0; i < N; i++)
	{
    	    std::cout << "(" << vecPair[i].first << "," << vecPair[i].second << ")\n";
	}
	std:: cout <<  way << '\n';
	std:: cout << '\n';
	if(way < min_way){
	    min_way = way;
	}
    } while(std::next_permutation(vecPair.begin(), vecPair.end()));
    
    std:: cout << "\n" <<  min_way << '\n';
    
    t = wtime() - t;

    printf("time: %.6f sec.\n", t);    
    
    return 0;
}