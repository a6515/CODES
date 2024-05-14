#include <iostream>
#include <queue>
using namespace std;


typedef struct ArcCell {
    int adj;    
    int info;   
} ArcCell, AdjMatrix[100][100]; // �����ڽӾ�������

// ���嶥��ṹ��
typedef struct {
    int data;  
    int length;
    int pre;    
} VertexType;

// ����ͼ�ṹ��
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

    printf("���붥�����ͻ���:");
    scanf("%d %d", &G.vexnum, &G.arcnum);
                   
  
    printf("���붥��:");
    for(int i = 0; i < G.vexnum; i++) {
        scanf("%d", &G.vexs[i].data);
        G.vexs[i].length = 10000; // ��ʼ�����·������Ϊһ���ϴ��ֵ
    }


    for(int i = 0; i < G.vexnum; i++)
        for(int j = 0; j < G.vexnum; j++)
            G.arcs[i][j].adj = 0;

    
    printf("���뻡��Ȩ��:\n");
    for(int i = 0; i < G.arcnum; i++) {
        scanf("%d %d %d", &m, &n, &t);
        G.arcs[m][n].adj = 1;   
        G.arcs[m][n].info = t;  
    }
    std::cout<<"����洢�ɹ�\n\n";
}

// Ѱ�Ҷ��� v �ڽڵ� w ֮�����һ���ڽӽڵ�
int NextAdj(int v, int w) {

    for(int i = w+1 ; i < G.vexnum; i++)
        if(G.arcs[v][i].adj)
            return i;
    return -1; 
}

void ShortestPaths(int v) {
	 
    int k = 0;  // ���׸��ڵ㿪ʼ����
    int t;
    G.vexs[0].pre=0;      
    G.vexs[v].length = 0;   // ��ʼ���㵽����ľ���Ϊ 0
    q.push(G.vexs[v].data);
    while(!q.empty()) {
        t = q.front();  
        k = NextAdj(t, k); 
        while(k != -1) {

            if(G.vexs[t].length + G.arcs[t][k].info <= G.vexs[k].length) {
                G.vexs[k].length = G.vexs[t].length + G.arcs[t][k].info;
                G.vexs[k].pre=t;
                q.push(G.vexs[k].data); // �� k ���
            }
            k = NextAdj(t, k);
        }
        q.pop(); 
    }
}

// ��ӡ�������㼰�����·������
void Print() {
	int k;
    for(int i = 0; i < G.vexnum; i++)
        printf("�Ӷ��㵽�ڵ�:%d�����·������------%d\n", G.vexs[i].data, G.vexs[i].length);
   
}


// ������
int main() {
	std::cout<<"�����222 ������ 202202313\n\n";
    CreateGraph();          // ����ͼ
    ShortestPaths(0);       // ����Ӷ��� 0 ��ʼ�����·��
    Print();                // ��ӡ���

    return 0;
}
