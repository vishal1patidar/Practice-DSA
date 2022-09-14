class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1 )return x;
        long low=1; // to keep track of lower limit
        
        long high=x/2; // to keep track of upper limit
        long count =0; // to store the nearest number if x is not a perfect square 
        while(low<=high){ 
            long mid=((high-low)/2)+low; // mid is the middel point of lower and higher limit
            if((long)x==mid*mid){  // if square of mid is equal to x than mid is the answer
                
                return (int)mid;
            }
            if((mid*mid)<(long)x){ // if square of mid is less than x than we will store mid in count variable and low will be equal to mid
                count=mid;
               low=mid+1;
            }
            else{ // else if square of mid is greater than mid that we will reduce high to mid
                high=mid-1;
            }
        }
// if there is no perfect square for given x than loop will be exited and count will contain the nearest no to the suare root of x
        return (int)count;
    }
};