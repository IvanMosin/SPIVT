#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));
    char mas[10] = {'a','b','c','d','e','f','g','h','i','j'};
    char mas_glas[3] = {'a','e','i'};
    char mas_sogl[7] = {'b','c','d','f','g','h','j'};
    char mas1[10], mas2[10], mas3[10];
    int i1, i2, i3;
    i1 = i2 = i3 = 0;
    int fd;
    
    while(1) {
	while(1){
	    fd = rand()%4+1;
	    if(fd == 1 && i1 < 10)
		break;
	    if(fd == 2 && i2 < 10)
		break;	
	    if(fd == 3 && i3 < 10)
		break;
	}
	switch(fd){
	    case 1: {
			mas1[i1] = mas[i1];
			i1++;
			break;
		    }
	    case 2: {
			for (int i = 0; i < 3; i++) {
			    if (mas[i2] == mas_glas[i]) 
				mas2[i] = mas[i2];
			}
			i2++;
			break;
		    }
	    case 3: {
			for (int i = 0; i < 7; i++) {
			    if (mas[i3] == mas_sogl[i])
				mas3[i] = mas[i3];
			}
			i3++;
			break;
		    }
	}
	if (i1 == 10 && i2 == 10 && i3 == 10)
	    break;
    }
    printf("mas1 = ");
    for (int i = 0; i < 10; i++) {
	printf("%c", mas1[i]);
    }	
    printf("\nmas2 = ");
    
    for (int i = 0; i < 3; i++) {
	printf("%c", mas2[i]);
    }
    printf("\nmas3 = ");
    
    for (int i = 0; i < 7; i++) {
	printf("%c", mas3[i]);
    }
    
    return 0;
}