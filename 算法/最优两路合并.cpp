#include <iostream>

typedef struct bug{
	int *data;
	int size;
	int contain;
} A;


void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
A *create(int n)
{
	//�������n
	A *a = new A;
	a->data = new int [n];
	a->size=0;
	a->contain=n;
	return a;
}
void heapup(A *a,int size)
{
	
	
	if(size !=0)
	{
		
		int p = (size-1)/2;       //���ڵ��±�
		if(size>0 && a->data[size] < a->data[p]) {
			swap(&(a->data[size]), &(a->data[p]));
			heapup(a,p);
		}
	}
}
void insert(A *a,int value)
{
	
	
	if(a->size ==a->contain)  {
		std::cout<<"����!!!";
		return ;
	}
	a->data[a->size]=value;
	a->size++;
	heapup(a,a->size-1);
   	
}

void down(A *a,int size)
{
	int min = size;
	int left = 2*size+1;
	int right = 2*size+2;
	if(left <(a->size) && a->data[left] <  a->data[min])  min=left;
	if(right <(a->size) && a->data[right] < a->data[min])  min=right;
	if(min!=size)
	{
		swap(&(a->data[min]),&(a->data[size]));
		down(a,min);
	}
	
	
}
int pullmin(A *a)
{
	if(a->size==0) {
		std::cout<<"��С��Ϊ��!!!\n";
		return 0;
	}
	int min = a->data[0];
    a->data[0]=a->data[a->size-1];
	a->size--;
	down(a,0);
	return min;
	
}
int main()
{
	int n;
	int t;
	std::cout<<"���������ݸ���:";
	std::cin>>n;
	A *heap = create(n);
	for(int i=0;i<n;i++)
	{
		std::cin>>t;
		insert(heap,t);
	}
	std::cout<<"�ṹΪ:";
	for(int i=0;i<n;i++)
	{
		std::cout<<heap->data[i]<<" ";
	}
	std::cout<<"\n";
	int sum=0;
	int cost=0;
    while(heap->size >1)
    {
		int a = pullmin(heap);
		int b = pullmin(heap);
		sum = a+b;
		cost += sum;
		std::cout<<"ȡ����"<<a<<","<<b<<"�ϳ���"<<sum<<"\n";
		insert(heap,sum);
		
	}
	std::cout<<"���ż�����Ϊ:"<<cost;
	
	return 0;
}
