class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        // i can also just return the image itself after making changes to it

        // intuition -
        // color the (sr, sc) with the new color, i can simply avoid going back
        // to the same cell or node if the color doesn't match the intitalColor
        // and at the same time, avoid going to cells which are not same as the
        // initialColor

        int initialColor = image[sr][sc];

        // one edge case as if the (sr, sc) is itself the color, that is (if
        // initialColor = color) then we will fall into the infinite loop of
        // going back to the same nodes again and again
        if (initialColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        // up right down left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // visit neighbours
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    image[nrow][ncol] == initialColor) {
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};