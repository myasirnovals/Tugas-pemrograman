#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

/* memanfaatkan time.h, primitif yg disediakan bahasa c untuk manipulasi waktu */

int main(){
	//KAMUS
	//typedef long time_t; 
	
	//struct tm
	/* { */
	/* int tm_sec; */ /* seconds */
	/* int tm_min; */ /* minutes */
	/* int tm_hour; */ /* hours */
	/* int tm_mday; */ /* day of the month */
	/* int tm_mon; */ /* month */
	/* int tm_year; */ /* year */
	/* int tm_wday; */ /* day of the week */
	/* int tm_yday; */ /* day in the year */
	/* int tm_isdst; */ /* daylight saving time */
	
	/* definisi variabel yang diperlukan untuk mengambil date dan time */
	time_t now;
	struct tm *T;
	
	/* ALGORITMA */
	printf("memanggil jam dan date dari sistem \n"); now = time (NULL);
	T = localtime (&now);
	printf("Jam = %d:%d:%d \n", T->tm_hour, T->tm_min, T->tm_sec);
	printf("Tanggal = %d-%d-%d \n", T->tm_mday, T->tm_mon+1, T->tm_year+1900);
	printf("local time %s \n", asctime (T));
	
	return 0;
	
}
