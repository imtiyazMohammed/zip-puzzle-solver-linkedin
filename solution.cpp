#include <bits/stdc++.h>
using namespace std;

string result = "", answer= "";
bool found = false;

bool checkThePath(vector<vector<int>>& grid, int& m, int& n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] != -1) return false;
        }
    }
    return true;
}

void dfs(vector<vector<int>>& grid, int& m, int& n, int i, int j, int k, int currK) {
    if(found) return;
    if(i < 0 or i >= m or j < 0 or j >= n) return;
    int cell = grid[i][j];
    if(cell == -1 or cell > currK) return;
    grid[i][j] = -1;
    if(cell == currK) currK++;
    if(currK == k+1 and checkThePath(grid, m, n)) {
        answer = result;
        found = true;
        grid[i][j] = cell;
        return;
    }
    static const int di[4]   = { 1, -1,  0,  0 };
    static const int dj[4]   = { 0,  0,  1, -1 };
    static const char dm[4]  = { 'D','U','R','L' };

    for (int d = 0; d < 4; ++d) {
        int ni = i + di[d], nj = j + dj[d];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

        result.push_back(dm[d]);
        dfs(grid, m, n, ni, nj, k, currK);
        if (found) {
            grid[i][j] = cell;
            return;
        }
        result.pop_back();
    }
    grid[i][j] = cell;
}

void zipSolver(vector<vector<int>>& grid, int& m, int& n, int startRow, int startCol, int k) {
    result.clear();
    answer.clear();
    found = false;
    cout<<"Given grid: \n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    dfs(grid, m, n, startRow, startCol, k, 2);
    if(found) {
        cout<<answer<<endl;
    }
    else cout<<"Not valid";
}

int main(){
    int tc;
    cin>>tc;
    int m,n,x,k=0;
    int startRow, startCol;
    while(tc--) {
        cin>>m>>n;
        k = 0;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin>>x;
                if(x == 1) {
                    startRow = i;
                    startCol = j;
                }
                grid[i][j] = x;
                k = max(k,x);
            }
        }
        zipSolver(grid, m, n, startRow, startCol,k);
        
    }
}