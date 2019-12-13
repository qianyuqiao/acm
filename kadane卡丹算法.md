连续子序列的最大和。
缘起：设dp[i]为以nums[i]结尾的连续子序列的最大和，则
```
if (dp[i-1] > 0) dp[i] = dp[i-1] + nums[i]; 
else dp[i] = nums[i];
```
代码
```
int getMaxSumSubArray(vector<int>& nums)
{
    int sum = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (sum >= 0) sum += nums[i];
        else sum = nums[i];
        res = max(sum, res);
    }
    return res;
}
```
关于连续子序列的最小和，可以这样想，如果一个数组的所有连续子序列和的范围为(a, b)这一段，那么他的相反数数组构成的连续子序列的和必定为(-b, -a)
<br>
所以，相反数数组的最大值的相反数即为最小和
```
int getMinSumSubArray(vector<int>& nums)
{
    vector<int> nums1;
    for (int num: nums)
        nums1.push_back(-1*num);
    int res1 = getMaxSumArray(nums);
    return -res1;
}
```
获取循环数列的连续子序列的最大和
```
int getMaxSumSubArray2(vector<int>& nums)
{
    int maxsum = A[0];
    int maxcur = A[0];
    int minsum = A[0];
    int mincur = A[0];
    int total = A[0];
    int tmp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        tmp = A[i];
        maxcur = max(maxcur+tmp, tmp);
        maxsum = max(maxcur, maxsum);
        mincur = min(mincur+tmp, tmp);
        minsum = min(maxmin, mincur);
        total += tmp;
    }
    if (maxsum < 0)
        returm maxsum;
    else return max(maxsum, total-minsum);
}
```
获取循环数列的连续子序列的最小和
```
int getMinSumSubArray2(vector<int>& nums)
{
    int maxsum = A[0];
    int maxcur = A[0];
    int minsum = A[0];
    int mincur = A[0];
    int total = A[0];
    int tmp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        tmp = A[i];
        maxcur = max(maxcur+tmp, tmp);
        maxsum = max(maxcur, maxsum);
        mincur = min(mincur+tmp, tmp);
        minsum = min(maxmin, mincur);
        total += tmp;
    }
    if (minsum > 0)
        returm minsum;
    else return min(minsum, total-maxsum);
}
```
