#include <stdio.h>
#include <time.h>

const double CLK_TCK = 1000.0;

clock_t start, stop;

double duration;

void func()
{
    printf("This is a function.\n");
}

int main()
{
    start = clock();
    func();
    stop = clock();
    duration = ((double)(stop - start))/CLK_TCK;
    printf("time:%lf", duration);
    return 0;
}
