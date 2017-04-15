#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

//#define k 1
#define left -150
#define right 150
#define size ((2*right + 1)*(2*right + 1))
using namespace std;

struct Film {
	int x;
	int y;
	int z = 0;
	double power;
};

struct Point {
	int x;
	int y;
	int z;
};

void print_film(Point *a) {
	for (auto i = 0; i < sqrt(size); i++) {
		for (auto j = 0; sqrt(size); j++) {
			cout << a[i].x << a[i].y << a[i].z << endl;
		}
	}
}

void print_film_cordinats(Point *a) {
	for (int k = 0; k < size; k++) {
		cout << "(";
		cout << a[k].x << ";";
		cout << a[k].y << ";";
		cout << a[k].z;
		cout << ")";
		cout << "\n";
	}	
}

void create_film (Point *a) {
	auto k = 0;
	for(int i = left; i < right + 1; i++) {
		for(int j = left; j < right + 1; j++) {
			a[k].x = i;
			a[k].y = j;
			a[k].z = 0;
			k++;
		}
	}
}

int main()
{
	Point source;
	source.x = 0;
	source.y = 0;
	source.z = 5*512;
	Point xray_film[size];
	create_film(xray_film);
	//print_film_cordinats(xray_film);
	//print_film(xray_film);
	return 0;
}
