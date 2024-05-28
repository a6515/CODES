#include<iostream>

bool is(int node,int **v,int last[],int N,int color)
{
    for(int i=0;i<N;i++)
    {
        if(v[node][i] && last[i]==color) return false;
    }
    return true;
}

void dfs(int node,int num,int N,int **v,int last[])
{
    if(node==N){
        std::cout<<"һ�ַ���Ϊ:  \n";
        for(int i=0;i<N;i++)
        {
            std::cout<<"�ڵ�"<<i<<",��ɫ:"<<last[i]<<"\n";
        }
        std::cout<<"\n";
        return;
    }
    for(int i=1;i<=num;i++)
    {
        if(is(node,v,last,N,i)){
            last[node]=i;
            dfs(node+1,num,N,v,last);
            last[node]=0;
        }

    }


}


void df(int color_num,int n,int **v)
{
   int last[n];
   for(int i=0;i<n;i++) last[i]=0;
   dfs(0,color_num,n,v,last);

}


int main()
{
    int n,i,j,c,color_num;
    int a,b;
    std::cout<<"������ͼ�Ķ������:";
    std::cin>>n;
    std::cout<<"������ͼ�ı���:";
    std::cin>>c;
    std::cout<<"��������ɫ�������:";
    std::cin>>color_num;
    int **v = new int*[n];
    for(i=0;i<n;i++)
    {
        v[i]=new int[n];
    }
    
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
           v[i][j]=0;
    std::cout<<"�밴�ڽӾ���ķ�ʽ��������ͼ\n";
    for(i=0;i<c;i++)
    {
        std::cout<<"��"<<i+1<<"����:";
        std::cin>>a>>b;
        v[b][a]=v[a][b]=1;

    }
    df(color_num,n,v);

}