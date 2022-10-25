
class Solution {
public:
	// vector<int> dx = {-1,1,0,0};
	// vector<int> dy = {0,0,-1,1};
	int vis[501][501];
	void dfs(vector<vector<int>>&grid, string &s, int i, int j,int ti , int tj) {
		if((i<0 or i >=grid.size()) or (j<0 or j>=grid[0].size()))
		    return ;
		if(vis[i][j] == 1 or grid[i][j] == 0)
		    return;
		 vis[i][j] = 1;
		 vector<pair<int,int>> vb = {{0,-1},{0,1},{1,0},{-1,0}};
		 s+=to_string(i-ti)+to_string(j-tj);
		 for(auto r:vb){
		     int x = r.first+i,y = r.second+j;
		     dfs(grid,s,x,y,ti,tj);
		 }
		
		
	}
	int countDistinctIslands(vector<vector<int>>& grid) {
		
		int n = grid.size();
		int m = grid[0].size();
// 		vector<vector<int>> vis(n, vector<int>(m));
        memset(vis,0,sizeof(vis));
		set<string> st;
// 		debug(vis)

// 		string s = "";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] or grid[i][j] == 0 ) {
					continue;
				}
				string s;
				// 	s += 'A';
					dfs(grid, s, i, j, i,j);
				    st.insert(s);
			}
		}
// 		debug(mb)
		return st.size();
	}
};
