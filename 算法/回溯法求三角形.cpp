#include<iostream>
#include<stdlib.h>

int  is(int l,int v[],int s)
{
	int count=0;
	for(int i=0;i<3;i++)
	{
		if(v[i]!=0) count++;
		
	}
	int sum=l+v[0];      //两边之和
	int dif=abs(l-v[0]); //差
	int remain=s-(l+v[0]); //第三条边
	if(count== 0) return 1;
	else if(count==1) {
		if(sum>remain &&dif<remain ) return 1;
		else return 0;
	}
	
	return 0;
}

void hcs(int c,int v[],int s,int *p)  /*c为当前边*/
{
	if(c==2) {
		(*p) ++;
		v[2]=s-v[0]-v[1];
		std::cout<<"一个可行解为: ";
		for(int i=0;i<3;i++)
		{
			std::cout<<v[i]<<" ";
		}
		v[2]=0;
		std::cout<<"\n";
		return;
	}
	for(int i=1;i<=s-2;i++)
	{
		if(is(i,v,s)==1)
		{
			v[c]=i;
			hcs(c+1,v,s,p);
			v[c]=0;
		}
		
	}

}
void hc(int s)
{
	int v[3];
	for(int i=0;i<3;i++) v[i]=0;
	int count=0;
	hcs(0,v,s,&count);
	std::cout<<"\n可行解个数为"<<(count)<<"个.";

	
}
int main()
{
	std::cout<<"计算机222 郭建新 202202313\n";
	std::cout<<"\n";
	int s;
	std::cout<<"请输入三角形的三条边之和:";
	std::cin>>s;
	hc(s);
}
