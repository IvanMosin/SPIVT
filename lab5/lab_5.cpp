#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <sys/time.h>
#include <stdio.h>

using namespace std;

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void check_min_tacts(vector< pair<int, int> > detail, int *order_details, int *order_details_min, int *min_tacts)
{
	int N = detail.size();
	
	int sum = 0;
	
	for(int i = 0; i < N + 1; i++)
	{
		if( i == 0 )
			sum += detail[order_details[0] - 1].first;
		else if( i == N )
			sum += detail[order_details[N - 1] - 1].second;
		else 
			if( detail[order_details[i - 1] - 1].second > detail[order_details[i] - 1].first )
				sum += detail[order_details[i - 1] - 1].second;
			else 
				sum += detail[order_details[i] - 1].first;
	}
	//cout << sum;
	if( sum < *min_tacts )
	{
		*min_tacts = sum;
		for(int i = 0; i < N; i++)
			order_details_min[i] = order_details[i];
	}
}
	
int main()
{
	srand(time(0));
	vector< pair<int, int> > detail;
	
	int N;
	
	cout << "Enter the number of details: ";
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		detail.push_back(make_pair(rand()%15 + 1, rand()%15 + 1));
	}
	
	int order_details[20], order_details_min[20], min_tacts = 1000000;
 
	for (int i = 0; i < N; i++)
		order_details[i] = i + 1;
	double t = wtime();
	do{
		//for (int i = 0; i < N; i++)
		//	cout << order_details[i] << " ";
		check_min_tacts(detail, order_details, order_details_min, &min_tacts);
		//cout << endl;
		
 		int j;
		for (j = N - 2 ; j >= 0 && order_details[j+1] < order_details[j]; j--);
		int k = j;
		if (k == -1) break;
 
		for (j = N - 1 ; j >= 0 && order_details[j] < order_details[k]; j--);
		int k2 = j;
 
		swap (order_details[k] , order_details[k2]);
 
		reverse (&order_details[k + 1] , &order_details[N]);
	}while (true);
	
	t = wtime() - t;

	printf("time: %.6f sec.\n", t);
	
	cout << "Minimum number of tacts: " << min_tacts << endl;
	cout << "Order of tacts:" << endl;
	
	for(int i = 0; i < N; i++)
	{
		cout << order_details_min[i] << " ";
	}
	cout << endl;
 	
	/*for(int i = 0; i < N; i++)
	{
		cout << i + 1 << " " << detail[i].first << " " << detail[i].second << endl;
	}*/
	
	return 0;
}
