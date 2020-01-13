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
else if (p[j-1] == '*') 
{
    dp[i][j] = dp[i][j-2] || dp[i][j-1];//任何人都能匹配0次或1次
    if (p[j-2] == '.' || p[j-2] == s[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j]; // 匹配多次
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
1.外层循环的去重需放在外层循环的最后，否则会把有效数据跳过<br>
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
好题，建议三刷，利用递归可以不new
### 22. Generate Parentheses
简单题，dfs6行解决，Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate Parentheses.
