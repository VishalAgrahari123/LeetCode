//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int i, int j, vector<vector<int>>&vis, vector<vector<int>>&mat, int n, int m)
    {
        vis[i][j] = 1;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for(int k=0; k<4; k++)
        {
            int r = i+dx[k];
            int c = j+dy[k];
            if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and mat[r][c] == 1)
            {
                dfs(r, c, vis, mat, n, m);
            }
        }
    }
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        // Code here

        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if((i==0 or i==n-1 or j==0 or j==m-1) and mat[i][j] == 1)
                {
                    dfs(i, j, vis, mat, n, m);
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and mat[i][j] == 1)
                {
                    cnt++;
                    dfs(i, j, vis, mat, n, m);
                }
            }
        }
        
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends