#pragma once
#include<iostream>
#include<vector>
#include <stack>
#include <queue>
#include <assert.h>
#include <string>
#include <algorithm>

#include <set>
#include <map>
#include<functional>


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
//
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
	   	   //move right
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

   /*
   输入两个整数序列，第一个序列表示栈的压入顺序，
   请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
   序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
   但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
   思路： 准备辅助栈，首先按入栈顺序压栈，如果辅助栈顶与弹出序列相同，则弹出，否则继续压
   */
   bool IsPopOrder(vector<int> pushV, vector<int> popV) 
   {
	   if (pushV.empty()) return false;
	   stack<int> stacktemp;
	   for (unsigned int i = 0 , j = 0 ; i <pushV.size() ; ++i)
	   {
		   stacktemp.push(pushV[i]);
		   while (j< popV.size()&&stacktemp.top()== popV[j])
		   {
			   stacktemp.pop();
			   j++;
		   }
	   }
	   return stacktemp.empty();
   }

   /*
       输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
	   分析：肯定需要用到递归的思路，考虑树的结构，需要另外一个函数来判定并且递归。
   */
   bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
   {
	   if (pRoot1 == NULL || pRoot2 == NULL) return false;
		  
	   return isTreeAHasTreeB(pRoot1, pRoot2)|| HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
   }
   //重点为在递归环境下判断是否为子树！
   bool isTreeAHasTreeB(TreeNode *pRoot1, TreeNode *pRoot2)
   {
	   if (pRoot2 == NULL)
		   return true;
	   if (pRoot1 == NULL)
		   return false;
	   if (pRoot1->val != pRoot2->val)
		   return false;
	   return isTreeAHasTreeB(pRoot1->left, pRoot2->left) && isTreeAHasTreeB(pRoot1->right, pRoot2->right);
	}

   /*
   从上往下打印出二叉树的每个节点，同层节点从左至右打印。
   分析，层次遍历二叉树， 打印根，然后存进队列， 然后left right 存进队列，每一个均这样，
   直到为null即存在一个递归过程？
   */
   std::vector<int> PrintFromTopToBottom(TreeNode *root) 
   {
	   vector<int> retVec;
	   if (root == NULL) return retVec;

	   std::deque<TreeNode*> nodeQueue; //存储二叉树节点；
	   nodeQueue.push_back(root);

	   while (!nodeQueue.empty())
	   {
		   TreeNode* temp = nodeQueue.front();
		   nodeQueue.pop_front();

		   retVec.push_back(temp->val);
		   if (temp->left)
		   {
			   nodeQueue.push_back(temp->left);
		   }
		   if (temp->right)
		   {
			   nodeQueue.push_back(temp->right);
		   }
	   }
	   return retVec;
   }

   /*
		输入一个整数数组，判断该数组是不是某二叉搜索树(排序特征)的后序遍历的结果。
		如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
		分析：
		(1)存入二叉树，分出左右子树，对右子树做判断，然后递归左右子树；
		(2)非常好的锻炼二叉树思维；可以尝试用迭代器做
   */
   bool VerifySquenceOfBST(std::vector<int> sequence)
   {
	   int root = sequence.back();

	   //找左边
	   unsigned int i = 0;
	   vector<int> leftTemp;
	   for (; i < sequence.size() - 1; i++)
	   {
		   leftTemp.push_back(sequence[i]);
		   if (sequence[i] > root)
		   {
			   leftTemp.pop_back();
			   break;
		   }
	   }

	   //找右子树
	   unsigned int j = i;
	   vector<int> rightTemp;
	   for (; j < sequence.size() - 1; j++)
	   {
		   rightTemp.push_back(sequence[j]);
		   if (sequence[j] < root)
		   {
			   return false;
		   }
	   }

	   //递归，
	   bool left = true;
	   if (!leftTemp.empty())
	   {
		   left = VerifySquenceOfBST(leftTemp);
	   }
	   bool right = true;  //防止为空
	   if (!rightTemp.empty())
	   {
		   right = VerifySquenceOfBST(rightTemp);
	   }
	   return left&&right;
   }

   /*
   输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
   路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
   分析：从根开始，则用到了先序遍历的知识，其次考虑递归，考虑递归返回条件。
   */
   std::vector<std::vector<int>> FindPath(TreeNode* root, int expectNumber) 
   {
	   std::vector<std::vector<int>> pathVec;
	   std::vector<int> tempPath;
	   int currentSum;
	   if(root) FindPathHelper(root, expectNumber, pathVec, tempPath, currentSum );
	   return pathVec;
   }
   //类似先序遍历的算法，加上判断叶子节点与维护currentSum,维护 pathVec;
   void FindPathHelper
   (   TreeNode* root, int expectNumber, std::vector<std::vector<int>> &pathVec,
       std::vector<int> &tempPath,   int currentSum 
   )
   {
	   currentSum += root->val;  //加上当前值；
	   tempPath.push_back(root->val);
	   //
	   if (currentSum == expectNumber && root->left == NULL && root->right )
	   {
		   pathVec.push_back(tempPath);//满足条件存储进去；
	   }
	   else
	   {
		   if (root->left)
		   {
			   FindPathHelper(root, expectNumber, pathVec, tempPath, currentSum);
		   }

		   if (root->right)
		   {
			   FindPathHelper(root, expectNumber, pathVec, tempPath, currentSum);
		   }

	   }

	   
	   //currentSum不用管
	   tempPath.pop_back(); //都不满足，则退一步
   }

   /*
		输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
		要求不能创建任何新的结点，只能调整树中结点指针的指向。
		分析：考虑一个二叉搜索树与双向链表均为两个指针将left，right转换为指向排序前后即可。
		考虑到二叉搜索树的排序特征。考虑用递归。
   */
   TreeNode* Convert(TreeNode* pRootOfTree)
   {
	   TreeNode* pLastNodeInList = NULL;  //指向双向链表的尾节点；
	   ConvertNodehelper(pRootOfTree, &pLastNodeInList);
	   
	   //回来到头节点
	   TreeNode * pHeadOfList = pLastNodeInList;
	   while (pHeadOfList!= NULL&& pHeadOfList->left !=NULL)
	   {
		   pHeadOfList = pHeadOfList->left;
	   }
	   return pHeadOfList;
   }

   void ConvertNodehelper(TreeNode* pNode, TreeNode** pLastNodeInList)
   {
	   if (pNode == NULL) return;  //如果为空，返回
		
	   TreeNode * pCurrentNode = pNode;

	   if (pCurrentNode ->left != NULL)
	   {
		   ConvertNodehelper(pCurrentNode->left, pLastNodeInList);
	   }

	   pCurrentNode->left = *pLastNodeInList;  //连接左子树最右边；
	   if (*pLastNodeInList!= NULL)
	   {
		   (*pLastNodeInList)->right = pCurrentNode;
	   }

	   *pLastNodeInList = pCurrentNode; //现在转换一个，将当前节点转换为双向链表最后一个节点。

	   if (pCurrentNode->right!= NULL)
	   {
		   ConvertNodehelper(pCurrentNode->right, pLastNodeInList);
	   }
   }


   /* 字符串的排列
	输入一个字符串,按字典序打印出该字符串中字符的所有排列。
	例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所
	有字符串abc,acb,bac,bca,cab和cba。 结果请按字母顺序输出

	分析：（1）考虑，假如固定第一个字符，将后面的字符做排列（逐个交换）。
	（2）即将字符串分为两个部分，第一个字符和后面的，然后逐个后面的与第一个字符交换；
	（3）然后固定第一个字符，后交换后面的。
	（4）每次交换，递归-之后需要换回来

   */
   std::vector<std::string> Permutation(std::string str) 
   {
	   std::vector<std::string> retVecString;
	   if (str.empty()) return retVecString;
	   size_t pos = 0;

	   permutation(retVecString, str, pos);
	   
	   std::sort(retVecString.begin(), retVecString.end());  //按字典顺序输出；

	   return retVecString;  
   }

   void permutation(std::vector<std::string> &retVecString, std::string str, size_t pos)
   {
	   if (pos == str.size()-1)   //返回条件，换到了最后一个
	   {
		   retVecString.push_back(str);
	   }
	   else
	   {
		   for (size_t i = pos ; i< str.size() ;++ i)
		   {
			   if (str[i] == str[pos] && i != pos )  //有重复字符时，跳过
			   {
				   continue;
			   }
			   //交换
			   std::swap(str[i], str[pos]);

			   permutation(retVecString, str, pos + 1);  //确定了固定下一个开始交换；

			   std::swap(str[i], str[pos]);
		   }
	   }
   }

   /*组合*/
   void Combination(char *string)
   {
	   assert(string != NULL);
	   vector<char> result;
	   int i, length = strlen(string);
	   for (i = 1; i <= length; ++i)
		   Combination(string, i, result);
   }

   void Combination(char *string, int number, vector<char> &result)
   {
	   assert(string != NULL);
	   if (number == 0)
	   {
		   static int num = 1;
		   printf("第%d个组合\t", num++);

		   vector<char>::iterator iter = result.begin();
		   for (; iter != result.end(); ++iter)
			   printf("%c", *iter);
		   printf("\n");
		   return;
	   }
	   if (*string == '\0')
		   return;
	   result.push_back(*string);
	   Combination(string + 1, number - 1, result);
	   result.pop_back();
	   Combination(string + 1, number, result);
   }





   /*
       数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
	   例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
	   超过数组长度的一半，因此输出2。如果不存在则输出  0 。
	   (1)简单的思路排序，找中位数。那么，时间复杂度O(n);
	   (2)直接找中位数。(中快排中的partition)

	   方法二：不修改的方式，加标志位：当前数字，次数。维护次数
   */
   int MoreThanHalfNum_Solution(std::vector<int> numbers) 
   {
	   if (numbers.empty()) return 0; //输入错误  。。 或者没有超过一半的
	  
	   int length = numbers.size()-1;
	   int middle = length >> 1;   //中间位置
	   int low = 0; 
	   int high = length - 1;
	   int index = partition(numbers, low , high);
	   while (index != middle)
	   {
		   if (index > middle)
		   {
			   high = middle - 1;
			   index = partition(numbers, low, high);
		   }
		   else if (index <middle)
		   {
			   low = middle;
			   index = partition(numbers, low, high);
		   }
	   }
	   return  checkTheNumber(numbers, numbers[middle]);
   }

   int checkTheNumber(std::vector<int> numbers, int checkNum)
   {
	   int times = 0;
	   
	   for (std::vector<int>::const_iterator ita = numbers.begin(); ita != numbers.end();++ita)
	   {
		   if (*ita == checkNum)
		   {
			   times++;
		   }
	   }
	   return times * 2 > numbers.size() ? checkNum : 0;
   }

   void swap(int &a, int &b)
   {
	   int temp = a;
	   a = b;
	   b = temp;   
   }

   int  partition(vector<int> &numbers, int low, int high)
   {
       int privotKey = numbers[low];
	   while (low<high)
	   {
		   while (low < high && numbers[high] >= privotKey) --high;
		   swap(numbers[low], numbers[high]);
		   while (low < high && numbers[low] <= privotKey) ++low;
		   swap(numbers[low], numbers[high]);
	   }
	   return low;   
   }

   //数组中多余一半的数字
   int MoreThanHalfNum(std::vector<int> numbers)
   {
	   if (numbers.empty())   return 0;
	   int tempNum ;  // 暂存数
	   int times = 0;    //次数
	   
	   for (std::vector<int>::const_iterator ita = numbers.begin(); ita != numbers.end(); ++ita)
	   {
			if (times == 0)
			{
				times = 1;
				tempNum = *ita;
			}
			else if (*ita == tempNum)
			{
				times++;
			}
			else
			{
				times--;
			}
	   }

	   return checkTheNumber(numbers , tempNum);
   }

   /*
	  找出数组中最小的k个数
	  分析：简单的方法，排序sort，前k个数；
	  方法2;利用partition. O(n)
	  方法三：O(nlogk)
   */
   std::vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
   {
	   std::vector<int> leastNumbers;
	   if (input.empty() || input.size() < k || k <= 0) return leastNumbers;

	   int low = 0; 
	   int high = input.size() -1;
	   int index = partition(input, low, high);  //此处的partition必须参数input为引用
	   while (index!=k -1)
	   {
		   if (index >k -1)
		   {
			   high = index - 1;
			   index = partition(input, low, high);
		   }
		   else
		   {
			   low = index+1;
			   index = partition(input, low, high);
		   }
	   }
	   return std::vector<int>(input.begin(), input.begin()+k);
   }

   //方法三:利用set实现，multiset
   //快的原因，set实现插入删除为O(logk)
   //考虑海量数据的原因，不能直接将vec插入set而是按需求
   std::vector<int> GetLeastNumber(vector<int> input, int k)
   {
	   std::vector<int> leastVec;
	   if (input.empty() || input.size() < k || k <= 0) return std::vector<int>();

	   //仿函数greater<int> 从大到小排序
	   std::multiset<int , std::greater<int>> leastSet;

	   for (vector<int>::iterator ita = input.begin() ; ita!=input.end();++ita)
	   {
		   if (leastSet.size()<k)
		   {
			   leastSet.insert(*ita);
		   }
		   else
		   {
			   multiset<int, greater<int> >::iterator greatest_it = leastSet.begin();
			   if (*ita < *greatest_it)
			   {
				   leastSet.erase(*greatest_it);
				   leastSet.insert(*ita);
			   }
		   }
	   }
	   return std::vector<int>(leastSet.begin(),leastSet.end());		
   }


   /*
	  计算连续子向量的最大和。
	  但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
	  例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
	  分析:没有要求求出该连续子数组；只需要求出该最大值； 
      （2）动态规划法
   */
   int FindGreatestSumOfSubArray(std::vector<int> array)
   {
	   if (array.empty()) return 0;

	   int TempSum = 0;
	   int GreatSum = array[0];
	   for(unsigned int i = 0 ; i <array.size() ; ++i)
	   {
		   if (TempSum<0)
		   {
			   TempSum = array[i];
		   }
		   else
		   {
			   TempSum += array[i];
		   }

		   if (TempSum>GreatSum)
		   {
			   GreatSum = TempSum;
		   }
	   }
	   return GreatSum;
   }

   /*
   整数中1出现的次数（从1到n整数中1出现的次数）
   数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次
   分析:(1)用蠢办法，一个个遍历分析位。
   */
   int NumberOf1Between1AndN_Solution(int n)
   {
	   if (n < 1) return 0;

	   int timesOfOne = 0;
	   for (int i = 1 ; i <= n ; i++)
	   {
		   timesOfOne += NumberOf1Bit(i);
	   }

	   return timesOfOne;
   }
   //求该数中1的位数。
   int NumberOf1Bit(int n)
   {
	   int retNumber = 0;
	   while (n != 0)
	   {
		   int tempBit = n % 10;  //余数
		   if (tempBit ==1)
		   {
			   retNumber++;
		   }
		   n = n / 10;
	   }
	   return retNumber;
   }

   /*
		把数组排成最小的数
   */
   string PrintMinNumber(vector<int> numbers)
   {
	   
   }

   /*
	 把只包含因子2、3和5的数称作丑数（Ugly Number）。
	 例如6、8都是丑数，但14不是，因为它包含因子7。
	 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
	 分析:(1)从1开始求出所有index的丑数。丑数判断用fator2，3，5
   */
   int GetUglyNumber_Solution(int index) \
   {
	   if (index < 1) return 0;
	   int times = 0;
	   int num = 1; //初始值
	   for (; times < index; num++)
	   {
		   if (IsUgly(num))
		   {
			   times++;
			   printf(" The index :%d   num: %d  \n", index, num);
		   }
	   }
	   return num;
   }

   bool IsUgly(int number)
   {
	   while (number % 2 == 0) number = number / 2;
	   while (number % 3 == 0) number = number / 3;
	   while (number % 5 == 0) number = number / 5;

	   if (number ==  1)
	   {
		   return true;
	   }
	   else 
	   {
		   return false;
	   }
   }

   //理解dp
   int GetUglyNumber_DP(int index) {
	   if (index <= 0) return 0;
	   if (index == 1) return 1;
	   vector<int>k(index); k[0] = 1;
	   int t2 = 0, t3 = 0, t5 = 0;
	   for (int i = 1; i<index; i++) {
		   k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
		   if (k[i] == k[t2] * 2) t2++;
		   if (k[i] == k[t3] * 3) t3++;
		   if (k[i] == k[t5] * 5) t5++;
	   }
	   return k[index - 1];
   }

   /*
      第一个只出现一次的字符 .
	  在一个字符串(1<=字符串长度<=10000，
	  全部由大小写字母组成)中找到第一个只出现一次的字符,并返回它的位置. 
	  分析：用一个数组存储出线过字符的次数，输出第一个一次的。
	  避免O(n2)算法，利用哈希表，存储出线字符的次数
   */
   int FirstNotRepeatingChar(string str) 
   {
	   if (str.empty()) return -1;

	   int hash[256] = { 0 };
	   
	   
	   for(int i = 0; i < str.length();++i)
	   {
		   hash[str[i]] += 1;  //次数加1；
	   }
	   
	   for(int	 i = 0 ; i <str.length();++i)
	   {
		   if (hash[str[i]] == 1) return i;
	   }
	   return -1;
   }

   //是否是大端模式判断；
   //方式一：强制类型转换
   bool IsBig_endian()
   {
	   int a = 0x12345678;
	   //printf("%#x", char(a));

	   for (size_t i = 0; i < 4; i++)
	   {
		   printf("%#x ----%p \n", *((char*)(&a) + i), (char*)&a + i);
	   }
	   if (*(char*)(&a) == 0x78)
	   {
		   printf("big_endian\n");
		   return true;
	   }
	   else
	   {
		   printf("little_endian\n");
		   return false;
	   }
   }
   //利用共同体所有数据均从同一位置开始存储
   bool IsBIg_endian_byUnion()
   {
	   union endianTest
	   {
		   int data;
		   char ch;
	   };
	   endianTest test;
	   test.data = 0x12345678;
	   printf("%d  \n",sizeof(test));
	   if (test.ch == 0x78)
	   {
		   printf("big_endian\n");
		   return true;
	   }
	   else
	   {
		   printf("little_endian\n");
		   return false;
	   }
   }


   /*
		找到两个单链表的第一个公共节点
		（1）暴力法：list1遍历每一个节点遍历一次第二个节点，这样判断。
	    （2）使用辅助栈：两个栈存两个链表。反过来，一个一个判断是相等。
		（3）第一次遍历，判断长度，长的先走N步，然后一个一个比较。
   */
   ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) 
   {
	   ListNode* retList(0);
	   if (pHead1 == NULL || pHead2 == NULL) return retList ;

	   unsigned int lengthOne = GetListLength(pHead1);
	   unsigned int lengthTwo = GetListLength(pHead2);


	   //赋值  注意pHeadLong需要指向较长的一个
	   ListNode* pHeadLong  = pHead1;
	   ListNode* pHeadShort = pHead2;
	   unsigned int diffLength = lengthOne > lengthTwo ? lengthOne - lengthTwo : lengthTwo - lengthOne;
	   if (lengthTwo >lengthOne)
	   {
		   ListNode* pHeadLong = pHead2;
		   ListNode* pHeadShort = pHead1;
	   }

	   for (unsigned i = 0; i < diffLength; i++)
	   {
		   pHeadLong = pHeadLong->next;
	   }
	   //一起往后走
	   while (pHeadLong!=NULL&&pHeadShort!=NULL&& pHeadLong!= pHeadShort)
	   {
		   pHeadLong = pHeadLong->next;
		   pHeadShort = pHeadShort->next;
	   }
	   
	   retList = pHeadLong;
	   return retList;
	   
   }

   unsigned int GetListLength(ListNode* Head)
   {
	   ListNode* pNode= Head;
	   unsigned int length = 0;
	   while (pNode)
	   {
		   ++length;
		   pNode = pNode->next;
	   }
	   return length;
   }

   /*
	统计一个数字在排序数组中出现的次数。
	1. 利用stl；
	2. 二分法找重复数组的第一个和最后一个(在相等的时候再做判断+1)
   */
   int GetNumberOfK(vector<int> data, int k) 
   {
	   std::vector<int>::iterator ita =  std::find(data.begin(), data.end(), k);
	   int times = 0;
	   
	   while (ita != data.end() && *ita == k )  //防止越界；
	   {
		   ++ita;
		   ++times;
	   }

	   //return std::count(data.begin(), data.end(), k);
	   return times;
   }

   /*
      求：  二叉树的深度。
	  分析:递归，找左右
	*/
   int TreeDepth(TreeNode* pRoot)
   {
	   if (pRoot == NULL) return 0;

	   int left  = TreeDepth(pRoot->left);
	   int right = TreeDepth(pRoot->right);

	   return left > right ? left + 1 : right + 1;
   }

   /*
	  判断该树属否是平衡二叉树；
	  (1) 分析：递归查找左右深度，如果高度大于一返回false,；递归左右子树
	  (2) 
   */
   bool IsBalanced_Solution(TreeNode* pRoot) 
   {
	   if (pRoot == NULL) return true;

	   int left = TreeDepth(pRoot->left);
	   int right = TreeDepth(pRoot->right);

	   if ((left - right) > 1 || (left - right) < -1)  return false;
	   
	   return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
   }

   /*
	  数组中只出现一次的数字 :一个整型数组里除了两个数字之外，
	  其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
	  分析：利用异或性质
   */
   void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
   {
	   if (data.empty() || data.size() < 2) return;  //错误返回;

	   int xorTemp = 0;
	   for (size_t i = 0; i < data.size(); i++)
	   {
		   xorTemp ^= data[i];  //得到最后的xor
	   }

	   //如何分为两个数？
	   int flag = 1;
	   while ( (xorTemp&flag) == 0)  //即将flag还原为xor?
	   {
		   flag <<= 1;  //左移一位
	   }

	   *num1 = xorTemp;
	   *num2 = xorTemp;

	   for (int i = 0; i < data.size(); ++i)
	   {
		   if ((flag & data[i]) == 0)  //如果在该位flag位为0；
		   {
			   *num2 ^= data[i];       //相与
		   }
		   else
		   {
			   *num1 ^= data[i];
		   }
	   }
    }
	   /*
		  和为S的连续正数序列；
	   */
	   vector<vector<int> > FindContinuousSequence(int sum) 
	   {

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



	 /*
	 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
	 */	 
	 class StackWithMin 
	 {
		
		 std::stack<int> m_data;
		 std::stack<int> m_min;
	  public:
		 void push(int value) {
			 m_data.push(value);

			 if (m_min.empty())
			 {
				 m_min.push(value);
			 }
			 else if (m_min.top() < value)
			 {
				 m_min.push(m_min.top());
			 }
			 else if (m_min.top() >= value)
			 {
				 m_min.push(value);
			 }
		 }
		 void pop() {
			 assert(m_data.empty());

			 m_data.pop();
			 m_min.pop();
		 }
		 int top() {
			 assert(m_data.empty());

			 return m_data.top();

		 }
		 int min() 
		 {
			 assert(m_data.empty());
			 return m_min.top();
		 }
	 };

bool TestNewSolution()
{
	newSolution solutionIns;
	//空格替换
	//char str[20] = "We are happy!";
	//solutionIns.replaceSpace(str, 1000);

	//从尾到头输出列表
	//TwoQueueStack qStack;
	//qStack.push(1);
	//qStack.push(2);
	//int a = qStack.pop();
	//qStack.push(3);
	//qStack.push(4);
	//int b = qStack.pop();
	//int c = qStack.pop();
	//std::cout<< a << b << c << std::endl;

	//输出最小的k个树
	//int array[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	//int arrLen = sizeof(array) / sizeof(int);
	//std::vector<int> vecInput = std::vector<int>(array, array + arrLen);
	//std::vector<int> retvec = solutionIns.GetLeastNumbers_Solution(vecInput, 4);
    
	solutionIns.IsBig_endian();
	solutionIns.IsBIg_endian_byUnion();
	


	//solutionIns.
	return true;
	//
}
