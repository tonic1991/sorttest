/*
	大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39 
*/
class Solution {
public:
    int Fibonacci(int n) {
    	if (n < 0)
    	{
    		return -1;
    	}
    	int preFstNum = 0 ,preScdNum = 1 ;
    	int result = 0;
    	if (n == 0)
    	{
    		return preFstNum;
    	}
    	else if (n == 1)
    	{
    		return preScdNum;
    	}else
    	{
    		for (int i = 2; i <= n; ++i)
    		{
    			result = preFstNum + preScdNum;
    			preFstNum = preScdNum;
    			preScdNum = result;
    		}

    		return result;
    	}
    }
};
