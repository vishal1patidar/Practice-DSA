class Solution {
public:
    int reverse(int n){
    int result=0;
    while(n!=0){
        int digit= n%10;
        if((result>INT_MAX/10)||(result<INT_MIN/10)){
            return 0;
        }
        result=(result*10)+digit;
        n=n/10;
        
    }
        return result;
    
    }
};