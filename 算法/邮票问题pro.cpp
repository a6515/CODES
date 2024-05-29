#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
bool com(const int&a, const int& b)
{
	return a>b;
}
bool is(int value,int p[],int curr_value)
{
	if(curr_value+value <= p[1]) {
		return true;
	}
	
	return false;

}
void deep_plus(int *v,int last[],int s[],int m,int n,int p[],int *max,int curr_value,int idx)
{
	
	if(idx==m+1 ||curr_value==p[1] || (*v)==m){
		if(curr_value>=(*max)) {
           std::cout<<"此时数组容量为:"<<(*v)<<",idx为:"<<idx<<",m+1为:"<<(m+1)<<",一种可能为:";
		   (*max)=curr_value;
           std::cout<<"最大值更新为:"<<(*max)<<"\n";
           for(int i=0;i<m;i++)
		   {
			  std::cout<<last[i]<<" ";
		   }
		   std::cout<<"\n\n";
		}
		else {
			std::cout<<"这不是一个最优解\n\n";
		}
		return;
	}
	if(is(s[idx],p,curr_value)){
		last[*v] =s[idx]; 
		std::cout<<(*v)<<"号位置放入"<<s[idx]<<", 此时idx:"<<idx<<"\n";
		(*v)++;
		deep_plus(v,last,s,m,n,p,max,curr_value+s[idx],idx);
		(*v)--;
		last[*v]=-1;
	}
    std::cout<<"不放入"<<s[idx]<<", 此时idx:"<<idx<<"\n";
	deep_plus(v,last,s,m,n,p,max,curr_value,idx+1);

}


void deep(int s[],int m,int n,int p[] )
{
	int last[n];
	int max=0,v=0;
	for(int i=0;i<n;i++) last[i]=-1;
	deep_plus(&v,last,s,m,n,p,&max,0,0);
	
}

int main(){
    int n,m;
    int p[2];
    std::cout<<"请输入区间:";
    for(int k=0;k<2;k++)
    {
		std::cin>>p[k];
	}
    std::cout<<"请输入邮票种类个数:";
    std::cin>>n;
    int s[n];
    std::cout<<"请输入邮票面值:";
    for(int i=0;i<n;i++)
    {
		std::cin>>s[i];
	}
    std::cout<<"请输入每张信封可以放几张邮票:";
    std::cin>>m;
    std::sort(s,s+n,com);
    deep(s,m,n,p);
    return 0;
}
