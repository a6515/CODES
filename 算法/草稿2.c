#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // ͼ�еĶ�����

// ���ڱ�ʾһ���ѽڵ㣨���ȶ����е�Ԫ�أ�
typedef struct {
    int v;      // ������
    int dist;   // Դ�㵽�ö���ľ���
} MinHeapNode;

// ���ȶ��У���С�ѣ�
typedef struct {
    int size;       // ���е�ǰԪ�ص�����
    int capacity;   // �ѿ������ɵ����Ԫ������
    MinHeapNode **array;  // ָ�����飬ָ���Ԫ��
} MinHeap;

// ����һ����С�ѽڵ�
MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* minHeapNode = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// ����һ����С��
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**) malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// ���������ѽڵ�
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// ��С�ѵ����µ�������
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// ����С������ȡ��С�ڵ�
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0)
        return NULL;

    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

// �ж���С���Ƿ�Ϊ��
int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Dijkstra's Algorithm using priority queue for shortest path finding
void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];  // ��������

    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    minHeap->size = V;

    while (!isEmpty(minHeap)) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decreaseKey(minHeap, v, dist[v]);
            }
        }
    }

    printf("Shortest path from %d to %d is %d\n", src, dest, dist[dest]);
}

int main() {
    int graph[V][V] = {{0, 4, 0, 0, 0},
                       {0, 0, 8, 0, 0},
                       {4, 0, 0, 2, 0},
                       {0, 0, 0, 0, 6},
                       {0, 0, 2, 0, 0}};

    int src = 0;  // Դ��
    int dest = 4;  // �յ�
    dijkstra(graph, src, dest);

    return 0;
}
