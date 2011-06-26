#include <stdio.h>
#include <math.h>

#define OMEGA_M 0.27
#define T(z) 1.0/((1.0+z)*pow((1.0-OMEGA_M+OMEGA_M*(1.+z)*(1.+z)*(1.+z)),0.5))
int main(void){
	float lookback(float z);
 	float redshift,time;

	printf("Please input the redshift:\n");
	scanf("%f",&redshift);
	time=lookback(redshift);
	printf("The lookback time is %f Gyr\n",time);

	return(0);

}

float lookback(float z)  
{	
	int    n,i;
	float h,tot1,tot2,tot;

	n=10000;
	h=z/(2.0*n);
	tot1=0.0;
	tot2=0.0;
	tot=0.0;

	for(i=1;i<=2*n-1;i+=2) 
			tot1+=T(i*h);
	for(i=2;i<=2*n-2;i+=2)
			tot2+=T(i*h);

	tot=T(0.0)+T(2.0*n);
	tot+=4*tot1+2*tot2;
	tot=h*tot/3.0;
	tot=tot*13.75468;

	return(tot);
				
}	

