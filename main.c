#include <stdio.h>
#include <stdlib.h>
void change5(int i,int *x, int *m,int h)
{
    int k=i+1;
    float t;
    while (abs(m[k*h+i])<=0.001) k++;
    for (int j=0;j<h;j++)
    {
        t=m[i*h+j];
        m[i*h+j]=m[k*h+j];
        m[k*h+j]=t;
    }
    t=x[i];
    x[i]=x[k];
    x[k]=t;
}
void change6(int i,float *w, float *m,int h)
{
    int k=i+1;
    float t;
    while (abs(m[k*h+i])<=0.001) k++;
    for (int j=0;j<h;j++)
    {
        t=m[i*h+j];
        m[i*h+j]=m[k*h+j];
        m[k*h+j]=t;
        t=w[i*h+j];
        w[i*h+j]=w[k*h+j];
        w[k*h+j]=t;
    }

}
void t9_5()
{
    int h;
    float *m,*x;
   double z;
   printf("Enter amount of variables: \n");
   scanf("%d",&h);
   printf("\nEnter equations: \n");
  m = malloc(sizeof(float)*h*h);
  x = malloc(sizeof(float)*h);
  for (int i=0;i<h;i++)
    for(int j=0;j<h+1;j++)
  {
      if (j==h)
        scanf("%f",&x[i]);
      else
        scanf("%f",&m[i*h+j]);
  }

   float a,d;
     for (int i=0;i<h-1;i++)
        for (int j=i+1;j<h;j++)
        {
         if (abs(m[h*i+i])<0.0001) change5(i,x,m,h);
         a=m[h*j+i];
         d=m[h*j+i]/m[h*i+i];
         if (a!=0)
            for (int k=0;k<h;k++)
        {
            m[h*j+k]= (m[h*j+k]) - d*m[h*i+k];
        }
        x[j]=x[j]-d*x[i];
        }
    for (int i=h-1;i>=1;i--)
        for (int j=i-1;j>=0;j--)
        {
        d=m[h*j+i]/m[h*i+i];
        x[j]=x[j]-x[i]*d;
        m[h*j+i]=0;
        }
     for (int j=0;j<h;j++)
        x[j]=x[j]/m[j*h+j];
    for (int j=0;j<h;j++)
        printf("\nx[%d]=%.3f \n",j,x[j]);

}
void t9_6()
{
    float *m,*w,*mb;
   int h;
   printf("Enter size: \n");
   scanf("%d",&h);
   printf("\nEnter matrix: \n");
  m = malloc(sizeof(float)*h*h);
  w = malloc(sizeof(float)*h*h);
  mb = malloc(sizeof(float)*h*h);
   for (int i=0;i<h;i++)
    for (int j=0;j<h;j++)
    {
     if (j==i)
     {
     w[i*h+j]=1;
     }
     else
     w[i*h+j] = 0;
     scanf("%f",&m[i*h+j]);
     mb[i*h+j]=m[i*h+j];
    }
    //
    float a,d;
     for (int i=0;i<h-1;i++)
        for (int j=i+1;j<h;j++)
        {
         if (abs(m[h*i+i])<0.0001) change6(i,w,m,h);
         a=m[h*j+i];
         d=m[h*j+i]/m[h*i+i];
         if (a!=0)
            for (int k=0;k<h;k++)
        {
            w[h*j+k] = w[h*j+k] - d*w[h*i+k];
            m[h*j+k]= (m[h*j+k]) - d*m[h*i+k];
        }
        }
    for (int i=h-1;i>=1;i--)
        for (int j=i-1;j>=0;j--)
        {
        d=m[h*j+i]/m[h*i+i];
          for(int k=0;k<h;k++)
            w[h*j+k]=(w[h*j+k] - w[h*i+k]*d);
        m[h*j+i]=0;
        }
        for (int i=0;i<h;i++)
    {
     for (int j=0;j<h;j++)
        w[i*h+j]=w[i*h+j]/m[i*h+i];
     m[i*h+i]=1;
    }
   //
   printf("Inverse matrix:\n");
   for (int i=0;i<h;i++)
    {
    printf("\n");
    for (int j=0;j<h;j++)
        printf("%.3f ",w[i*h+j]);
    }
    printf("\nCheck: matrix * matrix(-1) =\n");
    for(int i = 0; i < h; i++)
    for(int j = 0; j < h; j++)
    {
        m[i*h+j]=0;
        for(int k = 0; k < h; k++)
             m[i*h+j] += mb[i*h+k] * w[k*h+j];
    }
    for (int i=0;i<h;i++)
    {
    printf("\n");
    for (int j=0;j<h;j++)
        printf("%.3f ",m[i*h+j]);
    }
}
void t9_1()
{
const m=2;
const n=3;
    int *d1,d2[m][n],l;
    printf("Enter massive:\n");
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
        scanf("%d",&d2[i][j]);
    d1=malloc(m*n*sizeof(int));
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            d1[i*n+j]=d2[i][j];
    printf("==>>\n");
     for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            printf("%d ",d1[i*n+j]);
    printf("\n<<==\n");
    l=m*n;
    for (int i=0;i<l;i++)
        d2[i/n][i%n]=d1[i];
     for (int i=0;i<m;i++)
     { printf("\n");
        for (int j=0;j<n;j++)
            printf("%d ",d2[i][j]);
}
}
int main()
{
 int c;
 while(c!=0)
 {
 printf("Choose task:\n1.\n5.\n6.\n or print 0 to end program\n");
 scanf("%d",&c);
 switch(c)
 {
 case 1:
  t9_1();
  break;
 case 5:
    t9_5();
    break;
 case 6:
 t9_6();
 break;
 }
 }
}
