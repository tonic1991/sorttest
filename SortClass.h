#include<iostream>
#include<stdlib.h>

using namespace std;



//�������㷨�ϼ�
//SortClass sortClass;
//const int n = 8;
//int a[n] = {49,38,65,97,76,13,27,49}; 

//sortClass.InsertSort(a,8);

// sortClass.ShellSort(a,8);

//sortClass.SelectionSort(a,8);

// sortClass.BubbleSort(a,8);  //ԭʼð��

// sortClass.BubbleSort_pos(a,8);  


//   sortClass.QuickSort(a,0,7);

// sortClass.MergeSort(a,n);  //�鲢����

class SortClass
{
public:
	SortClass(){};
	~SortClass(){};



private:
	//��������
	void swap(int* a , int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}


public:
	void print(int a[],int n,int i ) //i ��ʾ�ڼ���
	{
		cout<<"\t"<<i <<":    ";  
		for(int j= 0; j<n; j++)
		{  
			cout<<a[j] <<" ";  
		}  
		cout<<endl;  
	}



	//ֱ�Ӳ������򣺽�һ����¼���뵽�Ѿ��ź�����������, �Ӷ��õ�һ���µ�,��¼����1�������
	//Ҫ�㣺�����ڱ�����Ϊ��ʱ�洢���жϱ߽�
	//���Ӷ� O(n2)
	void InsertSort(int a[], int n)		
	{	


		cout<<"InsertSort Test:  "<<endl;
		for (int i =1 ; i<n ; i++ )
		{
			if (a[i]<a[i-1])
			{
				int temp = a[i];     //����Ϊ�ڱ�
				int j = i-1;		//
				//a[i] = a[i-1];
				while ( j>=0 && temp < a[j])  //���Ҳ���λ��
				{
					a[j+1] = a[j];
					j--;
				}
				a[j+1] = temp;
			}
			print(a,n,i);
		}
		cout<<endl;



	}


	//ϣ�����򣺣���С������      ��������d = {n/2 ,n/4, n/8 .....1} nΪҪ�������ĸ���
	//Ҫ��: ����С������ ֱ�Ӳ�������
	void ShellSort(int a[],int n )
	{
		cout<<"Shell sort��"<<endl;
		int dk = n/2 ;  //����

		while (dk>=1)
		{
			for (int i = 0;i <dk ; i++)
			{
				for (int j = i +dk ; j<n ; j += dk	)
				{
					if (a[j] <a[j-dk])   //��Сֱ�Ӳ���ķ�ʽ
					{
						int temp = a[j];
						int k = j-dk;
						while (k>=0 && a[k]>temp)
						{
							a[k+dk] = a [k];
							k -= dk ;
						}
						a[k+dk] = temp; 					
					}

				}
				print(a,n,i);
			}

			dk = dk/2;
		}   
	}


	//ѡ������  ÿ�δ� n-i+1  ��ѡ����С����Ϊ��i����¼������
	//Ҫ��: temp ��¼index   
	void SelectionSort(int a[], int n)
	{
		cout <<"Selection Sort: "<<endl;
		for (int i = 0; i<n ; i++)
		{
			int temp = i;
			int j = i+1;
			for (  ;j <n; j++)   //����
			{

				if (a[j]< a[temp])
				{
					temp = j;
				}
			}
			int tempValue;
			//����
			tempValue = a[i];
			a[i] = a[temp] ;
			a[temp] = tempValue;

			print(a,n,i);
		}

	}


	//ð������O(n2) :
	//Ҫ�㣺ÿ�������ڵ����ȽϺ������ǵ�����������Ҫ���෴ʱ���ͽ����ǻ���
	void BubbleSort(int a [] ,int n )
	{
		for (int i = 0 ; i<n-1; i ++)
		{
			for (int j=0; j<n-i-1 ; j++ )
			{
				if (a[j]>a[j+1])
				{
					int temp;
					temp   = a[j+1];
					a[j+1] = a[j];
					a[j]   = temp;
				}
			}
			print(a,n,i);
		}
	}

	//ð������O(n2) :
	//Ҫ�㣺����pos��¼���һ�ν�����λ�á�
	void BubbleSort_pos(int a [] ,int n )
	{	
		int  lastSwapPos = 0 , lastSwapPosTemp=0;
		for (int i = 0; i < n-1; i++)
		{
			lastSwapPos = lastSwapPosTemp;
			for (int j = n-1; j  > lastSwapPos; j--)
			{
				if (a[j]<a[j-1])
				{
					int temp = a[j - 1];  
					a[j - 1] = a[j];  
					a[j] = temp;  

					lastSwapPosTemp = j;  //��С��jֵ��
				}
			}
			print(a,n,i);
		}
	}

	//��������
	//1��ѡ��һ����׼Ԫ��,ͨ��ѡ���һ��Ԫ�ػ������һ��Ԫ��,
	//2��ͨ��һ�����򽲴�����ļ�¼�ָ�ɶ����������֣�����һ���ּ�¼��Ԫ��ֵ���Ȼ�׼Ԫ��ֵС����һ���ּ�¼�� Ԫ��ֵ�Ȼ�׼ֵ��
	//3����ʱ��׼Ԫ�������ź�������ȷλ��
	//4��Ȼ��ֱ���������ּ�¼��ͬ���ķ���������������ֱ��������������
	void QuickSort(int a[], int low , int high	)
	{
		if (low<high)
		{
			int pivotloc = Partition(a , low , high);
			QuickSort( a , low , pivotloc);
			QuickSort( a,  pivotloc+1,high );		
		}
	}

	int Partition(int a[] , int low , int high )
	{
		int	 privotKey = a[low];
		while(low<high)
		{
			while (low<high && a[high] >= privotKey)  {--high;}
			swap(&a[low],&a[high]);
			while (low<high && a[low]<= privotKey) {  ++low;}
			swap(&a[low],&a[high]);	
		}

		print(a,8,0);
		return low;
	}
	//�ϲ��������������
	void MergeArray(int a [], int first, int mid, int last ,int temp[] )
	{
		int i = first; int j = mid +1 ;
		int m = mid ;  int  n = last;
		int length = 0;

		while (i <= m  && j <=n )
		{
			if (a[i]<=a[j])
			{
				temp[length++] = a[i++];
			}
			else
			{
				temp[length++] =a[j++];
			}
		}
		while (i<=m)
		{
			temp[length++] = a[i++];
		}
		while (j<=n)
		{
			temp[length++] = a[j++];
		}

		for (int index = 0; index < length; index++)
		{
			a[first + index] = temp[index];
		}

	}


	//�ݹ�--�鲢������ʽ
	void mergeSort(int a[] , int first , int last , int temp[])
	{
		//int mid = 0;
		if(first<last)
		{
			int mid = (first + last)/2;
			mergeSort(a , first ,mid ,temp);          //�ݹ����������
			mergeSort(a , mid+1 , last ,temp);		  //���������
			MergeArray(a , first , mid , last ,temp);    //�ϲ�����
			//print(a ,8,0);
		}
	}
	//���õݹ� �鲢����ķ���
	bool MergeSort(int a[] , int n)
	{
		int *p = new int[n];
		if ( p == NULL)
		{
			return false;
		}
		mergeSort(a,0,n-1,p);
		print(a ,8,0);
		delete []p;
		return true;
	}

	//����������ַ�
	int dichotomy(int* a, int length  ,int target)
	{

		//����֤�Ľ����ַ�
		int low = 0; int high = length -1;
		int mid = 0 ;
		while (low<high)
		{
			mid = ((high-low)>>1) +low;
			if (a[mid]== target) return mid;
			if (a[mid]>target)
			{
				high = mid-1;
			}
			else
			{
				low = mid +1 ;
			}
		}
		return -1;  //û�ҵ�
	}
};
