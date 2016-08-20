/*
	大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39 
*/
class Solution {
public:
    /*
        大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
        n<=39 
    */
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

    /*
        一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
    */
    int jumpFloor(int number) {
        if (number < 0)
        {
            return -1;
        }
        int preFstNum = 0 ,preScdNum = 1 , preScdNumTwo = 2;
        int result = 0;
        if (number == 0)
        {
            return preFstNum;
        }
        else if (number == 1)
        {
            return preScdNum;
        }else if (number == 2)
        {
            return preScdNumTwo;
        }
        {
            for (int i = 3; i <= number; ++i)
            {
                result = preScdNum + preScdNumTwo;
                preScdNum = preScdNumTwo;
                preScdNumTwo = result;
            }

            return result;
        }

    }

    /*
        一只青蛙一次可以跳上1级台阶，也可以跳上2级……
        它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
      (1)  每个台阶都有跳与不跳两种情况（除了最后一个台阶），最后一个台阶必须跳。所以共用2^(n-1)种情况  

      (2)n = n时，会有n中跳的方式，1阶、2阶...n阶，得出结论：
    f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n) => f(0) + f(1) + f(2) + f(3) + ... + f(n-1)
    
    */
    int jumpFloorII(int number) {
        if (number <= 0 )
        {
            return 0;
        }
        else if (number == 1)
        {
             return 1;
        }
        else 
        {
            int fstNum = 1 ,scdNum = 2;
            for (int i = 2; i <= number; ++i)
            {
                scdNum = 2*fstNum;
                fstNum = scdNum;
            }
            return scdNum;
        }
    }

    /*
        我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
        请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
    */
    int rectCover(int number) 
    {
        if (number <= 0 )
        {
            return 0;
        }
        int  *rec = new int[number +1];
        rec[1] = 1 ;
        rec[2] = 2  ;
        for (int i = 3; i < number+1; ++i)
        {
            rec[i] = rec[i-1] +rec [i-2];
        }
        return rec[number];
    }

    /*
        二进制中的1的个数 
        1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，
        会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
    */
    int  NumberOf1(int n) {
         int count ; //二进制中1的个数；
         while(n != 0)
         {
            n = (n-1)&n;
            ++count;
         }
         return count;
     }

     /*
     在一个二维数组中，每一行都按照从左到右递增的顺序排序，
     每一列都按照从上到下递增的顺序排序。
     请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
     左下角开始找
     */
     bool Find(vector<vector<int> > array,int target) {
      int  rowNum = array.size(); 
      int  colNum = array[0].size() ;
      int  col = 0 , row = rowNum-1 ;
      while(col <= colNum-1 && row >= 0)
      {
        if (target == array[row][col])
        {
            return true;
        }
        else if (target < array[row][col])
        {
            row--;
            continue;
        }
        else if (target > array[row][col])
        {
            col++;
            continue;
        }
      }
      return false;
    }

    /*
        请实现一个函数，将一个字符串中的空格替换成“%20”。
        例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
    */
    void replaceSpace(char *str,int length) {

    }





};  
