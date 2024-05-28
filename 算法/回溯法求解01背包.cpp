#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
typedef struct bug
{
    int num;
    int w;
    int p;
    double s;
}B;

typedef struct bugs
{
    int total_weight;
    int total_vaule;
    B *b;
}BB;

bool com(const B& a,const B& b)
{
    return a.s>b.s;
}

int is(const int& n,const int& w,const std::vector<B>& last,int node,B *b){
    int sum=0;
    for(int i=0;i<n;i++) sum+=last[i].w;
    std::cout<<"��ǰ����Ϊ:"<<sum<<",��Ʒ����Ϊ:"<<b[node].w<<"  ��Ʒ���Ϊ:"<<b[node].num<<"\n";
    if(sum+b[node].w <= w) return 1;
    return -1;

}
void dfs(int n,std::vector<B>& last,B *b, int w,int N,BB *p,int *flag)
{
    std::cout<<"��ǰn��ֵΪ"<<n<<"\n";
     if(n==N )  {
         std::cout<<"������\n";
        for(int i=0;i<last.size();i++)
        {
            std::cout<<"��Ʒ���:"<<last[i].num<<"  ��Ʒ����:"<<b[i].w<<"  ��Ʒ��ֵ:"<<b[i].p<<"\n";
        }
        std::cout<<"\n";
        return;
     }
     
     for(int i=n;i<N;i++)
     {
        if(is(n,w,last,i,b)==1){
          last.push_back(b[i]);
          p->total_weight += b[i].w;
          p->total_vaule += b[i].p;
          std::cout<<"��ǰi��ֵΪ:"<<i<<"\n";
          std::cout<<"������Ʒ:"<<b[i].num<<"\n";
          dfs(i+1,last,b,w,N,p,flag);
          p->total_weight -= b[i].w;
          p->total_vaule -= b[i].p;
          last.pop_back();

        }
     }
}
void df(B *b,int w,int n,BB *p)
{
    std::vector<B> last;
    int flag=0;
    dfs(0,last,b,w,n,p,&flag);
    
    
}

int main(){
   
    int w,n;
    std::cout<<"�����뱳��������:";
    std::cin>>w;
    std::cout<<"��������Ʒ����:";
    std::cin>>n;
    BB *p=new BB;
    p->total_weight=p->total_vaule=0;
    p->b = new B[n];
    std::cout<<"��ֱ�������Ʒ�������ͼ�ֵ:\n";
    for(int i=0;i<n;i++){
        std::cout<<"��"<<i+1<<"����Ʒ:";
        (p->b)[i].num=i;
        std::cin>>p->b[i].w>>p->b[i].p;
        p->b[i].s= (double)p->b[i].p /p->b[i].w;
    }
    std::sort(p->b,p->b+n,com);
    df(p->b,w,n,p);
    return 0;
}
