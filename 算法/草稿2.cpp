#include <iostream>
#include <queue>
#include <vector>
#include<climits>
using namespace std;

// ����ߵĽṹ��
struct Edge
{
    int from, to, weight;
};

// �ȽϺ���,�������ȶ���
struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

int main()
{
    // ͼ���ڽӱ��ʾ
    vector<vector<Edge>> graph = {
        {{0, 1, 2}, {0, 2, 8}, {0, 3, 5}},
        {{1, 2, 3}, {1, 4, 3}},
        {{2, 5, 4}},
        {{3, 5, 6}, {3, 6, 9}},
        {{4, 5, 5}, {4, 6, 7}},
        {{5, 6, 2}}};

    int n = 7;                  // �����
    int source = 0, target = 5; // Դ���Ŀ���

    // ��ʼ�� D �� S ����
    vector<int> D(n, INT_MAX);
    vector<int> S(n, -1);
    D[source] = 0;

    // ���ȶ���,���(����,���)
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (u == target)
            break; // �ҵ�Ŀ���,�˳�

        // ���� u ���ھӽ��
        for (const auto &edge : graph[u])
        {
            int v = edge.to;
            int weight = edge.weight;
            if (D[v] > D[u] + weight)
            {
                D[v] = D[u] + weight;
                S[v] = u;
                pq.push({D[v], v});
            }
        }
    }

    // ������·��
    cout << "���·��: ";
    int curr = target;
    while (curr != -1)
    {
        cout << curr << " ";
        curr = S[curr];
    }
    cout << endl;
    cout << "���·������: " << D[target] << endl;

    return 0;
}
/*
���ȶ��еı仯���̣�
���ȣ�������һ�����ȶ��� pq�����ڴ�� (����, ���) �� pair Ԫ�ء�
��Դ��������ȶ��У�pq.push({0, source})��
��ÿһ�ε����У������ȶ�����ȡ��������С�Ľ�� u��int u = pq.top().second��Ȼ����Ӷ������Ƴ���pq.pop()��
������� u ���ھӽ�㣬���� Dijkstra �㷨��˼��������·����
���ͨ����� u ������ v ��·������ D[v] ����ͨ����� u ��·������ D[u] ���ϱߵ�Ȩ�� weight������� D[v] �� S[v]��������� v �������ȶ��� pq��pq.push({D[v], v})��
�Ƶ����̣�
��ʼ�� D ����� S ���飬��Դ������·������ D[source] ��Ϊ 0��
����ѭ����ֱ�����ȶ���Ϊ�գ�
�����ȶ�����ȡ��������С�Ľ�� u��
������ u ��Ŀ��㣬�˳�ѭ����
������� u ���ھӽ�㣬����ÿ���� (u, v)��
���ͨ����� u ������ v ��·������ D[v] ����ͨ����� u ��·������ D[u] ���ϱߵ�Ȩ�� weight������� D[v] �� S[v]��������� v �������ȶ��� pq��
ѭ�����������·���ĳ��ȴ洢�� D[target] �У����·���ϵĽ��˳��洢������ S �С�
���·�������ȵ������
������·������Ŀ��㿪ʼ������ǰ��������� S �������ÿ����㡣
������·�����ȣ���� D[target]��
*/
