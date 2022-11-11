class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& Hari, vector<int>& newInterval) {
        if(!Hari.size()){
            Hari.push_back(newInterval);
            return Hari;
        }
        int k=0, i;
        Hari.push_back(newInterval);  // Inreasing vector size by 1;
        int n=Hari.size();
        for(i=0; i<n; i++){  //Sort using swap
            if(Hari[i][0]>=newInterval[0]){
                swap(Hari[i],Hari[n-1]);
                break;
            }
        }
        for(int j=i+1; j<n; j++){  
            swap(Hari[j],Hari[n-1]);
        }
        
        auto it=Hari.begin();
        for(int j=1;j<n;j++)
            if(Hari[k][1]>=Hari[j][0]) Hari[k][1]=max(Hari[k][1],Hari[j][1]);  // merges interval
            else Hari[++k]=Hari[j], it++;

        Hari.erase(it+1,Hari.end());  // removes extra elements left  in array
        return Hari;
    }
};