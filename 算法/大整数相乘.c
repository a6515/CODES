#include<stdio.h>
int main()
{
    int Data[100];                            /*�洢40λ������������*/
    int Digit;                               /*����λ������        */
    int i,j,k;                              /*ѭ����������        */
    int N;                                 /*�û�����ֵ          */
	
    for(i=0;i<100;i++)                   /*�������ʼֵ��Ϊ0    */
        Data[i]=0;
	
    Data[0]=1;                             /*���0λ������Ϊ1    */
    Digit=1;                               /*������λ��Ϊ1       */
	
    printf("������һ������:");
    scanf("%d",&N);                        /*��ȡ�û������Nֵ   */
	
    for(i=1;i<N+1;i++)
    {
        for(j=0;j<Digit;j++)
            Data[j] *= i;                  /*���������ݵ�����    */
        for(j=0;j<Digit;j++)
        {
            if(Data[j]>10)
            {            
			    Data[j + 1] =Data[j + 1]+ (Data[j] / 10);         
                Data[j] %= 10;  	                           
            }
        }    
        while(Data[Digit]>=10)//�������һλ
		{
			Data[Digit+1]=Data[Digit+1]+Data[Digit]/10; 
			Data[Digit]=Data[Digit]%10;    
			Digit++;
		}
		
		if(Data[Digit]>0)
			Digit++;
        
        printf("%d!=",i);
        for(k=Digit-1;k>=0;k--)       /*��������е�����*/
            printf("%d",Data[k]);
        printf("\n");
	}
	return 0;
}
