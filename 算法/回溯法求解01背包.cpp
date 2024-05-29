#include <iostream>
#include <vector>
#include <algorithm>
typedef struct bug
{
    int num;
    int w;
    int p;
    double s;
}B;

bool com(const B& a,const B& b){
     return a.s>b.s;
}

bool is(int w,int item_w,const int& W)
{
    return w+item_w <=W;
}

void dfs(int idx,int W,int N,B b[],int last[],int *max,int w,int p,int *count)
{
    if(w> W) return;
    if(idx==N){
      
        if(p>(*max)){
            *max=p;
        }
        return;
    }
    if( is(w,b[idx].w,W) ){
        last[*count]=b[idx].num;
       (*count)++;
    
        dfs(idx+1,W,N,b,last,max,w+b[idx].w,p+b[idx].p,count);
      
        
        (*count)--;
        last[*count]=-1;
    }
 
    dfs(idx+1,W,N,b,last,max,w,p,count);
}


int main()
{
    int w, n,max=0,count=0;
    std::cout << "请输入背包总重量: ";
    std::cin >> w;
    std::cout << "请输入物品个数: ";
    std::cin >> n;
    B b[n];
    int last[n];
    for(int i=0;i<n;i++) last[i]=-1;
    std::cout << "请分别输入物品的重量和价值:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "第" << i  << "个物品: ";
        b[i].num = i;
        std::cin >> b[i].w >>    b[i].p;
        b[i].s = (double)b[i].p /b[i].w;
        
    }
    std::sort(b,b+n,com);
    dfs(0,w,n,b,last,&max,0,0,&count);
    std::cout<<"最大价值为:"<<max;

}