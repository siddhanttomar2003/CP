class Solution {
public:
      void flood(vector<vector<int>>& image,int sr,int sc,int &m,int &n,int &oldColor,int &newColor){
          if(sr<0||sc<0||sr==m||sc==n||image[sr][sc]!=oldColor)return;
          image[sr][sc]=newColor;
          flood(image,sr+1,sc,m,n,oldColor,newColor);
          flood(image,sr-1,sc,m,n,oldColor,newColor);
          flood(image,sr,sc+1,m,n,oldColor,newColor);
          flood(image,sr,sc-1,m,n,oldColor,newColor);

      }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int oldColor=image[sr][sc];
        int newColor=color;
        if(oldColor==newColor)return image;
        flood(image,sr,sc,m,n,oldColor,newColor);
        return image;

    }
};