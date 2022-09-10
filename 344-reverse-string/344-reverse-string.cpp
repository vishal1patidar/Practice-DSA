class Solution {
public:
    void revers(vector<char>& str){
    
    int s = 0;
    int e = str.size()-1;
    
    while (s < e){
        swap(str[s++], str[e--]);
    }
}
void reverseString(vector<char>& s) {
    revers(s);
}
};