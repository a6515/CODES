#include <iostream>
#include <queue>
using namespace std;


typedef struct ArcCell {
    int adj;    
    int info;   
} ArcCell, AdjMatrix[100][100]; // 定义邻接矩阵类型

// 定义顶点结构体
typedef struct {
    int data;  
    int length;
    int pre;    
} VertexType;

// 定义图结构体
typedef struct {
    VertexType vexs[100];   
    AdjMatrix arcs;         
    int vexnum;             
    int arcnum;             
} Graph;

Graph G;                    
queue<int> q;              


void CreateGraph() {
    int m, n, t;

    printf("输入顶点数和弧数:");
    scanf("%d %d", &G.vexnum, &G.arcnum);
                   
  
    for(int i = 0; i < G.vexnum; i++) {
        G.vexs[i].data=i;
        G.vexs[i].length = 10000; // 初始化最短路径长度为一个较大的值
    }


    for(int i = 0; i < G.vexnum; i++)
        for(int j = 0; j < G.vexnum; j++)
            G.arcs[i][j].adj = 0;

    
    printf("输入弧及权重:\n");
    for(int i = 0; i < G.arcnum; i++) {
        scanf("%d %d %d", &m, &n, &t);
        G.arcs[m][n].adj = 1;   
        G.arcs[m][n].info = t;  
    }
    std::cout<<"矩阵存储成功\n\n";
}

// 寻找顶点 v 在节点 w 之后的下一个邻接节点
int NextAdj(int v, int w) {

    for(int i = w+1 ; i < G.vexnum; i++)
        if(G.arcs[v][i].adj)
            return i;
    return -1; 
}


void ShortestPaths(int v) {
	 
    int k = 0;  // 从首个节点开始访问
    int t;
    G.vexs[0].pre=0;      
    G.vexs[v].length = 0;   // 起始顶点到自身的距离为 0
    q.push(G.vexs[v].data);
    while(!q.empty()) {
        t = q.front();  
        k = NextAdj(t, k); 
        while(k != -1) {

            if(G.vexs[t].length + G.arcs[t][k].info <= G.vexs[k].length) {
                G.vexs[k].length = G.vexs[t].length + G.arcs[t][k].info;
                G.vexs[k].pre=t;
                q.push(G.vexs[k].data); // 将 k 入队
            }
            k = NextAdj(t, k);
        }
        q.pop(); 
    }
}

// 打印各个顶点及其最短路径长度
void Print() {
	int k;
    for(int i = 0; i < G.vexnum-1; i++)
        printf("从顶点到节点:%d的最短路径长度------%d\n", G.vexs[i].data, G.vexs[i].length);
   
}
void print2(int n,int s[],int i)
{
	if(i== G.vexnum) {
		return;
	}
	s[i] = G.vexs[n].pre;
	std::cout<<"第"<<i<<"次放入成功\n";
	print2(n-1,s,i+1);
	
}

// 主函数
int main() {
	std::cout<<"计算机222 郭建新 202202313\n\n";
    CreateGraph();          // 创建图
    ShortestPaths(0);       // 计算从顶点 0 开始的最短路径
    Print();                // 打印结果
    int s[G.vexnum];
    print2(G.vexnum-1,s,0);
    std::cout<<"\n";
    std::cout<<"最短路径编号为:";
    for(int i=0;i<4;i++)
    {
		std::cout<<s[i]<<" ";
	}
    return 0;
}
