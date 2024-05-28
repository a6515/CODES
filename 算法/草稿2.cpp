#include <iostream>
#include <vector>
#include <algorithm>

typedef struct bug {
    int num;
    int w;
    int p;
    double s;
} B;

typedef struct bugs {
    int total_weight;
    int total_value;
    B *b;
} BB;
bool is(const int current_weight, const int w, int item_weight) {
    return (current_weight + item_weight <= w);
}
bool com(const B& a, const B& b) {
    return a.s > b.s;
}

// 剪枝函数：估计当前路径的最大可能价值
bool bound(int current_weight, int current_value, int idx, int w, int N, B *b, BB *p,std::vector<B>& last,std::vector<B>& best_items) {
    std::cout<<",进入bound函数\n";
    if (current_weight > w) { 
        std::cout<<"当前背包超重\n"; 
        return false;
    } // 超过重量限制，直接剪枝
    else if(current_weight == w){
        std::cout<<"背包满载\n"; 
        best_items = last;
        p->total_value=current_value;
        std::cout<<"此时最大价值为:"<<current_value<<"\n";
        return false;
    }
    int total_weight = current_weight;
    double total_value = current_value;
    // 计算从 idx 到 N 的最大可能价值
    for (int i = idx; i < N; i++) {
        if (total_weight + b[i].w <= w) {
            total_weight += b[i].w;
            std::cout<<"总重量变味了"<<total_weight<<"\n";
            total_value += b[i].p;
        } else {
            total_value += (w - total_weight) * b[i].s;
            break;
        }
    }
    std::cout<<"此时价值上界为:"<<total_value<<", 当前价值为:"<<current_value<<", 记录最大价值为:"<<p->total_value<<"\n";
    return total_value >p->total_value;
}


void dfs(int idx, std::vector<B>& last, B *b, int current_weight, int current_value, int w, int N, BB *p, std::vector<B>& best_items) {

    if(current_weight>w) {
            std::cout<<"当前背包超重\n";
            return;
    }
    if (idx == N) {
        std::cout<<"编号满了\n";
        if (current_value > p->total_value) {
            p->total_value = current_value;
            best_items = last;
            std::cout<<"交互了一次\n";
        }
        return;
    }

    // 尝试包含 b[idx]
    if (is(current_weight, w, b[idx].w)) {
        last.push_back(b[idx]);
        std::cout<<"放入了物品"<<b[idx].num<<", 当前背包重量："<<current_weight+b[idx].w<<", 当前idx:"<<idx<<"\n";
        dfs(idx + 1, last, b, current_weight + b[idx].w, current_value + b[idx].p, w, N, p, best_items);
        last.pop_back();
        std::cout<<"回退了一次\n";
    }


    // 尝试不包含 b[idx]
    std::cout<<"尝试不包含节点:"<<idx<<"\n";
    if (bound(current_weight, current_value, idx + 1, w, N, b, p,last,best_items)) {
        std::cout<<"bound函数返回真:\n";
        dfs(idx + 1, last, b, current_weight, current_value, w, N, p, best_items);
    }
    std::cout<<"末尾结束\n";
}

void df(B *b, int w, int n,BB *p) {
    std::vector<B> last;
    std::vector<B> best_items;
    dfs(0, last, b, 0, 0, w, n,p ,best_items);

    std::cout << "最佳组合:\n";
    for (const auto& item : best_items) {
        std::cout << "物品编号: " << item.num << "  物品重量: " << item.w << "  物品价值: " << item.p << "\n";
    }
    std::cout << " 总价值: " << p->total_value << "\n";
}

int main() {
    int w, n;
    std::cout << "请输入背包总重量: ";
    std::cin >> w;
    std::cout << "请输入物品个数: ";
    std::cin >> n;

    BB *p = new BB;
    p->total_weight = p->total_value = 0;
    p->b = new B[n];

    std::cout << "请分别输入物品的重量和价值:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "第" << i + 1 << "个物品: ";
        (p->b)[i].num = i;
        std::cin >> p->b[i].w >> p->b[i].p;
        p->b[i].s = (double)p->b[i].p / p->b[i].w;
    }

    //std::sort(p->b, p->b + n, com);
    df(p->b, w, n,p);

    delete[] p->b;
    delete p;
    return 0;
}
