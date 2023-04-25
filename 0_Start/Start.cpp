#include <iostream>

float func(int num)
{
	printf("doit");
    return num*0.1f;
}

int main()
{
	float (*p) (int);
    p = func;
    p(100);
    printf("%f", p(100));

    return 0;
}
