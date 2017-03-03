#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(NULL);
    char mas[10] = {'a','b','c','d','e','f','g','h','i','j'};
    char mas_glas[3] = {'a','e','i'};
    char mas_sogl[7] = {'b','c','d','f','g','h','j'};
    char mas1[10], mas2[10], mas3[10];
    int i1, i2, i3;
    i1 = i2 = i3 = 0;
    
    while(1) {
	fd = rand()%4+1;
	switch(fd){
	    case 1: {
			mas1[i1] = mas[i1];
			i1++;
			break;
		    }
	    case 2: {
			for (int i = 0; i < 3; i++) {
			    if (mas[i2] == mas_glas[i]) 
				mas2[i2] = mas[i2];
			}
			i2++;
			break;
		    }
	    case 3: {
			for (int i = 0; i < 7; i++) {
			    if (mas[i3] == mas_sogl[i])
				mas3[i3] = mas[i3];
			}
			i3++;
			break;
		    }
	}
    }

    return 0;
}