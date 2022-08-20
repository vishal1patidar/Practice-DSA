class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0){
            return 1;
        }
        if(n<0){
            x= 1/x;
            n= abs(n);
        }
        double ans= myPow(x,n/2);
        if(n%2 == 1){
            return ans*ans*x;
        }
        return ans*ans;
    }
};