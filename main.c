#include<stdio.h>
#include<math.h>

//function for analyze
int analyze(float, float, float);
//function for synthesizes
int synthesizes(float, float);
int main()
{
	float W, h, er, Z0;
	int mode;
	//select mode
	//1==>analyze
	//2==>synthesizes
	printf("select mode please:\n1==>analyze\n2==>synthesizes\n");
	scanf("%d",&mode);
	if(mode!=1&&mode!=2)
	{
		printf("select mode please:\n1==>analyze\n2==>synthesizes\n");
	}
	switch(mode)
	{
		case 1:
			//input parameters
			printf("You have selected analyze mode.Please input\nW: ");scanf("%f",&W);
			printf("h:");scanf("%f",&h);
			printf("er:");scanf("%f",&er);
			//check parameters
			if(W<=0||h<=0||er<=0)
			{
				printf("parameters incorrect\n");
				break;
			}
			analyze(W, h, er);
			break;
		case 2:
			//input paremeters
			printf("You have selected synthesizes mode.Please input\nZ0: ");scanf("%f",&Z0);
			printf("er:");scanf("%f",&er);
			//check paremeters
			if(Z0<=0||er<=0)
			{
				printf("parameters incorrect\n");
				break;
			}
			synthesizes(Z0, er);
	}
	return 0;
}

//function of analyze
int analyze(float W, float h, float er)
{
	float Wh, ee, Z0;
	Wh=W/h;
	if(Wh<=1)
	{
		ee=(er+1)/2+(er-1)/2*(pow((1+12/Wh),-1)+0.04*pow(1-Wh,2));
		Z0=60/sqrt(ee)*log(8/Wh+0.25*Wh);
	}
	else
	{
		ee=(er+1)/2+(er-1)/(2*sqrt(1+12/Wh));
		Z0=(120*3.1415926)/(sqrt(ee)*(Wh+1.393+0.667*log(Wh+1.444)));
	}
	printf("Z0==>%f\n",Z0);
	printf("ee==>%f\n",ee);
	return 0;
}
//function of synthesizes
int synthesizes(float Z0, float er)
{
	float A, B, Wh;
	A=Z0/60*sqrt((er+1)/2)+(er-1)/(er+1)*(0.23+0.11/er);
	if(A>1.52)
	{
		Wh=8*exp(A)/(exp(2*A)-2);
	}
	else
	{
		B=60*3.1415926*3.1415926/(Z0*sqrt(er));
		Wh=2/3.14159268*(B-1-log(2*B-1)+(er-1)/(2*er)*(log(B-1)+0.39-0.61/er));
	}
	printf("W/h==>%f\n",Wh);
	return 0;
}
