#include <iostream>
#include <cmath>
using namespace std;
float f12(float *x)
{
	float fx;
	fx=pow(x[0],4)+pow(x[1],4)+sqrt(2+pow(x[0],2)+pow(x[1],2))-2*x[0]+3*x[1];
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
	eps=0.0000001;
	h=0.2;
	x[0]=1;
	x[1]=1;
	x1[0]=1;
	x1[1]=1;
	x2[0]=1;
	x2[1]=1;
	ff2=f12(x);
	for(i=0;i<1000;i++)
	{
		ff1=ff2;
		f0=f12(x);
		x1[0]=x[0]+h;
		f1=f12(x1);
		x2[0]=x[0]-h;
		f2=f12(x2);
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
		f00=f12(x);
		x1[1]=x[1]+h;
		f11=f12(x1);
		x2[1]=x[1]-h;
		f22=f12(x2);
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
		ff2=f12(x);
	}
	cout<<"Локальный минимум функции: "<<ff2<<" Координаты минимума: х1="<<x[0]<<" х2="<<x[1];
}