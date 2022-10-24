// // BIT MANIPULATION SOLUTION
// class Solution {
// public:
//     int maxLength(vector<string>& arr) {
//         int maxlength=0;
//         int n=arr.size();
//         int nos=pow(2,n)-1;
//         for(int num=0;num<=nos;num++)
//         {
//             vector<string> temp;
//             for(int i=0;i<n;i++)
//             {
//                 int bit=(num&(1<<i));
//                 if(bit) temp.push_back(arr[i]);
//             }
//             string s1="";
//             for(int i=0;i<temp.size();i++)
//             {
//                 s1+=temp[i];
//             }
//             int freq[26]={0};
//             for(int i=0;i<s1.size();i++)
//             {
//                 freq[s1[i]-'a']++;
//             }
//             int cnt=0;
//             for(int i=0;i<26;i++)
//             {
//                 if(freq[i]==1)
//                 {
//                     cnt++;
//                 }
//                 else if(freq[i]>1)
//                 {
//                     cnt=0;
//                     break;
//                 }
//             }
//             maxlength=max(maxlength,cnt);            
//         }
//         return maxlength;
//     }
// };
//BACKTRACKING SOLUTION
class Solution {
public:
    void fun(int idx,vector<string>& arr,vector<string>& temp,int& maxlength)
    {
        if(idx==arr.size())
        {
            string s1="";
            for(int i=0;i<temp.size();i++)
            {
                s1+=temp[i];
            }
            int freq[26]={0};
            for(int i=0;i<s1.size();i++)
            {
                freq[s1[i]-'a']++;
            }
            int cnt=0;
            for(int i=0;i<26;i++)
            {
                if(freq[i]==1)
                {
                    cnt++;
                }
                else if(freq[i]>1)
                {
                    cnt=0;
                    return;
                }
            }
            maxlength=max(maxlength,cnt);
            return;
        }
        temp.push_back(arr[idx]);
        fun(idx+1,arr,temp,maxlength);
        temp.pop_back();
        fun(idx+1,arr,temp,maxlength);
    }
    int maxLength(vector<string>& arr) {
        vector<string> temp;
        int maxlength=0;
        fun(0,arr,temp,maxlength);
        return maxlength;
    }
};