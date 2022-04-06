#include <iostream>
#include <cmath>
using namespace std;
float f4(float *x)
{
	float fx;
	fx=5*pow((x[0]),2)-4*x[0]*x[1]+5*pow((x[1]),2)-x[0]-x[1];
	return fx;
}
int main()
{
	setlocale(LC_ALL,"Russian");
	int i;
	float *x,*x1,*x2,h,eps,f0,f1,f2,f00,f11,f22,ff1,ff2;
	x=new float[2];
	x1=new float[2];
	x2=new float[2];
	eps=0.00001;
	h=0.001;
	x[0]=0;
	x[1]=0;
	x1[0]=0;
	x1[1]=0;
	x2[0]=0;
	x2[1]=0;
	ff2=f4(x);
	for(i=0;i<1000;i++)
	{
		ff1=ff2;
		f0=f4(x);
		x1[0]=x[0]+h;
		f1=f4(x1);
		x2[0]=x[0]-h;
		f2=f4(x2);
		if(f1<f0)
		{
			x[0]=x1[0];
		}
		else if(f2<f0)
		{
			x[0]=x2[0];
		}
		else
		{
			x[0]=x[0];
		}
		f00=f4(x);
		x1[1]=x[1]+h;
		f11=f4(x1);
		x2[1]=x[1]-h;
		f22=f4(x2);
		if(f11<f00)
		{
			x[1]=x1[1];
		}
		else if(f22<f00)
		{
			x[1]=x2[1];
		}
		else
		{
			x[1]=x[1];
		}
		ff2=f4(x);
		if((ff1-ff2)<eps)
		{
			break;
		}
	}
	cout<<"Минимум функции: "<<ff2<<" Координаты минимума: х1="<<x[0]<<" х2="<<x[1];
}