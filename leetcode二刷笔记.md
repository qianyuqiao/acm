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
好题，当p[j-1] == '*'时候，
```
else if (p[j-1] == '*') 
{
    dp[i][j] = dp[i][j-2] || dp[i][j-1];//任何人都能匹配0次或1次
    if (p[j-2] == '.' || p[j-2] == s[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j]; // 匹配星号
}
```
