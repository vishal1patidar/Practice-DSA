class Solution {
public:
    int guessNumber(int n) {
        int start = 1 , end = n;
        while(start <= end){
            int mid = start + (end - start) / 2;
            int ans = guess(mid);
            if(ans == 0)
                return mid;
            else if( ans == 1)
                start = mid + 1;
            else 
                end = mid ;
        }
        return 0;
    }
};