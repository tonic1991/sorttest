#include <iostream>
#include <string.h>

using namespace std;

class SwordTo
{
public:
	void Print1ToMaxOfDigits(int n);    //E12:��ӡ��1��nλ�����
	
	void YangHuiTriangle(int n );  // �������

	void MallocText(); //����molloc���ռ�

private:
	bool InCreaseNum(char* number);   //��1�������ж���ֹ

	void PrintNumber(char* number);        //��ӡ����ӡ�÷����û�ϰ�ߣ�ǰ���0����ӡ

};

void SwordTo::Print1ToMaxOfDigits(int n)
{
	if (n<=0) return ;
	
	char* number = new char[n+1];  //�����˿ռ䣬��û�и�ֵ
	memset(number,'0',n);   //ǰnλ��'0';
	number[n] = '\0';        //���һλ��'\0'

	while (!InCreaseNum(number))    //+1 ����
	{
		PrintNumber(number);
		cout<<" ";
	}
	delete[] number;   //�ͷ��ڴ�
}

bool SwordTo::InCreaseNum(char* number)
{
	bool isOverflow = false;     //�����־
	int  carryFlag  = 0;			 //��λ��־
	int  numLength  = strlen(number);

	for (int i = numLength-1 ; i>=0; i-- )
	{
		int tempSum = number[i] - '0'+ carryFlag;  //ÿ���ȼ���

		if (i==numLength -1)    //���λ+1
		{
			tempSum++;
		}

		if (tempSum>=10)//��λ�����
		{
			if (i==0)   //�жϽ���
			{
				isOverflow =true;
			}
			else
			{
				tempSum -=10;
				carryFlag =1;
				number[i]  = tempSum+'0';
			}
		}
		else//�Ǽ���
		{
			number[i] = '0'+ tempSum;
			break;	
		}
	}


	return isOverflow;
}

void SwordTo::PrintNumber(char* number)
{
	bool bfirstNoZero = false;
	int numLengh =  strlen(number);
	for (int i = 0 ;i<numLengh ; i++)
	{
		if (!bfirstNoZero && number[i] != '0')
		{
			bfirstNoZero=true;
		}
		if (bfirstNoZero)
		{
			cout<<number[i];
		}
	}
//	cout<<"\t";
	
}

//������� ������Ϊ�߶�
//��̬�����ά���飻
//int m=5,n=5;
//int **p=new int*[m];
//for(int i=0;i<m;i++)
//{
//	p[i]=new int[n]; 
//}
//����2:
//int n=5;
//int (*p)[5]=(int(*)[5])malloc(sizeof(int)*5*n);
void SwordTo::YangHuiTriangle(int h)
{
	//��̬����
	int** aTriA=new int*[h];
	for (int i = 0 ; i <h ; i++)
	{
		aTriA[i] = new int[h];
	}
	for (int i = 0 ; i<h;i++)
	{
		for (int j= 0 ; j<=i;j++)
		{
			if (i==j||j==0)
			{
				aTriA[i][j]=1;
			}else
			{
				aTriA[i][j]=aTriA[i-1][j]+aTriA[i-1][j-1];
			}			
		}
	}
	for (int i =0;i<h;i++)
	{
		
		for (int j = 0 ; j <=i;j++)
		{
			cout<<aTriA[i][j]<<"";
		}
		cout<<endl;
	}
	//�ͷţ�
	for (int i = 0 ; i <h;i++)
	{
		delete[] aTriA[i];
	}
	delete[] aTriA;
	//delete[]aTriA;

}

//���Կ�molloc�����ռ�
void SwordTo::MallocText()
{
	unsigned int maxMen = 0;
	unsigned int alloc_size[] = {8*1024*1024,4*1024*1024 ,2*1024*1024};
	int i , count;
	for (i = 0 ; i <3;i++)
	{
		for (count=1; ; count++)
		{
			void* mem = (void*)malloc(maxMen +alloc_size[i]*count);
			if (NULL != mem)
			{
				maxMen = maxMen+alloc_size[i]*count;
				free(mem);
				cout<<"maxMen : \t"<<maxMen<<endl;
			}
			else
			{
				break;
			}
		}
		cout<<"maxMen :______________ \t"<<maxMen<<endl;
	}
	cout<<"maxMen : *************\t"<<maxMen<<endl;
}
