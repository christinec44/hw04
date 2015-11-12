#include <stdio.h>
#include <math.h>
/*When compiling add -lm*/

struct point2d
{
	double x;
	double y;
};

struct triangle
{
	struct point2d a;
	struct point2d b;
	struct point2d c;
};


double distance1 (struct triangle t);


double distance (struct point2d x, struct point2d y);

/*Calculate the distance of points B-C*/
double distance (struct point2d a, struct point2d b)
{
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

double area(struct triangle t);
/*Calculate the area of a triangle*/
double area(struct triangle t)
{
	return fabs(0.5*( (t.c.x-t.a.x)*(t.b.y-t.a.y) - (t.c.y-t.a.y)*(t.b.x-t.a.x)));
}

int main(void)
{
	struct triangle t1;
	double s, d1, d2, d3, r;


/*initialization*/

t1.a=(struct point2d) {2., 2.};
t1.b=(struct point2d) {-2.,1.};
t1.c=(struct point2d) {0.,-3.};

s=area(t1);
printf("Area of Triangle: %14.6f\n", s);

//d1=distance1(t1);
d1=distance(t1.c, t1.a);
printf("Distance C-A: %14.6f\n", d1);

//d2=distance2(t1);
d2=distance(t1.a, t1.b);
printf("Distance A-B: %14.6f\n", d2);

//d3=distance3(t1);
d3=distance(t1.c, t1.b);
printf("Distance B-C:  %14.6f\n", d3);

r=(2*area(t1))/(d1+d2+d3);
printf("The radius of a circle inscribed in this triangle is:  %14.6f\n",r);

return 0;
}


