#include<iostream>
#include<algorithm>

typedef struct b{
	int v;
	int p;
}B;

int max(const int& a,const int& b)
{
	return a>b ? a:b;
}


int dt(int n,B b[],int v)
{
	int dp[n+1][v+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=v;j++)
		{
			if(i==0 || j==0) dp[i][j]=0;
			
			else if((b[i-1].v)<= j) dp[i][j] = max((b[i-1].p)+ dp[i-1][j-(b[i-1].v)], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
		std::cout<<"第"<<i+1<<"次最大价值为:"<<dp[i][v]<<"\n";
	}
	return dp[n][v];
}

int main()
{
   int n,v;
   std::cin>>n>>v;
   B b[n];
   for(int i=0;i<n;i++)
   {
   	 std::cin>>b[i].v>>b[i].p;
   }
   int s = dt(n,b,v);
   std::cout<<"最大价值为:"<<s;
}
