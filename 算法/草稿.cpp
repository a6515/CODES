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
    int max_value;
    B *b;
} BB;

bool com(const B& a, const B& b) {
    return a.s > b.s;
}

bool is(const int current_weight, const int w, int item_weight) {
    return (current_weight + item_weight <= w);
}

void dfs(int idx, std::vector<B>& last, B *b, int current_weight, int current_value, int w, int N,BB *p) {
    
    if (current_weight > w) return; 
    if (idx == N && current_value>= p->max_value) {
        std::cout << "当前组合:\n";
        int sum=0;
        for (const auto& item : last) {
            std::cout << "物品编号: " << item.num << "  物品重量: " << item.w << "  物品价值: " << item.p << "\n";
            sum+=item.p;
        }
        p->max_value=sum;
        std::cout << "总重量: " << current_weight << " 总价值: " << sum << "\n\n";
        return ;
    }


    if (is(current_weight, w, b[idx].w)) {
        last.push_back(b[idx]);
        dfs(idx + 1, last, b, current_weight + b[idx].w, current_value + b[idx].p, w, N,p);
        std::cout<<"回退\n";
        last.pop_back();
    }

    dfs(idx + 1, last, b, current_weight, current_value, w, N,p);
}

void df(B *b, int w, int n,BB *p) {
    std::vector<B> last;
    dfs(0, last, b, 0, 0, w, n,p);
}


int main() {
    int w, n;
    std::cout << "请输入背包总重量: ";
    std::cin >> w;
    std::cout << "请输入物品个数: ";
    std::cin >> n;
    BB *p = new BB;
    p->total_weight = p->max_value = 0;
    p->b = new B[n];
    
    std::cout << "请分别输入物品的重量和价值:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "第" << i + 1 << "个物品: ";
        (p->b)[i].num = i;
        std::cin >> p->b[i].w >> p->b[i].p;
        p->b[i].s = (double)p->b[i].p / p->b[i].w;
    }

    std::sort(p->b, p->b + n, com);
    df(p->b, w, n,p);

    delete[] p->b;
    delete p;
    return 0;
}
