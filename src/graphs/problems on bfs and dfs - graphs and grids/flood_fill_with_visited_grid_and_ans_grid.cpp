class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        // super easy question, same as the rotten oranges
        // here, integer element of the image represents the color, only two
        // colors are there in the whole question, the one in the initial image
        // and the one given as the color

        int initialColor = image[sr][sc];
        // we have to visit only the cells with initial color and color them
        // with new color

        // grid question - bfs on grid / dfs on grid
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        // copy it
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = image[i][j];
            }
        }
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int startRow = sr, startCol = sc;
        // just apply bfs or dfs on the image

        // bfs
        queue<pair<int, int>> q;

        vis[sr][sc] = 1;
        ans[sr][sc] = color;
        q.push({sr, sc});

        // up right down left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    !vis[nrow][ncol] && image[nrow][ncol] == initialColor) {
                    // not yet visited
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    ans[nrow][ncol] = color;
                }
            }
        }
        return ans;
    }
};