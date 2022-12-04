class Solution {
public:
    int strStr(string h, string n) {
    int i = 0;
    int size1 = h.size();
    while(i<size1){
        
        if(h[i] == n[0]){
            int j = i+1;
            int size2 = n.size();
            int k = 1;
            while(k<size2){
                if(h[j] == n[k]){
                    j++;
                    k++;
                }
                else{
                    break;
                }
            }
            if(k == size2){
                return i;
            }
            
        }
        i++;
    }
    return -1;
}
};