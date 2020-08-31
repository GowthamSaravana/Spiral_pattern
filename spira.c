#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char str[100];
    scanf("%d",&n);
    int spiral[n][n];
    int mrow,maxr,mcol,maxc;
    int value=n*n;
    if(n%2!=0)
    {
    mrow=0;
    maxr=n-1;
    mcol=0;
    maxc=n-1;
    while(value>=1){
        for(int i=mcol;i<=maxc;i++)
        {
            spiral[mrow][i]=value;
            value--;
        }
        for(int i=mrow+1;i<=maxr;i++)
        {
            spiral[i][maxc]=value;
            value--;
        }
        for(int i=maxc-1;i>=mcol;i--)
        {
            spiral[maxr][i]=value;
            value--;
        }
        for(int i=maxr-1;i>=mrow+1;i--)
        {

            spiral[i][mcol]=value;
            value--;
        }
        mrow++;
        maxr--;
        mcol++;
        maxc--;

    }
    }
    if(n%2==0)
    {
        mrow=0;
        maxr=n-1;
        mcol=0;
        maxc=n-1;
        while(value>=1)
        {
            for(int i=maxc;i>=mcol;i--)
            {
                spiral[maxr][i]=value;
                value--;
            }
            for(int i=maxr-1;i>=mrow;i--)
            {
                spiral[i][mrow]=value;
                value--;
            }

            for(int i=mcol+1;i<=maxc;i++)
            {
                spiral[mcol][i]=value;
                value--;
            }
            for(int i=mrow+1;i<=maxr-1;i++)
            {
                spiral[i][maxc]=value;
                value--;
            }
                mrow++;
                mcol++;
                maxr--;
                maxc--;

        }
    }
    for(int i=0;i<n;i++,printf("\n"))
    {
        for(int j=0;j<n;j++)
            printf("%d ",spiral[i][j]);
    }
    int index_i,index_j;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(spiral[i][j]==1)
            {
                index_i=i;
                index_j=j;
                break;
            }
        }
    }
    scanf("%s",&str);
    int result;
    int k=0;
    while(k<strlen(str))
    {
      for(int i=index_i;i<n;i++)
        {
            for(int j=index_j;j<n;j++)
            {

                 if(str[k]=='L' ||str[k]=='l')
                {
                    index_i=index_i;
                    index_j=index_j-1;
                    break;
                }
                else if(str[k]=='R' || str[k]=='r')
                {
                    index_i=index_i;
                    index_j=index_j+1;
                    break;

                }else if(str[k]=='U' || str[k]=='u')
                {
                    index_i=index_i-1;
                    index_j=index_j;
                    break;

                }else if(str[k]=='D' || str[k]=='d')
                {
                    index_i=index_i+1;
                    index_j=index_j;
                    break;

                }
            }
            k++;
        }

    }

    if((index_i>=0 && index_i<n)&&(index_j>=0 && index_j<n))
    {
        result=spiral[index_i][index_j];
        printf("%d",result);
    }
    else
        printf("-1");

}
