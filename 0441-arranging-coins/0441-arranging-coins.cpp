// Time Complexity - O(n)

class Solution {
public:
    int arrangeCoins(int n) {
        double count=0,ans=0,rem;
        for(int i=1;i<=n;i++){
            ans=ans+i;
            
            if(n<ans){
                break;
            }
            count++;
        }
        return count;
    }
};