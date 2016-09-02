#pragma once
#include<iostream>
#include<vector>
#include <stack>
#include <queue>
/*
newcoder solutions
*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


class newSolution {
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
    bool Find(std::vector<std::vector<int> > array,int target) {
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
    void replaceSpace(char *str,int length) 
	{
		int lenthOld = strlen(str); 
		for (int i = 0; i < lenthOld; i++)
		{
			printf("%c", str[i]);
		}
		printf("\n");
		int count = 0; //sapce count
		for (int i = 0; i < lenthOld; i++)
		{
			if (str[i] == ' ')
			{
				count++;
			}

			i++;
		}
		int lengthNew = lenthOld + 2 * count -1;  //1+2->3 -1 dute to from zero;
		
		for (int i = lenthOld - 1; i >= 0 && lengthNew != i; --i)
		{
			if (str[i] == ' ')
			{
				str[lengthNew--] = '0';
				str[lengthNew--] = '2';
				str[lengthNew--] = '%';
			}
			else
			{
				str[lengthNew--] = str[i];
			}
			
		}
		std::cout << "\n print relpaceStr: \n";
		int lentghUptodate = strlen(str);
		for (int i = 0; i < lentghUptodate; i++)
		{
			printf("%c", str[i]);
		}
		printf("\n");

    }
	
	
	
	  /*
		从尾到头打印链表  尾->头
		（1）stack
		（2）递归
	  */
	std::vector<int> printListFromTailToHead(struct ListNode* head) 
	{
		//先进后出
		std::stack<int> storeStack;
		while (NULL != head)
		{
			storeStack.push(head->val);
			head = head->next;
		}
		std::vector<int> retVec;
		while (!storeStack.empty())
		{
			retVec.push_back(storeStack.top());
			storeStack.pop();
		}

		return retVec;


		//递归
		//std::vector<int> vecHold;
		//while (NULL != head)
		//{
		//	 printListFromTailToHead(head->next);
		//}
		//vecHold.push_back(head->val);
		//return vecHold;
	}


	
	
	
	/*
		输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
		例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
		中序遍历的根节点位置在中间p
		*/
struct TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> in)
{
	int inSize = in.size();
	if (inSize == 0)
	{
		return NULL;
	}

	std::vector<int> pre_left, pre_right, in_left, in_right;

	int val = pre[0];

	TreeNode* Node = new TreeNode(val); //root node is the first node of the pre

	int InRootTemp = 0;
	for (; InRootTemp < inSize; ++InRootTemp)
	{
		if (val == in[InRootTemp])  //find the root position in the in 
		{
			break;
		}
	}

	//assignment for pre and in ;
	for (int i = 0; i < inSize; ++i)
	{
		if (i < InRootTemp)
		{
			in_left.push_back(in[i]);
			pre_left.push_back(pre[i + 1]);   //i+1 
		}
		else if (i >InRootTemp)
		{
			in_right.push_back(in[i]);
			pre_right.push_back(pre[i]);
		}
	}

	Node->left = reConstructBinaryTree(pre_left, in_left);
	Node->right = reConstructBinaryTree(pre_right, in_right);

	return Node;
}


/*
	递归打印后序二叉树
	*/
void post_tree(TreeNode * Root)
{
	if (Root != NULL)
	{
		post_tree(Root->left);
		post_tree(Root->right);
		printf("%d ", Root->val);
	}
}

/*
		把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
		输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
		例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
		NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
		*/
int minNumberInRotateArray(std::vector<int> rotateArray)
{
	if (rotateArray.empty())
	{
		return 0;
	}
	int mid, left = 0, right = rotateArray.size() - 1;
	//根据特点用二分法找
	while (right - left != 1)
	{
		mid = left + (right - left) / 2;
		if (rotateArray[left] <= rotateArray[mid])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return rotateArray[right] > rotateArray[left] ? rotateArray[left] : rotateArray[right];
}

/*
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
	所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
	（1）类似插入排序
	（2）第二个思路：再创建一个临时数组 ， 遇见偶数加入新数组的同时在老数组中删除该值，将新数组添加到老数组里
*/
void reOrderArray(std::vector<int> &array)
{
	if (array.empty())
	{
		return;
	}
	//考虑奇偶位置 插入排序
	for (size_t i = 0; i < array.size(); ++i)
	{
		if( (array[i]%2 )==1)
		{
			int temp = array[i];
			int j = i - 1;
			while (j>=0 && (array[j]%2)==0 )
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = temp;
		}

	}

	
}


/*
	输入一个链表，输出倒数第k个指针
	1.可以考虑存进栈中再取出来，这个是不可以的，因为链表改变了就改变了。
	2.考虑跟随，一个链表先走k步，如果为空，后面的输出
*/
   ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
   {
	    if (pListHead==NULL||k<0) return NULL;
	    ListNode *preNode = pListHead;
		ListNode *followNode  = pListHead;
		//先跑k步
		for (unsigned int i = 0; i < k; i++)
		{
			if(preNode -> next == NULL) return NULL;
			else
			{
				preNode = preNode->next;
			}			
		}
		while (preNode!=NULL)
		{
			preNode = preNode->next;
			followNode = followNode->next;
		}
		return followNode;
    }

   /*
	  输入一个链表，反转链表后，输出链表的所有元素。
      第一时间栈的都是傻逼
	  (1)考虑逐步反转！！！三个指针，分别指向当前pHead，之前pre，之后next
	  (2)用递归
   */
   ListNode* ReverseList(ListNode* pHead) 
   {
	   ListNode *pre  = NULL;
	   ListNode *next = NULL;
	   while(pHead!=NULL)
	   {
		   next = pHead->next;
		   pHead->next = pre;
		   pre = pHead;
		   pHead = next;
		   
	   }
	   return pre;
   }

   /*
   递归的方法其实是非常巧的，它利用递归走到链表的末端，然后再更新每一个node的next 值 ，实现链表的反转。而newhead 的值没有发生改变，为该链表的最后一个结点，所以，反转后，我们可以得到新链表的head。
   注意关于链表问题的常见注意点的思考：
   1、如果输入的头结点是 NULL，或者整个链表只有一个结点的时候
   2、链表断裂的考虑
   */
   ListNode *ReverseListRec(ListNode *pHead)
   {
	   //如果链表为空或者链表中只有一个元素
	   if(pHead==NULL||pHead->next==NULL) return pHead;

	   //先反转后面的链表，走到链表的末端结点
	   ListNode* pReverseNode=ReverseList(pHead->next);

	   //再将当前节点设置为后面节点的后续节点
	   pHead->next->next=pHead;
	   pHead->next=NULL;

	   return pReverseNode;
   }
   
 /*
	输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
	考虑单链表的生成？两个node
	（1）非递归 ， 内存超出，也不清楚怎么回事
	（2）递归
 */
   ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
   {
	   if (pHead1 == NULL)
	   {
		   return pHead2;
	   }
	   if (pHead2 == NULL)
	   {
		   return pHead1;
	   }
	   ListNode *ListNodeMerged = new ListNode(-1);
	   ListNode * Head= ListNodeMerged;
	   ListNode *tail ; 

	   while (pHead1 != NULL || pHead2 != NULL)
	   {
		   if(pHead1->val < pHead2->val)
		   {
			   tail = new ListNode(pHead1->val);
			   Head->next = tail;
			   Head = tail;
			   pHead1 = pHead1->next;
		   }
		   else
		   {
			   tail = new ListNode(pHead2->val);
			   Head->next = tail;
			   Head = tail;
			   pHead1 = pHead2->next;
		   }
	   }
		
	   while (pHead1!= NULL)
	   {
		   tail = new ListNode(pHead1->val);
		   Head->next = tail;
		   Head = tail;
		   pHead1 = pHead1->next;
	   }
	   while (pHead2!= NULL)
	   {
		   tail = new ListNode(pHead2->val);
		   Head->next = tail;
		   Head = tail;
		   pHead1 = pHead2->next;
	   }

	   return ListNodeMerged;
   }
   //递归
   ListNode* MergeRec(ListNode* pHead1, ListNode* pHead2)
   {
	   ListNode* node=NULL;
	   if(pHead1==NULL){return node=pHead2;}
	   if(pHead2==NULL){return node=pHead1;}
	   if(pHead1->val>pHead2->val){
		   node=pHead2;
		   node->next=MergeRec(pHead1,pHead2->next);
	   }else
	   {
		   node=pHead1;
		   node->next=MergeRec(pHead1->next,pHead2);
	   }
	   return node;

   }



      /*
	二叉树镜像
	分析：肯定是要用递归。比如选择用先序遍历二叉树的思路，然后pRoot->left <-> pRoot->right 然后递归pRoot->left,right 
  */
   void MirrorTree(TreeNode *pRoot)
   {
	   if (pRoot == NULL) return ;
	   
	   //左右子树互换镜像。
	   TreeNode *pTemp = pRoot->left;
	   pRoot->left = pRoot->right;
	   pRoot->right = pTemp;
	   
	   MirrorTree(pRoot->left);
	   MirrorTree(pRoot->right);
   }

   /*
   输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
   如果输入如下矩阵：  1  2  3  4 
                       5  6  7  8 
					   9 10 11 12
					  13 14 15 16 
   则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
   分析：用四个状态来表示 右j+1 , 下 i+1 左j-1 上i-1
         如何记录走几步？
		 // 定义四个关键变量，表示左上和右下的打印范围
		 int left = 0, top = 0, right = col - 1, bottom = row - 1;
		 主要的问题出在没有控制好后两个for循环，需要加入条件判断，防止出现单行或者单列的情况。

   */
   std::vector<int> printMatrix(std::vector<std::vector<int> > matrix) 
   {
	   std::vector<int> retVec;

	   int row = matrix.size();
	   int col = matrix[0].size();

	   if (row==0||col==0)
	   {
		   return retVec;
	   }
  
	   int left = 0 , right = col -1 ,top = 0 , buttom = row -1;

	   while (left<=right&&top<=buttom)
	   {
	   	   //move ringt
		   for (int i = left;i<=right;++i)
			   retVec.push_back(matrix[top][i]);
		   //move dowm
		   for (int i = top+1; i<=buttom;++i)
				retVec.push_back(matrix[i][right]);
		   //move left
		   if(buttom!=top)
		   for (int i = right-1; i >= left; --i)
		       retVec.push_back(matrix[buttom][i]);
		   //move up
		   if (left!=right)
		   for (int i = buttom-1; i > top; --i)
		   	   retVec.push_back(matrix[i][left]);  	
			left++;right--;top++;buttom--;
	   }
	   return retVec;
   }


};  


	 /*
		two stacks make a queue, implement
	 */
	 class TwoStackQueue
	 {
	 public:
		 void enQueue(int node) 
		 {
			 stack1.push(node);
		 }

		 int deQueue() 
		 {
			 while (!stack1.empty())
			 {
				 stack2.push(stack1.top());
				 stack1.pop();
			 }
			 if (stack2.empty())
			 {
				 throw "pop empty stack";
			 }
			 else 
			 {
				 int ret = stack2.top();
				 stack2.pop();
				while (!stack2.empty())
				 {
					 stack1.push(stack2.top());
					 stack2.pop();
				 }
				 return ret;
			 }
		 }

	 private:
		 std::stack<int> stack1;
		 std::stack<int> stack2;
	 };

	 /*
		two queues make a stack. 
	 */
	 class TwoQueueStack
	 {
	 public:
		void push(int node)
		{
			queue1.push(node);		
		}
		 
		int pop()
		{
			int ret = 0;
			if (queue1.empty())
			{
				throw "queue pop error! \n";
			}
			else
			{ 
				while (!queue1.empty())
				{
					ret = queue1.front();
					queue1.pop();
					queue2.push(ret);
				}
				while (queue2.size() > 1)
				{
					queue1.push(queue2.front());
					queue2.pop();
				}
				queue2.pop();

				return ret;
			}		
		}
	 
	 private:
		 std::queue<int> queue1;
		 std::queue<int> queue2;
	 };



bool TestNewSolution()
{
	newSolution solutionIns;
	//空格替换
	//char str[20] = "We are happy!";
	//solutionIns.replaceSpace(str, 1000);

	//从尾到头输出列表
	
	TwoQueueStack qStack;
	qStack.push(1);
	qStack.push(2);
	int a = qStack.pop();
	qStack.push(3);
	qStack.push(4);
	int b = qStack.pop();
	int c = qStack.pop();

	std::cout<< a << b << c << std::endl;

	//solutionIns.
	return true;
}