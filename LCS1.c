#include<iostream>
#include<string>
#include<vector>
using namespace std;
int findLength(int n1, int n2, int a[], int b[]) {
    int prev[n2+1] = {};
    int dp[n2+1] = {};
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(a[i - 1] == b[j - 1])
                dp[j] = prev[j - 1] + 1;
            else dp[j] = max(dp[j - 1], prev[j]); 
            prev[j-1] = dp[j-1];
        }
        prev[n2] = dp[n2];
    }
    return dp[n2];
}

int main()
{
    int n1, n2;
    while (cin >> n1 >> n2)
    {
        int A[n1] = {};
        int B[n2] = {};
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i]; 
        int res = findLength(n1, n2, A, B);
        cout << res << endl;
    }
    return 0;
}
