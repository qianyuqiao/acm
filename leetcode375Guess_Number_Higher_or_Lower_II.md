
首先，这题是什么意思呢？给一列数1,2,3,4,5,9,7,8,....,n，现在让你准备一笔钱，每次猜错了就会给钱，问你应该最少准备多少钱才能保证猜到那个数

比如说 1,2,3,4,一种最优解是准备1+3元。先猜1，不对再猜3，如果比3大就是4，比3小就是2.所以你应该最少准备4元。

那么对于1,2,3,4,5,6,7这种比较复杂的情况怎么办呢？这个时候有一个很明显的结论是这样的，要准备的钱必定是下面几种情况中最小的
```
1元 + 猜2~7需要的钱
2元 + max(猜1需要的钱, 猜3~7需要的钱)
3元 + max(猜1~2需要的钱, 猜4~7需要的钱)
4元 + max(猜1~3需要的钱, 猜5~7需要的钱)
5元 + max(猜1~4需要的钱, 猜6~7需要的钱)
6元 + max(猜1~5需要的钱, 猜7需要的钱)
7元 + max(猜1~6需要的钱)
```
为什么要有max呢?比如说我先准备4元来猜4，如果比4元大，那么还准备需要猜5~7的钱；如果比4元小，那么还需要准备猜1~3的钱。所以只要准备的钱都够这两者即可。

AC代码
```
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][2] = i;
        }
        for (int l = 3; l <= n; l++)
        {
            for (int i = 1; i+l-1 <= n; i++)
            {
                for (int j = 0; j <= l-1; j++)
                {
                    if (j == 0) dp[i][l] = min(i+dp[i+1][l-1], dp[i][l]);
                    else if (j == l-1) dp[i][l] = min(i+l-1+dp[i][l-1], dp[i][l]);
                    else {
                        int res = max(dp[i][j], dp[i+j+1][l-j-1]);
                        dp[i][l] = min(res + i+j, dp[i][l]);
                    } 
                        
                }
            }
        }
        return dp[1][n];
    }
};
```