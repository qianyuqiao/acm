# nums.size() >= 1;
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
