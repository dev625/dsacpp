#include <bits/stdc++.h>
using namespace std;

void DFS(int i, int j, int n, int m, vector<vector<char>> grid, vector<vector<bool>> &V)
{
    if ((i >= 0 && i < n) && (j >= 0 && j < m) && grid[i][j] == '1' && V[i][j] == false)
    {
        V[i][j] = true;
        DFS(i, j + 1, n, m, grid, V);
        DFS(i, j - 1, n, m, grid, V);
        DFS(i + 1, j, n, m, grid, V);
        DFS(i - 1, j, n, m, grid, V);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int result{0};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> V(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && V[i][j] == false)
            {
                result++;
                DFS(i, j, n, m, grid, V);
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> V;
    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        for (int j = 0; j < m; j++)
        {
            char ele;
            cin >> ele;
            temp.push_back(ele);
        }
        V.push_back(temp);
    }
    cout << numIslands(V);
}