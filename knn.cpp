#include<bits/stdc++.h>
using namespace std;
char str[100],strt[100];
double sp,sw,pl,pw,dclass[1000],spt,swt,plt,pwt;
double a[200][5]={0},dst[1000];
int main()
{
    FILE *fp=fopen("iris_training.txt","r"),*fp1=fopen("testing.txt","r");
    int i=0,sz,j,k,kval;
    cout<<"enter the value of k";
    cin>>kval;

    while(fscanf(fp,"%lf%lf%lf%lf%s",&sp,&sw,&pl,&pw,str)!=EOF)
    {
        a[i][0]=sp;
        a[i][1]=sw;
        a[i][2]=pl;
        a[i][3]=pw;
        if(strcmp(str,"Iris-setosa")==0)
        {
            a[i][4]=1;
        }
        else if(strcmp(str,"Iris-versicolor")==0)
        {
            a[i][4]=2;
        }
        else if(strcmp(str,"Iris-virginica")==0)
        {
            a[i][4]=3;
        }
        i++;
    }
    sz=i;
    //fclose(fp);

    double distance,val;
    while(fscanf(fp1,"%lf%lf%lf%lf",&spt,&swt,&plt,&pwt)!=EOF)
    {
     for(i=0;i<sz;i++)
     {
         val=((a[i][0]-spt)*(a[i][0]-spt))+((a[i][1]-swt)*(a[i][1]-swt))+((a[i][2]-plt)*(a[i][2]-plt))+((a[i][3]-pwt)*(a[i][3]-pwt));

         distance=sqrt(val);
         //cout<<"distance "<<distance<<"\n";
         dst[i]=distance;
         dclass[i]=a[i][4];


     }
     for(j=0;j<sz-1;j++)
     {
         for(k=j+1;k<sz;k++)
         {
             if(dst[j]>dst[k])
             {
                 double temp=dst[j];
                 dst[j]=dst[k];
                 dst[k]=temp;

                 int temp1=dclass[j];
                 dclass[j]=dclass[k];
                 dclass[k]=temp1;

             }
         }
     }

     int c1=0,c2=0,c3=0;

     for(j=0;j<kval;j++)
     {
         if(dclass[j]==1)
         {
             c1++;
         }
         else if(dclass[j]==2)
         {
             c2++;
         }
         else
            c3++;

            //cout<<"dstance and class "<<dst[j]<<" "<<dclass[j]<<"\n";
     }
     //int maximun=0;
     if(c1>=c2 && c1>=c3)
     {
         cout<<"Iris-setosa";
     }
     else if(c2>c1 && c2>c3)
     {
         cout<<"Iris-versicolor";
     }
     else
        cout<<"Iris-virginica";

        cout<<" c1= "<<c1<<" c2="<<c2<<" c3="<<c3;

      cout<<"\n";

    }



  return 0;

}
