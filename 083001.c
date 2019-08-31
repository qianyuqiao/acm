#include<iostream>
#include<string>
#include<vector>
using namespace std;
	vector<vector<int>> helper(vector<vector<int>> & matrix) {
	int row = matrix.size();
	int column = matrix[0].size();
	vector<vector<int>> dp(row-1, vector<int>(column-1, 0));
	for (int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < column-1; j++)
		{
			if (matrix[i][j]  && matrix[i+1][j+1] && matrix[i+1][j] && matrix[i][j+1])
			 dp[i][j] = 1; 
		}
	}
		return dp;
	}

	void dfs(vector<vector<int>> & dp0, vector<vector<bool>>& visited, int indexi, int indexj, int& res, int row, int column, int tmp)
	{
		res = max(res, tmp);
			
		for (int j = indexj; j < column; j++) 
		{
			if (dp0[indexi][j])
			{
				if (indexi > 0 && visited[indexi-1][j]) continue;
				if (j > 0 && visited[indexi][j-1]) continue;
				if (indexi > 0 && j > 0 && visited[indexi-1][j-1]) continue;
				visited[indexi][j] = true;
				dfs(dp0, visited, indexi, j+1, res, row, column, tmp+1);
				visited[indexi][j]  = false;
			}
		}
			
		for (int i = indexi+1; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (dp0[i][j])
				{
					if (i > 0 && visited[i-1][j]) continue;
					if (j > 0 && visited[i][j-1]) continue;
					if (i > 0 && j > 0 && visited[i-1][j-1]) continue;
					visited[i][j] = true;
					dfs(dp0, visited, i, j+1, res, row, column, tmp+1);
					visited[i][j]  = false;
				}
			}
		}
		
		return;
	}

int main()
{
	int n, m;
	while (cin >> n)
	{
		cin >> m;
		if (n < 2 || m < 2) return 0;
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			cin >> dp[i][j];
		}
		
		vector<vector<int>> dp1 = helper(dp);
		vector<vector<bool>> visited(n-1, vector<bool>(m-1, false));
				
		int res = 0;
		dfs(dp1, visited, 0, 0, res, n-1, m-1, 0);

		cout << res << endl;
	}
	return 0;
}
