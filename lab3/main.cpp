#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

int *queue;

int stage_sync(int tact, int n_stage, int *stat)
{
	*stat = 0;	
	if( tact == 0 && queue[n_stage] == 1 )
	{
		tact = 10;
		queue[n_stage] = 0;
		*stat = tact;
	}
	//cout << "tact: " << tact << " ";
	if( tact <= 10 && tact > 0 )
	{
		tact--;
		if ( tact == 0 )
		{
			if( queue[n_stage + 1] == 0 )
			{
				queue[n_stage + 1] = 1;
				//cout << "!" << " ";
			} else {
				tact = 1;
				//cout << "?" << endl;
			}
		}
	}
	//cout << queue[n_stage] << " ** " << queue[n_stage + 1] << endl;
	return tact;
}

int stage_async(int tact, int n_stage, int *stat)
{
	*stat = 0;
	if( tact == 0 && queue[n_stage] == 1 )
	{
		tact = rand() % 5 + 6;
		queue[n_stage] = 0;
		*stat = tact;
	}
	//cout << "tact: " << tact << " ";
	if( tact <= 10 && tact > 0 )
	{
		tact--;
		if ( tact == 0 )
		{
			if( queue[n_stage + 1] == 0 )
			{
				queue[n_stage + 1] = 1;
				//cout << "!" << " ";
			} else {
				tact = 1;
				//cout << "?" << endl;
			}
		}
	}
	//cout << queue[n_stage] << " ** " << queue[n_stage + 1] << endl;
	return tact;
}

int pipe(int task, string pipes_type, fstream &out, int N)
{
	int stages_tact[N] = {0};
	int total_count_tact = 0;
	int staistics_tacts[N] = {0};
	queue = new int[N + 1];	
	for(int i = 0; i < N + 1; i++)
		queue[i] = 0;
	
	if( pipes_type == "async" )
	{
		cout << "Asynchronous pipeline." << endl;
		out << "Asynchronous pipeline." << endl;
	}
	if( pipes_type == "sync" )
	{
		cout << "Synchronous pipeline." << endl;
		out << "Synchronous pipeline." << endl;
	}
	out << "task: " << task << endl;	
	while(1)
	{
		for(int i = 0; i < N; i++)
		{
			//cout << "stage: " << i << " ";
			if( i == 0 && stages_tact[0] == 0 && task != 0)
			{
				queue[0] = 1;
				task--;
			} 
			int stat;
			if( pipes_type == "async" )
				stages_tact[i] = stage_async(stages_tact[i], i, &stat);
			if( pipes_type == "sync" )
				stages_tact[i] = stage_sync(stages_tact[i], i, &stat);
			
			staistics_tacts[i] += stat;
			if( i == N - 1 )
				queue[N] = 0;
			//cout << endl;
		}
		total_count_tact++;
		//cout << "total_count_tact = " << total_count_tact << endl;
		//cout << "task: " << task << endl;
		int flag = 0;
		for(int i = 0; i < N; i++)
		{
			if( stages_tact[i] == 0 )
			{
				flag++;
			}
		}
		if( task == 0 && flag == N )
			break;
	}
	
	for(int i = 0; i < N; i++)
	{
		cout << staistics_tacts[i] << endl;
		out << staistics_tacts[i] << endl;
	}
	return total_count_tact;
}

int main()
{
	srand(time(0));
	fstream out;
	out.open("result.txt", ios_base::out | ios_base::app);
	string pipes_type;
	int task;
	int N;
	cout << "Select the type of pipeline (enter 'async' or 'sync'): ";
	cin >> pipes_type;
	cout << "Enter the number of tasks: ";
	cin >> task;
	cout << "Enter the number of stage: ";
	cin >> N;
	
	int result = pipe(task, pipes_type, out, N);
	cout << "Total number clock cycles for pipeline: " << (double)100000/result << endl;
	out << "Total number clock cycles for pipeline: " << (double)100000/result << endl;
	out << endl << "=====================================" << endl;
	out.close();
	return 0;
}
