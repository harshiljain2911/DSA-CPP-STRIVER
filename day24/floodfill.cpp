class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col,
             int originalColor, int newColor) {

        // Boundary check
        if(row < 0 || row >= image.size())    return;
        if(col < 0 || col >= image[0].size()) return;

        // Only fill cells that have the original color
        if(image[row][col] != originalColor)  return;

        image[row][col] = newColor;           // Recolor this pixel

        // Recurse in all 4 directions
        dfs(image, row + 1, col, originalColor, newColor); // down
        dfs(image, row - 1, col, originalColor, newColor); // up
        dfs(image, row, col + 1, originalColor, newColor); // right
        dfs(image, row, col - 1, originalColor, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        // If already the same color, no work needed
        if(originalColor == color) return image;

        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};
