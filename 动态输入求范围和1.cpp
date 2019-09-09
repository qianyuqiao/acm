#include<iostream>
#include<vector>
using namespace std;

vector<int> rangeSum(int numOfCustomer, int numOfQueries, int** queries)
{
	int nums = 0;
	int len = numOfQueries;
	int bak[numOfCustomer] = {};
	vector<int> res;
	for (int i = 0; i < len; i++)
	{
		if (queries[i][0] == 1) bak[queries[i][1]] += queries[i][2];
		else if (queries[i][0] == 2)
		{
			int tmp = 0;
			int st = queries[i][1];
			int ed = queries[i][2];
			for (int i = st; i <= ed; i++)
			{
				tmp += bak[i];
			}
			res.push_back(tmp);
		}
	}
	return res;
}
int main()
{
	int cus;
	int qur;
	while (cin >> cus)
	{
		cin >> qur;
		int** q;
		q = new int*[qur];
		for (int i = 0; i < qur; i++)
		{
			q[i] = new int[3];
		}
		for (int i = 0; i < qur; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> q[i][j];
			}
		}		
		vector<int> res = rangeSum(cus, qur, q);
		for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
