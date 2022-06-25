class Solution {
public:
    string reverseWords(string s) {
    //take two pointer i and j start with 0
    int j = 0;
    int i = 0;
    int n = s.length();
    // Run a Loop till the size of the string
    while(j <= n){
        //condition checking if there is space or not 
        //after that if you find the space we simply reverse the string till j 
        // and set the i = j + 1 and then increase j++ 
        if(s[j] == ' ' || j == n){
            reverse(s.begin() + i , s.begin() + j);
            i = j+1;
            j++;
            
        }
        //if there no space present we simply increase j++ , 
        else{
            j++;
        }
    }
    return s;
}
};