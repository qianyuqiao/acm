### 2. Add Two Numbers
看了一下别人的答案，while 和 new ListNode()都是OK的啦，调试和给分的编译器不一样，给分的编译器认为ListNode* head 后面没有 = NULL的话是个随机非空的.
递归的话只要7行。
### 3. Longest Substring Without Repeating Characters
二刷的时候一看就知道是滑动窗口，注意字符串可能为空
### 4. Median of Two Sorted Arrays
两种思路，1.摁葫芦法，<br>
要找第k个数(k从1开始数)，如果A[i] > B[j]且i+1+j+1 = k那么边界一定在索引j的后面，通过不断试探来确定边界
![这里随便写文字](https://github.com/qianyuqiao/scripts/blob/master/median.jpg)
2.二分查找法查找中位数
设长为m较短数列A的左边有i个数，那么为了兼顾奇偶，长为n较长数列B的左边有j = (m+n+1)/2-i个数<br>
我们找到的结果必定满足以下之一:<br>
i = 0 && B[j-1] <= A[i]<br>
i = m && A[i-1] <= B[j]<br>
j = 0 && A[i-1] <= B[j]<br>
j = n && B[j-1] <= A[i]<br>
A[i-1] <= B[j] && B[j-1] <= A[i]<br>
### 5. Longest Palindromic Substring
用dp做的话，简单;<br>
用镜面扩展的话，也简单
### 6	ZigZag Conversion
简单题不解释，注意numRows=1的特殊情况
### 7. Reverse Integer
注意临界条件，用long long int表示x
### 8.String to Integer (atoi)（恶心）
纯粹恶心人的，不做也罢
### 9. Palindrome Number
简单题
### 10. Regular Expression Matching
好题，难点在于匹配到"\*"号的时候
```
容易错的地方在于多次匹配 必须是dp[i-1][j]
else if (p[j-1] == '*') 
{
    dp[i][j] = dp[i][j-2] || dp[i][j-1];//任何人都能匹配0次或1次
    if (p[j-2] == '.' || p[j-2] == s[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j]; // 匹配多次,这里容易错，必须是dp[i-1][j],因为可能是aaa和.*
}
```
### 11. Container With Most Water
移动短板才可能使面积变大，所以每次向中心移动短板吧
### 12. Integer to Roman
你把1000,2000,3000,100,200,300,400,500,600,700,800,900,10,20,30,40,50,60,70,80,90,1,2,3,4,5,6,7,8,9这些数字和对应罗马文字提前写好就行了啊
### 13. Roman to Integer
简单题，第一遍做的时候都能秒杀。。
### 14. Longest Common Prefix
简单题，拿第一个和第二个比较得到结果1，再拿结果一和第三个比较得到结果二，再拿结果二和第四个比较。。这样依次迭代
### 15. 3Sum
好题，有几个地方需要注意：<br>
1.外层循环的去重需放在外层循环的最后，否则会把有效数据跳过,比如0,7,7<br>
2.内层循环分为nums[i] 和 nums[j]相等不等的两种情况，对于相等，直接放入res然后退出；对于不等，循环去重
### 16. 3Sum Closest
和上一题思路一致，不同的是在内层循环加了一个判断记录当前距离是否比已有的最小距离小
### 17. Letter Combinations of a Phone Number
简单题，迭代就行了
### 18. 4Sum
和15题思路一模一样，但是这次两个外层循环都需要在内层循环完成的最后循环去重
### 19. Remove Nth Node From End of List
快慢指针法
### 20. Valid Parentheses
易错，注意判断栈是否非空，非空才能S.pop()
### 21. Merge Two Sorted Lists
好题，建议三刷，利用递归或迭代都可以不new
```
递归写法：
        if (!l1 || l2 && l1->val > l2->val) swap(l1, l2);
        if (l1) l1->next = mergeTwoLists(l1->next, l2);
        return l1;
迭代写法：
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else 
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1? l1: l2;
        return dummy->next;
    }
```


### 22. Generate Parentheses
简单题，dfs6行解决，Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate Parentheses.
### 23. Merge k Sorted Lists
基于21题，归并排序即可。
```
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1? l1: l2;
        return dummy->next;
    }
    
    ListNode* Merge(vector<ListNode*>& lists, int st, int ed)
    {
        if (st == ed) return lists[st];
        if (ed == st + 1) return merge(lists[st], lists[ed]);
        ListNode* p1 = Merge(lists, st, (st+ed)/2);
        ListNode* p2 = Merge(lists, (st+ed)/2+1, ed);
        return merge(p1, p2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) return NULL;
        return Merge(lists, 0, len-1);
    }
```
### 24. Swap Nodes in Pairs
简单题，可以用迭代也可以用递归
### 25. Reverse Nodes in k-Group（建议4刷）
好题，可以用递归写法，难点是每次递归要把下一组的第一个节点找出来
```
        ListNode* tail = head;
        for (int i = 0; i < k; i++)
        {
            if (!tail) return head;
            tail = tail->next;
        }
        ListNode* res = reverse(head, tail);//找到下次递归时使用的第一个节点。
        head->next = reverseKGroup(tail, k);
        return res;
```
迭代：
```
        if (k == 1 || head == NULL) return head;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        dummy->next = head;
        ListNode* cur = head;
        int i = 0;
        while (cur)
        {
            i = 0;
            while (i < k && cur) //难点1 
            {
                cur = cur->next;
                i++;
            }
            if (i < k)  // 难点2
            {
                tail->next = head;
                break;
            }
            tail->next = reverse(head, cur);
            tail = head;
            head = cur;
        }
        return dummy->next;
```
### 26. Remove Duplicates from Sorted Array
好题，三行解决，
```
    int removeDuplicates(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 1; i < n; i++) nums[i] == nums[i-1] ? count++ : nums[i-count] = nums[i];
        return n - count;
    }
```
### 27. Remove Element
和上一题思路一模一样
### 28. Implement strStr()
好题，模板要背熟
### 29. Divide Two Integers
好题，这题的坑点有如下：<br>
1.边界条件的处理，将a = INT_MIN,b=-1单独拿出来处理<br>
2. 1 << 31 == INT_MIN(常数默认类型是INT)<br>
(long long)1 << 31 == INT_MAX + 1;
### 30.Substring with Concatenation of All Words
这题还是一格格的往后试吧。。
```
....
for (int i = 0; i < len; i++)
{
    unordered_map<string, int> m = m0;
    int j = 0;
    for (j = 0; j < wlen; j++)
    {
        string tmp = s.substr(i+j*wlen, wsize);
        if (m.find(tmp) != m.end())
        {
            m[tmp]--;
            if (m[tmp] < 0) break;
        }
        else break;
    }
    if (j == wlen) res.push_back(i);
}
return res;
```
### 31.next permutation
好题建议三刷，算法可以概括为：最后的守序者<br>
与大于守序者的最后者互换，守序者后反转
即
```
1.找到所有满足nums[k]<nums[k+1]的情形中，使k最大的那个
2.再找到所有满足nums[l]>nums[k]中,使l最大的那个
3.交换nums[k],nums[l]
4.对nums[k]之后的元素(不包括nums[k])进行反转，即可得到结果
```
### 32. Longest Valid Parentheses
好题三刷，这题的思想很简单，当一个右括号s[i]匹配时，<br>
以这个右括号结尾的长度一定是右括号索引-左括号索引+1+（左括号前一位如果是右括号，右括号的长度）
### 33. Search in Rotated Sorted Array
好题三刷，有三种思路：<br>
思路1.先判断nums[mid]在左边还是右边，再判断target在nums[mid]左边还是右边<br>
思路2.如果target和nums[mid]不在同一边，判断nums[mid]在左边还是在右边，<br>
如果在nums[mid ]左边，nums[mid] = INT_MIN,在右边nums[mid] = INT_MAX;<br>
思路3.先用while (st < ed)找出最小元素，根据最小元素确定target在左边还是在右边。<br>
### 34. Find First and Last Position of Element in Sorted Array
好题三刷，这题= 找到>=target的第一个数 + <= target的最后一个数
### 35. Search Insert Position
找到>=target的第一个数的下标位置
### 36. Valid Sudoku
利用数组存储，遍历一次就够了<br>
注意：
```
(i/3)*3 != i
```
### 38. Count and Say
题目看懂了就不难了
### 39. Combination Sum
好题建议三刷，裸dfs题
用动态规划也能做vector<vector<vector<int>>> (不过用dp的复杂度貌似比dfs高?)
### 40. Combination Sum II
好题三刷，建议裸dfs<br>
难点在于,为什么直接每次dfs之后跳过相同的却还能得到正常结果？<br>
因为当前数字的dfs已经计算出所有结果了<br>
比如
```
1,1,1,2,3
5
```
第一个1得到如下的
```
1,1,1,2,3
1,1,3
```
和3SUM,4SUM一样，都要先计算后去重，因为计算结果本身包含他自己
### 41. First Missing Positive（不会）
好题三刷这题的要义在于，把当前位置的数放到属于它的位置上，直到变不了
### 42. Trapping Rain Water（不会的）
好题三刷，这道题叫做<br>
```
三块板才能形成一个水池    
```
### 43. Multiply Strings(不会) 
这题的坑在于
```
int index1 = i + j + 1;
int index0 = i + j;
int sum = tmp1*tmp2 + res[index1] - '0';
res[index0] += sum/10;// index0上可能有别的数据，比如65*35,65*5得到325,5*3得到15，5+2得到7,1要加到3上
res[index1] = sum%10 + '0'; // index1上的数据已经算出来了
```
### 44. Wildcard Matching（不会）
和第十题思路类似，不过比第十题思路简单
### 45. Jump Game II
这题采用搜刮法，例如
```
[2,3,1,1,4]
0轮搜刮后的增加的下标：0
1轮搜刮后的增加的下标：1, 2
2轮搜刮后的增加的下标：3,4
```
所以答案是2
### 46. Permutations(建议换一种方法三刷)
建议用NextPermutation + do while
用dfs也可以做
### 47. Permutations II（易错）
建议用do while
和3SUM,4SUM,conbinationsII一样，在第一个数字完成dfs后后移
### 48. Rotate Image
两个难点，但是画张图就行了
![image](https://github.com/qianyuqiao/acm/blob/master/img/yuandixuanzhuan.jpg)
<br>
1.j最大是len-1-i
2.看图说四个点的坐标
### 49 Group Anagrams
查找排序后的字符串有没有记录
### 50. Pow(x, n)(不会)
好题三刷
1.对INT_MIN要单独处理
```
unsigned int nn;
if (n == INT_MIN) nn = (unsigned int)INT_MAX + 1;
else nn = (n >= 0 ? n : -n);
```
2.公式要背牢
```
double Pow(double x, unsigned int n)
{
    if (n == 0) return 1.0;
    if (n == 1) return x;
    double r = Pow(x, n>>1);
    r *= r;
    if (n & 0x01) r *= x;
    return r;
}
```
### 51. N-Queens(不会）
难点在于判断条件
### 52. N-QueensII
和41题一样
### 53.最大连续子序列（易错）
注意卡丹算法的坑

### 54. Spiral Matrix
```
模拟问题，注意特殊情况
1.只有一行
2.只有一列
我看到的leetcode上最好的思路：
设置rowst, rowed, colst, coled来限定当前区域，
每次在送数的时候一定要确保rowst <= rowed 且colst <= coled;
```
### 55.jump game
思路：从后向前推，当发现nums[i] + i >= goal的时候，这时候只要能保证能跳到goal位置就行。
```
   int goal = len - 1;
   for (int i = len - 1; i >= 0; i--)
   {
        if (nums[i]+i >= goal)
            goal = i;
    }
    return goal == 0;
```
### 56. Merge Intervals（好题三刷）
```
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int len = intervals.size();
        if (len == 0) return res;
        res.push_back(intervals[0]);
        int vlen = 1;
        int tmp;
        for (int i = 1; i < len; i++)
        {
            vlen = res.size();
            tmp = res[vlen-1][1];
            if (intervals[i][0] > tmp)
                res.push_back(intervals[i]);
            else
                res[vlen-1][1] = max(tmp, intervals[i][1]);
        }
        return res;
```
难点：
1.sort的使用<br>
2.每次是和res的最后一个元素比较

### 57. Insert Interval
```
1.用二分查找找出插入位置
2.插入
3.用56题的思路比较
```

### 58. Length of Last Word
简单题，直接秒杀

### 59. Spiral Matrix II
和54题思路一样

### 60. Permutation Sequence
直接背公式

### 61. Rotate List （看看思路）
```
1.遍历，把节点序号和对应的指针存起来，计算总长度
2.让最后一个指针指向head,确定下面两个问题：
哪一指针后面是空(len-k-1)
返回哪一个指针(len-k)
```

### 62	Unique Paths    
二维dp秒解
注意声明为
```
unsigned int dp[][] = {};
```

### 63	Unique PathsII
二维dp秒解
注意声明为
```
unsigned int dp[][] = {};
```
### 64. Minimum Path Sum
二维dp秒解

### 66. Plus One
简单题，秒杀

### 67. Add Binary
简单题，秒杀

### 69. Sqrt(x)
```
二分查找，简单，注意
unsigned long long mid,这样做乘法的话结果是unsigned long long
```

### 70. Climbing Stairs
简单dp

### 71. Simplify Path
分割所有的"/"，剩下的用栈随便做
```
        stringstream ss(path);
        vector<string> stk;
        while (getline(ss, tmp, '/'))
        {
            if (tmp == "" || tmp == ".") continue;
            if (tmp == ".." && !stk.empty()) stk.pop_back();
            if (tmp != "..") stk.push_back(tmp);
        }
        for (auto s: stk) res += "/" + s;
        return stk.empty() ? "/": res;
```
### 72. Edit Distance（学姐问过我的题）
```
思路：其实只有两种操作：
1.相同长度，替换
2.不同长度，短的要增加
递推公式：
s1[i] == s2[j]: 
dp[i][j] = dp[i-1][j-1];
s1[i] != s2[j]:
dp[i][j] = min(dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1);
难点：
i = 0的一列的初始化（有相同的，1+i-1，否则1+i)
j = 0 的一行的初始化（有相同的，1+j-1，否则1+j)
```

### 73. Set Matrix Zeroes（三刷）
1.如果有感染者，先感染海关<br>
如果感染者就在海关，标记海关
```
1 1 1
1 0 1
1 1 1
```
变成
```
1 0 1
0 0 1
1 1 1
```
2.遍历没一个数，如果海关没感染，他也被感染
```
1 0 1
0 0 0
1 0 1
```
### 74. Search a 2D Matrix
成功的秘诀在于取第一行最后一个数

### 75. sort colors
可以直接用数组记录02个数然后自己创造，也可以用左右指针指向02的位置，<br>
搜到0和左指针互换，左++ i++***i可以加因为左指针指向的不是0就是1***<br>
搜到1和右指针，右--,***i不能加，因为可能换了个0或者2过来***
如下
```
        while (i <= r)
        {
            if (nums[i] == 0)
            {
                swap(nums[l], nums[i]);
                l++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[r], nums[i]);
                r--;
                i--; // 这个地方是易错点，因为可能直接换了个2或者0过来
            }
            i++;
        }
```
### 76. Minimum Window Substring（三刷，注意res == MAX_INT的时候，res 要变成0）
```
如果面试的时候要写，那么每次循环时都手动计算是不是map是不是满了
```

### 77. Combinations（三刷时建议用迭代）
dfs
迭代

### 78. Subsets（好题三刷）
```
位操作：
i = 0,...,2^n-1
0000 
0001 第一位
0010 第二位
0011 第一位和第二位
```

### 79. Word Search（好题三刷，易错：）
```
思路：贪吃蛇，吃完后比较
```
### 80. Remove Duplicates from Sorted Array II
和26题思路一模一样

## 82. Remove Duplicates from Sorted List 
简单题，建议用迭代和递归各做一遍。

### 83. Remove Duplicates from Sorted List
简单题

### 86. Partition List
注意，这题的tail2会成环！！！
```
要把tail2->next = NULL;
```
### 88. Merge Sorted Array
秒杀题，二分查找+从后覆盖<br>
或者先把nums1的前面移位到后面，再用双指针插入

### 90. Subsets II（注意这题是乱序）
好题三刷，注意这题是乱序

### 958. Check Completeness of a Binary Tree(建议三刷)
如果是完全二叉树，到空节点就停止的层序遍历，空节点后不应该还有非空节点。

