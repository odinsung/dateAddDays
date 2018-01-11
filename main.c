#include <stdio.h>

typedef unsigned char	uchar;
typedef unsigned int 	uint;
typedef unsigned long 	ulong;
typedef unsigned char	bool;

#define true 	1
#define false 	0

typedef struct{
	uint Year;
	uint Month;
	uint Day;
}Date_t;

bool isLeapYear(uint year){
	if ((year % 4) 	 != 0){ return false; }
	if ((year % 100) != 0){ return true;  }
	if ((year % 400) != 0){ return false; }
	return true;	
}

Date_t dateAddDays(Date_t src, uint days){
	Date_t 	dt 				= src;
	uint 	monthDays[13] 	= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	uint 	tmpDays 		= days;
	
	if (isLeapYear(dt.Year)){
		monthDays[2] = 29;
	}
	while(tmpDays > (monthDays[dt.Month] - dt.Day)){
		tmpDays -= (monthDays[dt.Month] - dt.Day);
		if (dt.Month == 12){
			dt.Month = 1;
			dt.Year++;
			monthDays[2] = isLeapYear(dt.Year)? 29 : 28;
		}else{
			dt.Month++;
		}
		dt.Day = 0;
	}
	dt.Day += tmpDays;
	return dt;
}

int main(int argc, char** argv) {
	
	Date_t dt1 = {2018, 1, 15};			// Example: 2018/1/15 + 45 days
	Date_t dt2 = dateAddDays(dt1, 45);
	
	printf("Result date = %d/%d/%d\n", dt2.Year, dt2.Month, dt2.Day);
	
	return 0;
}

