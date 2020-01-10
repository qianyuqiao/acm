### 2. Add Two Numbers
看了一下别人的答案，while 和 new ListNode()都是OK的啦，调试和给分的编译器不一样，给分的编译器认为ListNode* head 后面没有 = NULL的话是个随机非空的.
递归的话只要7行。
### 3. Longest Substring Without Repeating Characters
二刷的时候一看就知道是滑动窗口，注意字符串可能为空
### 4. Median of Two Sorted Arrays
两种思路，1.摁葫芦法，<br>
要找第k个数(k从1开始数)，如果A[i] > B[j]且i+1+j+1 = k那么边界一定在索引j的后面，通过不断试探来确定边界
![这里随便写文字](https://github.com/qianyuqiao/scripts/blob/master/median.jpg)
