//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
////   vector    ����ʹ�� 
////            erese()  unique()   vector<int>::reverse_iterator it 
////  algorithm  ����ʹ��
////             sort() ;  reverse()
//
//
////vector ������
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
//	//ȥ�ظ�
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
//    //���vec
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
//	VectorTest vecTest;  //ʵ����vector ������
//	vecIn.push_back(3);
//	vecIn.push_back(1);
//	vecIn.push_back(5);
//	vecIn.push_back(3);
//	vecIn.push_back(2);
//	cout<<"input vector"<<endl	;
//	vecTest.printVec(vecIn);
//		
//	//����
//	vecTest.SortVec(vecIn);
//
//	//ȥ��
//	vecTest.uniqueVec(vecIn);
//	
//	
//	//����
//	cout<<"reverse()"<<endl;
//	reverse(vecIn.begin(),vecIn.end()); 
//	vecTest.printVec(vecIn);
//	
//	//�ֶ��������
//	vecTest.reverseTest(vecIn);
//
//
//
//	system("pause");
//
//}