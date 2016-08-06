#include<iostream>
#include<stdlib.h>

using namespace std;



//排序类算法合集
//SortClass sortClass;
//const int n = 8;
//int a[n] = {49,38,65,97,76,13,27,49}; 

//sortClass.InsertSort(a,8);

// sortClass.ShellSort(a,8);

//sortClass.SelectionSort(a,8);

// sortClass.BubbleSort(a,8);  //原始冒泡

// sortClass.BubbleSort_pos(a,8);  


//   sortClass.QuickSort(a,0,7);

// sortClass.MergeSort(a,n);  //归并排序

class SortClass
{
public:
	SortClass(){};
	~SortClass(){};



private:
	//交换函数
	void swap(int* a , int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}


public:
	void print(int a[],int n,int i ) //i 表示第几趟
	{
		cout<<"\t"<<i <<":    ";  
		for(int j= 0; j<n; j++)
		{  
			cout<<a[j] <<" ";  
		}  
		cout<<endl;  
	}



	//直接插入排序：将一个记录插入到已经排好序的有序表中, 从而得到一个新的,记录数增1的有序表
	//要点：设立哨兵，作为临时存储和判断边界
	//复杂度 O(n2)
	void InsertSort(int a[], int n)		
	{	


		cout<<"InsertSort Test:  "<<endl;
		for (int i =1 ; i<n ; i++ )
		{
			if (a[i]<a[i-1])
			{
				int temp = a[i];     //复制为哨兵
				int j = i-1;		//
				//a[i] = a[i-1];
				while ( j>=0 && temp < a[j])  //查找插入位置
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


	//希尔排序：：缩小增量法      增量序列d = {n/2 ,n/4, n/8 .....1} n为要排序数的个数
	//要点: 即缩小增量的 直接插入排序
	void ShellSort(int a[],int n )
	{
		cout<<"Shell sort："<<endl;
		int dk = n/2 ;  //步长

		while (dk>=1)
		{
			for (int i = 0;i <dk ; i++)
			{
				for (int j = i +dk ; j<n ; j += dk	)
				{
					if (a[j] <a[j-dk])   //更小直接插入的方式
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


	//选择排序  每次从 n-i+1  中选出最小的作为地i个记录交换。
	//要点: temp 记录index   
	void SelectionSort(int a[], int n)
	{
		cout <<"Selection Sort: "<<endl;
		for (int i = 0; i<n ; i++)
		{
			int temp = i;
			int j = i+1;
			for (  ;j <n; j++)   //查找
			{

				if (a[j]< a[temp])
				{
					temp = j;
				}
			}
			int tempValue;
			//交换
			tempValue = a[i];
			a[i] = a[temp] ;
			a[temp] = tempValue;

			print(a,n,i);
		}

	}


	//冒泡排序O(n2) :
	//要点：每当两相邻的数比较后发现它们的排序与排序要求相反时，就将它们互换
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

	//冒泡排序O(n2) :
	//要点：，用pos记录最后一次交换的位置。
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

					lastSwapPosTemp = j;  //最小的j值；
				}
			}
			print(a,n,i);
		}
	}

	//快速排序
	//1）选择一个基准元素,通常选择第一个元素或者最后一个元素,
	//2）通过一趟排序讲待排序的记录分割成独立的两部分，其中一部分记录的元素值均比基准元素值小。另一部分记录的 元素值比基准值大。
	//3）此时基准元素在其排好序后的正确位置
	//4）然后分别对这两部分记录用同样的方法继续进行排序，直到整个序列有序。
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
	//合并两个数组成有序
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


	//递归--归并排序形式
	void mergeSort(int a[] , int first , int last , int temp[])
	{
		//int mid = 0;
		if(first<last)
		{
			int mid = (first + last)/2;
			mergeSort(a , first ,mid ,temp);          //递归拆分左边数组
			mergeSort(a , mid+1 , last ,temp);		  //拆分右数组
			MergeArray(a , first , mid , last ,temp);    //合并数组
			//print(a ,8,0);
		}
	}
	//调用递归 归并排序的方法
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

	//有序情况二分法
	int dichotomy(int* a, int length  ,int target)
	{

		//待验证改进二分法
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
		return -1;  //没找到
	}
};
