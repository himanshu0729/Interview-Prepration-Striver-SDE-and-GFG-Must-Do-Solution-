    void fillColor(int sr, int sc, vector<vector<int>>& image, int newColor, int oldColor){
        
        
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != oldColor)
            return;
        
        image[sr][sc] = newColor;
        
        fillColor(sr - 1, sc, image, newColor, oldColor);
        fillColor(sr, sc + 1, image, newColor, oldColor);
        fillColor(sr + 1, sc, image, newColor, oldColor);
        fillColor(sr, sc-1, image, newColor, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] == newColor)
            return image;
        
        fillColor(sr, sc, image, newColor, image[sr][sc]);
        return image;
    }
