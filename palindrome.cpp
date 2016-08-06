//回文串相关palindrome

//#include<iostream>
//#include <string>
//#include <algorithm>
//using namespace std;	
//
//string MaxCircleStr(string strInput)
//{
//	string strLeft,strRight;
//	 int length =strInput.length();
//	for(size_t i = 0;i< strInput.length()/2 ;  i++ )
//	{
//		int right =length -i-1;	
//		if (strInput[i] == strInput[length-i-1])
//		{
//			
//			strLeft +=  strInput[i];
//			strRight += strInput[length-i-1];
//		}
//	}
//	if (strInput.length()%2 !=0)
//	{
//		strLeft += strInput[length/2];
//	
//	}
//	//sort(strLeft.begin(),strLeft.end());
//	for (size_t i = 0 ; i<strRight.length();i++)
//	{
//	   strLeft += strRight[strRight.length()-i-1];
//	}
//	return strLeft;
//}
//
//void main()
//{
//	string strIn,strOut;
//	//cin>>strIn;
//	
//	strIn = "aceefeecd" ;
//	//strIn="cababbacefgheggfeca";
//	for (size_t i = 0 ; i < strIn.length();i++)
//	{
//		cout<<strIn[i]<<endl;
//	}
//	strOut  = MaxCircleStr(strIn);
//	cout<<strOut<<"   ::长度：：  "<<strOut.length();
//
//    
//}