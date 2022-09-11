class Solution {
public:
    
    void floodFillnew(vector<vector<int>>& image, int sr, int sc, int color, int target) {
        // cout<<"sr:"<<sr<<" sc:"<<sc<<endl;
    
        if(sr < 0)
            return;
        if( sc < 0) 
            return;
        if(sr > (image.size()-1))
            return;
        if(sc > (image[0].size()-1))
            return;
        if(image[sr][sc] != target)
            return;
        image[sr][sc] = color;
        // check top
        floodFillnew(image, sr-1, sc, color, target);
        // check left
        floodFillnew(image, sr, sc-1, color, target);
        // check right
        floodFillnew(image, sr, sc+1, color, target);
        // check bottom
        floodFillnew(image, sr+1, sc, color, target);
        // fill the current element;
        
        return;
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        floodFillnew(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};