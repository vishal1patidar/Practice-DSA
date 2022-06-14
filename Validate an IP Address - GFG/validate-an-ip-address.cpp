// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            int cell=0 ;
            string num="" ;
            for(int i=0; i<s.length() ; i++)
            {
                //Check if the cell contain any alphabet
                if(s[i]>='A' and s[i]<='Z') return false ;
                if(s[i]>='a' and s[i]<='z') return false ;
                    if(s[i]!='.')
                        num+=s[i] ;
                    else
                    {
                        //Check if cells have any value
                        if(i+1<s.length() and s[i+1]=='.') return false ;
                        //Check if the cells have at most 3 digits
                        if(num.length()>3) return false ;
                        //Check if 0 is followed by any digit
                        if(num.length()>1 and num[0]=='0') return false ;
                        //Check if the number lies within the range
                        int temp=stoi(num) ;
                        if(temp<0 or temp>255) return false ;
                        cell++ ;
                        //Check if the cell size is not greater than 4
                        if(cell>3) return false ;
                        num="" ;
                    }
            }
            
            if(num.length()>1 and num[0]=='0') return false ;
            
            //Check if the cell size is equal to 4
            return cell==3 ? true : false ;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends