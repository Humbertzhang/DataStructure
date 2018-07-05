#include <stdio.h>

int isr(int year) {
	if((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int y, m, d;
	while(scanf("%d/%d/%d", &y, &m, &d) != EOF) {
		int days = 0;
		int status = isr(y);
		for(int i = 1; i < m; i++) {
			if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
				days = days + 31;
			} else if (i == 4 || i == 6 || i == 9 || i == 11) {
				days = days + 30;
			} else if (i == 2) {
				days = days + 28 + status;
			}
		}
		days = days + d;
		printf("%d\n", days);
	}
	return 0;
}
