
#define NRANSI
#include "nrutil.h"

int nn;
float *fvec;
void (*nrfuncv)(int n, float v[], float f[]);

float fmin_(float x[])
{
	int i;
	float sum;

	(*nrfuncv)(nn,x,fvec);
	for (sum=0.0,i=1;i<=nn;i++) sum += SQR(fvec[i]);
	return 0.5*sum;
}
#undef NRANSI
