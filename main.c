#include <stdio.h>
#include <stdlib.h>
void change5(int i,int w, int *m)
{
    int k=i+1,t;
    while (m[k*w+i]==0) k++;
    if (k<w-1)
    for (int j=0; j<w; j++)
    {
      t=m[w*i+j];
      m[w*i+j]=m[k*w+j];
      m[k*w+j]=t;
    }
}
void change6(int i,float *w, float *m,int h)
{
    int k=i+1;
    float t;
    while (abs(m[i*h+k])<=0.001) k++;
    for (int j=0;j<h;j++)
    {
        t=m[j*h+i];
        m[j*h+i]=m[j*h+k];
        m[j*h+k]=t;
        t=w[j*h+i];
        w[j*h+i]=w[j*h+k];
        w[j*h+k]=t;
    }

}
void t9_5()
{
    int n,*m,w,h;
   double z;
   printf("Enter amount of variables: \n");
   scanf("%d",&n);
   printf("\nEnter equations: \n");
  m = malloc(sizeof(int)*n*(n+1));
   h=n;
   w=n+1;
   for (int i=0;i<n;i++)
    for (int j=0;j<n+1;j++)
     scanf("%d",&m[i*w+j]);
   int a;
     for (int i=0;i<h-1;i++)
        for (int j=i+1;j<h;j++)
        {
         if (m[w*i+i]==0) change5(i,w,m);
         a=m[w*j+i];
         if (a!=0)
            for (int k=i;k<w;k++)
        {
            m[w*j+k]= ((m[w*j+k]*m[w*i+i]) - (a*m[w*i+k]));
        }
        }
        for (int i=h-1;i>=1;i--)
        for (int j=i-1;j>=0;j--)
          { for (int k=0;k<i;k++)
            m[w*j+k]=m[w*j+k]*m[w*i+i];
            m[w*j+w-1]= m[w*j+w-1]*m[w*i+i] - m[w*i+w-1]*m[w*j+i];
            m[w*j+i]=0;
           }
   for (int i=0;i<h;i++)
    {
        z=m[w*i+w-1]/m[w*i+i];
        printf("\n x[%d]=%.3f \n ",i,z);
    }
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
    for (int i=0;i<h;i++)
     for (int j=0; j<h;j++)
     {
         mb[i*h+j]=mb[i*h+j]*w[j*h+i];
     }
    for (int i=0;i<h;i++)
    {
    printf("\n");
    for (int j=0;j<h;j++)
        printf("%.3f ",mb[i*h+j]);
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
 printf("Choose task:\n1.\n5.\n6.\n");
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
 t9_6;
 break;
 }

}
