#include<iostream>


void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}



void merg(int arr[],int left,int right,int n)
{
	if(left>=right) return;
	int key=left;
	int i=left;
	int j=right;
	std::cout<<"����ѭ��\n";
	std::cout<<"ѭ����ʼi��j��ֵΪ:"<<i<<","<<j<<"\n";
	
	    while(i<j)
		{
			
			while( arr[i+1]<arr[key]) i++;
		    if(i<j) i++;
		    
			while(arr[j]>arr[key] )   j--;
			
			
			std::cout<<"i��j��ֵΪ:"<<i<<","<<j<<"\n";
			if(i<j)
			{
				swap(&arr[i],&arr[j]);
			}
			std::cout<<"��ǰ�����ֵΪ";
			for(int x=0;x<n;x++)
			{
				std::cout<<arr[x]<<" ";
			}
			std::cout<<"\n";
		}
	
	
	
	std::cout<<"�˳�ѭ��\n";
	if(i>=j) swap(&arr[key],&arr[j]);
    
	std::cout<<"��ǰһ�������������ֵΪ::::";
	for(int x=0;x<n;x++)
	{
		std::cout<<arr[x]<<" ";
    }
    std::cout<<"\n";
	merg(arr,left,j-1,n);
	merg(arr,j+1,right,n);
	
}


int main()
{
	int n;
	std::cout<<"������Ҫ��������ָ���:";
	std::cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];
	}
	merg(arr,0,n-1,n);
	std::cout<<"\n";
	std::cout<<"����˵��:!!!!";
	for(int i:arr)
	{
		std::cout<<i<<" ";
	}
	return 0;
}
