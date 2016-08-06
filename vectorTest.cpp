//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
////   vector    基本使用 
////            erese()  unique()   vector<int>::reverse_iterator it 
////  algorithm  基本使用
////             sort() ;  reverse()
//
//
////vector 测试类
//class VectorTest
//{
//	
//public: 
//	// vector sort
//	void SortVec(vector<int>  vec)
//	{
//		if (!vec.empty())
//		{
//			sort(vec.begin(),vec.end());	 
//		}
//
//		cout<<"sort result:"<<endl;
//		printVec(vec);
//	}
//	
//	//去重复
//	 void uniqueVec(vector<int>  vec)
//	{
//		vec.erase(unique(vec.begin(),vec.end()),vec.end());
//		
//		cout<<"erase unique:"<<endl;
//		printVec(vec);
//	}
//	
//
//	 void reverseTest(vector<int> vec)
//	 {
//		cout<<"reverse vec use reverse_iterator :"<<endl <<"\t";
//		for (vector<int>::reverse_iterator it = vec.rbegin();it!=vec.rend();it++)
//		{
//			cout <<*it<<"  ";
//		}
//
//
//	 }
//
//    //输出vec
//	void printVec(vector<int> vec)
//	{
//		
//		if (vec.empty())
//		{
//			cout <<"vec is empty"<<endl;
//		}		
//		cout<<"\t";
//		for (vector<int>::iterator it = vec.begin();it!=vec.end();it++)
//		{
//			cout<<" "<<*it<<" ";
//		}
//		cout<<endl;
//		
//	}
//
//
//
//};
//
//
//void main()
//{
//	vector<int> vecIn;
//	VectorTest vecTest;  //实例化vector 测试类
//	vecIn.push_back(3);
//	vecIn.push_back(1);
//	vecIn.push_back(5);
//	vecIn.push_back(3);
//	vecIn.push_back(2);
//	cout<<"input vector"<<endl	;
//	vecTest.printVec(vecIn);
//		
//	//排序
//	vecTest.SortVec(vecIn);
//
//	//去重
//	vecTest.uniqueVec(vecIn);
//	
//	
//	//逆序
//	cout<<"reverse()"<<endl;
//	reverse(vecIn.begin(),vecIn.end()); 
//	vecTest.printVec(vecIn);
//	
//	//手动反向访问
//	vecTest.reverseTest(vecIn);
//
//
//
//	system("pause");
//
//}