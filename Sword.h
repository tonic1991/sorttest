#include <iostream>
#include <string.h>

using namespace std;

class SwordTo
{
public:
	void Print1ToMaxOfDigits(int n);    //E12:打印从1到n位最大数
	
	void YangHuiTriangle(int n );  // 杨辉三角

	void MallocText(); //测试molloc最大空间

private:
	bool InCreaseNum(char* number);   //加1操作，判断终止

	void PrintNumber(char* number);        //打印，打印得符合用户习惯，前面的0不打印

};

void SwordTo::Print1ToMaxOfDigits(int n)
{
	if (n<=0) return ;
	
	char* number = new char[n+1];  //申请了空间，但没有赋值
	memset(number,'0',n);   //前n位赋'0';
	number[n] = '\0';        //最后一位补'\0'

	while (!InCreaseNum(number))    //+1 操作
	{
		PrintNumber(number);
		cout<<" ";
	}
	delete[] number;   //释放内存
}

bool SwordTo::InCreaseNum(char* number)
{
	bool isOverflow = false;     //溢出标志
	int  carryFlag  = 0;			 //进位标志
	int  numLength  = strlen(number);

	for (int i = numLength-1 ; i>=0; i-- )
	{
		int tempSum = number[i] - '0'+ carryFlag;  //每次先计算

		if (i==numLength -1)    //最低位+1
		{
			tempSum++;
		}

		if (tempSum>=10)//进位的情况
		{
			if (i==0)   //判断结束
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
		else//非计算
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

//杨辉三角 。输入为高度
//动态分配二维数组；
//int m=5,n=5;
//int **p=new int*[m];
//for(int i=0;i<m;i++)
//{
//	p[i]=new int[n]; 
//}
//方法2:
//int n=5;
//int (*p)[5]=(int(*)[5])malloc(sizeof(int)*5*n);
void SwordTo::YangHuiTriangle(int h)
{
	//动态分配
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
	//释放：
	for (int i = 0 ; i <h;i++)
	{
		delete[] aTriA[i];
	}
	delete[] aTriA;
	//delete[]aTriA;

}

//测试可molloc的最大空间
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
