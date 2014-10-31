#include <stdio.h>

main()
{
	int salary, tax;
	float inflation;
	int y;
	
	srand(time(NULL));
	
	salary = 1200;
	inflation = 0.0f;
	for( y=0 ; y<30 ; y++ ) {
		if( y != 0 ) {
			inflation = (rand() % 901 + 100) / 100.0f;
			salary = salary + salary * (inflation + 1) / 100.0f;
		}
		
		//tax = calc_tax(salary);
		if( salary <= 1000 ) {
			tax = (salary * 8) / 100;
		}
		else if( salary <= 4000 ) {
			tax = (1000 * 8) / 100;
			tax += ((salary - 1000) * 17) / 100;
		}
		else if( salary <= 8000 ) {
			tax = (1000 * 8) / 100;
			tax += (3000 * 17) / 100;
			tax += ((salary - 4000) * 26) / 100;
		}
		else {
			tax = (1000 * 8) / 100;
			tax += (3000 * 17) / 100;
			tax += (4000 * 26) / 100;
			tax += ((salary - 8000) * 35) / 100;			
		}
		
		printf("%2d년차 - 연봉:%5d, 근로세:%4d, 실질수입액:%5d, 물가인상률: %.2f\n",
				 y+1, salary, tax, salary-tax, inflation);
	}
}
