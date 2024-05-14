#include<iostream>
void traceback(int i, int j, int s[][100]) {
    if (i == j) {
        std::cout << "A" << i+1 ;
    } else {
        std::cout << "(";
        traceback(i, s[i][j], s);
        std::cout << "x";
        traceback(s[i][j] + 1, j, s);
        std::cout << ")";
    }
}
void mc(int p[],int n)
{
	int i,j,k,r,t;
	int m[n][n];
	int s[n][100]={0};
	for(i=0;i<n;i++) m[i][i]=0;
	for(r=2;r<=n;r++)           //r������һ�飬����
	{
		for(i=0;i<=n-r;i++)     //iΪһ�����ʼλ��
		{
			j=i+r-1;            //jΪһ���β��
			m[i][j]=9999999;    //��ʼ��
			s[i][j]=i;
			for(k=i;k<j;k++)    //kΪ����±�
			{
				t = m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(t<m[i][j]) {
					m[i][j]=t;   //�������ż������ͷָ��±�
					s[i][j]=k;
				}
			}
		}
	}
	std::cout<<"���ż������Ϊ:"<<m[0][n-1]<<"\n";
	std::cout << "���󻮷���ʽΪ: ";
	traceback(0, n-1 , s);
}

int main()
{
	int p[]={10,20,25,15,5,10,25};
	int len = sizeof(p)/sizeof(p[0]);
	mc(p,len-1);
	
	return 0;
}
