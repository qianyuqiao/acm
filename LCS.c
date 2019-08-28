#include<iostream>
#include<string>
#include<vector>
using namespace std;
int findLength(int n1, int n2, int a[], int b[]) {
    int dp[n1+1][n2+1] = {};
    for(int i = 1; i <= n1; i++)
        for(int j = 1; j <= n2; j++)
        {
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);    
        }
    return dp[n1][n2];
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
