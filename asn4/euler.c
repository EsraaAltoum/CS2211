#include <stdio.h>
double factorial(int n);
double euler(double epsilon);

int main(void){
	char ans = 'y';
	double ep;
	while(ans == 'Y' || ans == 'y'){

		printf("epsilon = ");
		scanf(" %lf", &ep);
		double e = euler(ep);
		printf("e = %lf\n\n", e);
		printf("would you like to try another value (y/n): ");
		scanf(" %c", &ans);
	}
	// double ep = 0.0001;
	// double e = euler(ep);
	// printf("\nepsilon = %f, e = %f", ep, e);
}

double factorial(int n){
	double n_fact = 1;
	for(int i = 1; i<=n; i++)
		n_fact *= i;
	return n_fact;
}

double euler(double epsilon){
	double limit = 1 / epsilon;
	double e = 1;
	for(int n = 1; n < limit; n++){
		double n_fact = factorial(n);
		if(n_fact > limit) break;
		e = e + 1 / n_fact;
	}
	return e;
}