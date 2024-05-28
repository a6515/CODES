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

// ��֦���������Ƶ�ǰ·���������ܼ�ֵ
bool bound(int current_weight, int current_value, int idx, int w, int N, B *b, BB *p,std::vector<B>& last,std::vector<B>& best_items) {
    std::cout<<",����bound����\n";
    if (current_weight > w) { 
        std::cout<<"��ǰ��������\n"; 
        return false;
    } // �����������ƣ�ֱ�Ӽ�֦
    else if(current_weight == w){
        std::cout<<"��������\n"; 
        best_items = last;
        p->total_value=current_value;
        std::cout<<"��ʱ����ֵΪ:"<<current_value<<"\n";
        return false;
    }
    int total_weight = current_weight;
    double total_value = current_value;
    // ����� idx �� N �������ܼ�ֵ
    for (int i = idx; i < N; i++) {
        if (total_weight + b[i].w <= w) {
            total_weight += b[i].w;
            std::cout<<"��������ζ��"<<total_weight<<"\n";
            total_value += b[i].p;
        } else {
            total_value += (w - total_weight) * b[i].s;
            break;
        }
    }
    std::cout<<"��ʱ��ֵ�Ͻ�Ϊ:"<<total_value<<", ��ǰ��ֵΪ:"<<current_value<<", ��¼����ֵΪ:"<<p->total_value<<"\n";
    return total_value >p->total_value;
}


void dfs(int idx, std::vector<B>& last, B *b, int current_weight, int current_value, int w, int N, BB *p, std::vector<B>& best_items) {

    if(current_weight>w) {
            std::cout<<"��ǰ��������\n";
            return;
    }
    if (idx == N) {
        std::cout<<"�������\n";
        if (current_value > p->total_value) {
            p->total_value = current_value;
            best_items = last;
            std::cout<<"������һ��\n";
        }
        return;
    }

    // ���԰��� b[idx]
    if (is(current_weight, w, b[idx].w)) {
        last.push_back(b[idx]);
        std::cout<<"��������Ʒ"<<b[idx].num<<", ��ǰ����������"<<current_weight+b[idx].w<<", ��ǰidx:"<<idx<<"\n";
        dfs(idx + 1, last, b, current_weight + b[idx].w, current_value + b[idx].p, w, N, p, best_items);
        last.pop_back();
        std::cout<<"������һ��\n";
    }


    // ���Բ����� b[idx]
    std::cout<<"���Բ������ڵ�:"<<idx<<"\n";
    if (bound(current_weight, current_value, idx + 1, w, N, b, p,last,best_items)) {
        std::cout<<"bound����������:\n";
        dfs(idx + 1, last, b, current_weight, current_value, w, N, p, best_items);
    }
    std::cout<<"ĩβ����\n";
}

void df(B *b, int w, int n,BB *p) {
    std::vector<B> last;
    std::vector<B> best_items;
    dfs(0, last, b, 0, 0, w, n,p ,best_items);

    std::cout << "������:\n";
    for (const auto& item : best_items) {
        std::cout << "��Ʒ���: " << item.num << "  ��Ʒ����: " << item.w << "  ��Ʒ��ֵ: " << item.p << "\n";
    }
    std::cout << " �ܼ�ֵ: " << p->total_value << "\n";
}

int main() {
    int w, n;
    std::cout << "�����뱳��������: ";
    std::cin >> w;
    std::cout << "��������Ʒ����: ";
    std::cin >> n;

    BB *p = new BB;
    p->total_weight = p->total_value = 0;
    p->b = new B[n];

    std::cout << "��ֱ�������Ʒ�������ͼ�ֵ:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "��" << i + 1 << "����Ʒ: ";
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
