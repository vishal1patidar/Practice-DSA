class Solution {
public:
    
    int rec(int num, int arr[])
    {
        if(arr[num])
            return arr[num];
        return (arr[num]=rec(num-1,arr)+rec(num-2,arr));
    }
    int climbStairs(int n) {
        int arr[46]={0};
        arr[0]=arr[1]=1;
        int num=rec(n,arr);
        
        return num;
    }
};