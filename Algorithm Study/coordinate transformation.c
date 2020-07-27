#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI 3.1415926
#define DTR (PI/180)

void main()
{
	while (1)
	{
		int mode;
		printf("[Select mode] 1 : Polar Coordinate 2 : Cartesian Coordinate\n\nMode : ");
		if (scanf("%d", &mode) == 0)
		{
			printf("\nProgram error! Try again.\n\n");
			getchar();
			continue;
		}
		if (mode != 1 && mode != 2)
		{
			printf("\nWrong number! Try again.\n\n");
			continue;
		}
		if (mode == 1)
		{
			double mag, deg;
			printf("\nSet next values.\n\nMagnitude    : ");
			scanf("%lf", &mag);
			printf("Angle(Degree) : ");
			scanf("%lf", &deg);
			double x = mag * cos(deg * DTR);
			double y = mag * sin(deg * DTR);
			printf("\n* Coordinates transformation result\n\nX value : %.3lf\nY value : %.3lf\n\n", x, y);
		}
		if (mode == 2)
		{
			double x, y;
			printf("\nSet next values.\n\nX value : ");
			scanf("%lf", &x);
			printf("Y value : ");
			scanf("%lf", &y);
			double mag = sqrt(pow(x, 2) + pow(y, 2));
			double deg = asin(y / mag) / DTR;
			printf("\n* Coordinates transformation result\n\nMagnitude     : %.3lf\nAngle(Degree) : %.3lf\n\n", mag, deg);
		}
	}
}