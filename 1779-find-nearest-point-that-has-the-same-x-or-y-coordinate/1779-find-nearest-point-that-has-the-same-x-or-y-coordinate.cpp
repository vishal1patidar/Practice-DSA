class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int pos=-1,minDist=100000;
      for(int i=0;i<size(points);i++){
          if(x== points[i][0] || y== points[i][1]){
              int dist = abs(x-points[i][0])+abs(y-points[i][1]);
              if( dist<minDist){
                  pos=i;
                  minDist=dist;
              }
          }
      }  
        return pos;
    }    
};