class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector <bool>& vis) {
        vis[node] = true;
        for (int i = 0; i < vis.size(); i++) {
            if (node != i && !vis[i] && isConnected[node][i])
                dfs(i, isConnected, vis);
        }
    }    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector <bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < vis.size(); i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, isConnected, vis);
            }
        }
        return cnt;
    }
};
