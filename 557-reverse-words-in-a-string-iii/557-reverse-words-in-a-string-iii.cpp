class Solution
{
    public:
        string reverseWords(string s)
        {
            int tmp = 0;  // With this variable we maintain start index of every word.
            int n = s.length();   
            for (int i = 0; i <= n; i++)
            {
                if (s[i] == ' ' || i == n)  //If there is space or we are at end of senetence.
                {
                    int start = tmp;
                    int end = i - 1;  //to find the last index of that word.
                    while (start < end)
                    {
                        swap(s[start], s[end]);
                        start++;
                        end--;
                    }

                    tmp = i + 1; //now from i+1 index , new word start.
                }
            }
            return s;
        }
};