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
           std::cout<<"��ʱ��������Ϊ:"<<(*v)<<",idxΪ:"<<idx<<",m+1Ϊ:"<<(m+1)<<",һ�ֿ���Ϊ:";
		   (*max)=curr_value;
           std::cout<<"���ֵ����Ϊ:"<<(*max)<<"\n";
           for(int i=0;i<m;i++)
		   {
			  std::cout<<last[i]<<" ";
		   }
		   std::cout<<"\n\n";
		}
		else {
			std::cout<<"�ⲻ��һ�����Ž�\n\n";
		}
		return;
	}
	if(is(s[idx],p,curr_value)){
		last[*v] =s[idx]; 
		std::cout<<(*v)<<"��λ�÷���"<<s[idx]<<", ��ʱidx:"<<idx<<"\n";
		(*v)++;
		deep_plus(v,last,s,m,n,p,max,curr_value+s[idx],idx);
		(*v)--;
		last[*v]=-1;
	}
    std::cout<<"������"<<s[idx]<<", ��ʱidx:"<<idx<<"\n";
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
