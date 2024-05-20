#include<iostream>
#include<algorithm>
typedef struct bug{
	int num;
	int d;
	int p;
}A;
bool com(const A& a,const A& b)
{
	return a.p>b.p;
}
int *js(A *a,int n,int **b)
{
	int count=0,max=0;
	int *x = new int[n];
	std::sort(a,a+n,com);
    for(int i=0;i<n;i++)
    {
    	if(a[i].d> max)  max=a[i].d;
		if(count<max) x[count++]=a[i].num;	
	}
	**b=count;
	return x;
}
int main()
{
	A a[]={{0,1,3}, {1,3,5},{2,4,20},{3,3,18},{4,2,1},{5,1,6},{6,2,30} };
	//A a[]={{0,2,100},{1,1,10},{2,2,15},{3,1,17}};
	int len = sizeof(a)/sizeof(a[0]);
	int *count=new int;
	int *x=js(a,len,&count);
	for(int i=0;i<(*count);i++)
	{
		std::cout<<x[i]<<" ";
	}
	return 0;
}
