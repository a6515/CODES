#include <iostream>
#include <queue>
#include <vector>
#include <functional>



int main(){

    std::priority_queue<int,std::vector<int>, std::greater<int> >  heap;
    heap.push(7);
    heap.push(6);
    heap.push(5);
    heap.push(4);
    heap.push(3);
    heap.push(2);
    heap.push(1);
    while(!heap.empty())
    {
		std::cout<<heap.top()<<" ";
		heap.pop();
	}
    return 0;
}
