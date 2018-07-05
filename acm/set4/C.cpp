#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const double PI = 3.141592653589792;
int n, f;
double pies[10005];

double cakes(double r) {
	return PI * r * r;
}

int check(double num){
	int	cnt = 0;
    double temps = pies[0];
	for(int i = 0; i < n;){
		if(temps - num > 0) {
			cnt += 1;
            temps -= num;
		} else {
			i+= 1;
            temps = pies[i];
		}
	}
	return cnt >= f;
}


int main()
{
	int T;
	cin >> T;
	while(T--){
		cin >> n >> f;
		f+=1;
		double max, min;
		double sum=0;
		for(int i = 0; i < n; i++){
			scanf("%lf", &pies[i]);
			if(i == 0){
				max = pies[0];
				min = pies[0];
			} else {
				if(pies[i] > max){
					max = pies[i];
				}
				if(pies[i] < min){
					min = pies[i];
				}
			}
		}
        max = cakes(max); min = cakes(min);
        for(int i = 0; i < n; i++){
            pies[i] = cakes(pies[i]);
        }
        for(int i = 0; i < n; i++) {sum += pies[i];}
		double l = min/f, r = sum/f;
		while(fabs(r-l) > 0.00000001){
			double mid = (r+l) / 2;
			if(check(mid)){
				l = mid;
			} else {
				r = mid;
			}
		}
	    printf("%.4f\n", l);
	}
	return 0;
}

