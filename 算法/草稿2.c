#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // 图中的顶点数

// 用于表示一个堆节点（优先队列中的元素）
typedef struct {
    int v;      // 顶点编号
    int dist;   // 源点到该顶点的距离
} MinHeapNode;

// 优先队列（最小堆）
typedef struct {
    int size;       // 堆中当前元素的数量
    int capacity;   // 堆可以容纳的最大元素数量
    MinHeapNode **array;  // 指针数组，指向堆元素
} MinHeap;

// 创建一个最小堆节点
MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* minHeapNode = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// 创建一个最小堆
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**) malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// 交换两个堆节点
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// 最小堆的向下调整过程
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

// 从最小堆中提取最小节点
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

// 判断最小堆是否为空
int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Dijkstra's Algorithm using priority queue for shortest path finding
void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];  // 距离数组

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

    int src = 0;  // 源点
    int dest = 4;  // 终点
    dijkstra(graph, src, dest);

    return 0;
}
