#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
bool com(const int&a, const int& b)
{
	return a>b;
}
int is(int last[], int v, int value,int p[])
{
	int sum=0;
	
	for(int i=0;i<v+1;i++) sum+=last[i];
	
	if((sum+value)>=p[0] && (sum+value)<=p[1] )  return 1;
	
	return 0;
}
int  deep_plus(int v,int last[],int s[],int m,int n,int p[],int *max)
{
	if(v==m) {
		int sum=0;
		for(int i=0;i<m;i++)
		{
			sum+=last[i];
		}
		if(*max<=sum) {
			std::cout<<"���ܵ�ֵΪ:";
			*max  = sum;
			for(int i=0;i<m;i++)
		    {
			    std::cout<<last[i]<<"  ";
		    }
			std::cout<<"\n���ֵΪ:"<<sum;
		    std::cout<<"\n\n";
		    return 0;
		}
		else{
            return 0;
		}
		
	}
	for(int i=0;i<n;i++)
	{
		if(is(last,v,s[i],p)==1) {
			last[v] = s[i];
			deep_plus(v+1,last,s,m,n,p,max);
			last[v]=0;
		}
		
	}
	return 0;
}


void deep(int s[],int m,int n,int p[] )
{
	int last[n];
	int max=0;
	for(int i=0;i<n;i++) last[i]=0;
	deep_plus(0,last,s,m,n,p,&max);
	
}

int main(){
    int n,m;
    int p[2];
    std::cout<<"����������:";
    for(int k=0;k<2;k++)
    {
		std::cin>>p[k];
	}
    std::cout<<"��������Ʊ�������:";
    std::cin>>n;
    int s[n];
    std::cout<<"��������Ʊ��ֵ:";
    for(int i=0;i<n;i++)
    {
		std::cin>>s[i];
	}
    std::cout<<"������ÿ���ŷ���Էż�����Ʊ:";
    std::cin>>m;
    std::sort(s,s+n,com);
    deep(s,m,n,p);
    return 0;
}
