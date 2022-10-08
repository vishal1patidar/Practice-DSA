class Solution {
public:
   bool increasingTriplet(vector<int>& arr) {
        
        int n=arr.size();
        int i;
        int small=INT_MAX,large=INT_MAX;
        //Hum yha pe do variable liye hai small and large jismei hum extreme large number daal diye
        for(int i=0;i<n;i++)
        {
            //ismei sb se small number save ho jayega 
            if(arr[i]<=small)
                small=arr[i];
            //ismei loop run k baad small se bda number save hoga
            else if(arr[i]<=large)
                large=arr[i];
            //And agar large se bda v koi number hoga toa ye true return kr dega
            else
                return true;
        }
        // or agar upper condition sb satisfy nhi karega toa false return kr dega
            return false;
       //if you like then please vote 
    }
};