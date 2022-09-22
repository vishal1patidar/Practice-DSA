class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(!st.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> vis;
        vis.insert(beginWord);
        int level = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string temp = q.front();
                q.pop();
                if(temp==endWord) return level;
                
                string curword;
                for(int i=0;i<temp.size();i++) {
                    curword = temp;
                    for(char ch='a';ch<='z';ch++) {
                        curword[i] = ch;
                        if(st.count(curword) and !vis.count(curword)) {
                            vis.insert(curword);
                            q.push(curword);
                        }
                    }
                }
            }
            level++;
        }
       return 0; 
    }
};