/* ------------------------------------------------------------------|
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
------------------------------------------------------------------*/

/*	动态规划算法
*
*	执行用时：16 ms, 在所有 C++ 提交中击败了14.22%的用户
*	内存消耗：9.8 MB, 在所有 C++ 提交中击败了10.90%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <list>  

using namespace std;

int minPathSum(vector<vector<int>>& grid) 
{
	//vector<vector<int> > ans = grid;								实际工程中不允许原地修改，所以复制一份
	int m = grid.size() - 1;
	int n = grid[0].size() - 1;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			else if (i == 0)
			{
				grid[i][j] += grid[i][j - 1];
			}
			else if (j == 0)
			{
				grid[i][j] += grid[i - 1][j];
			}
			else
			{
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}

		}
	}
	return grid[m][n];
	/*vector<vector<int> >res;

	res[0][0] = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (i == 0)
			{
				res[i][j] = grid[i][]
			}
		}
	}*/
	
}

int main()
{
	vector<vector<int> >grid = { {1,3,1},{1,5,1} ,{4,2,1} };

	int distance = minPathSum(grid);
	cout << distance << endl;
}