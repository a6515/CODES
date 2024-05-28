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
        std::cout << "��ǰ���:\n";
        int sum=0;
        for (const auto& item : last) {
            std::cout << "��Ʒ���: " << item.num << "  ��Ʒ����: " << item.w << "  ��Ʒ��ֵ: " << item.p << "\n";
            sum+=item.p;
        }
        p->max_value=sum;
        std::cout << "������: " << current_weight << " �ܼ�ֵ: " << sum << "\n\n";
        return ;
    }


    if (is(current_weight, w, b[idx].w)) {
        last.push_back(b[idx]);
        dfs(idx + 1, last, b, current_weight + b[idx].w, current_value + b[idx].p, w, N,p);
        std::cout<<"����\n";
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
    std::cout << "�����뱳��������: ";
    std::cin >> w;
    std::cout << "��������Ʒ����: ";
    std::cin >> n;
    BB *p = new BB;
    p->total_weight = p->max_value = 0;
    p->b = new B[n];
    
    std::cout << "��ֱ�������Ʒ�������ͼ�ֵ:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "��" << i + 1 << "����Ʒ: ";
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
