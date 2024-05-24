#include <stdio.h>
#include <stdlib.h>
#include "jam.c"
#include "jam.h"

int main (){
	JAM J,J2;
	CreateJam(&J,10, 3, 20 );
 	PrintJam(J);
 	printf("\nGet Hour :%d",GetHour(J));
 	printf("\nGet Minute :%d",GetMinute(J));
 	printf("\nGet Second :%d",GetSecond(J));
 	return 0;
}


