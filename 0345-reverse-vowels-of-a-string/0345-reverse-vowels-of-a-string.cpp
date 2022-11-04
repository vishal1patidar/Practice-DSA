class Solution {
public:
    bool isVowel(char ch)
    {
        char currCh = tolower(ch); //lower all the characters to reduce checking for upppercase vowels
        if (currCh == 'a' || currCh == 'e' || currCh == 'i' || currCh == 'o' || currCh == 'u') return true;
        return false;
    }
    string reverseVowels(string s)
    {
        int n = s.size();
        int low = 0, high = n - 1;
        while(low < high)
        {
            bool isLowVowel = isVowel(s[low]);
            bool isHighVowel = isVowel(s[high]);
            if (isLowVowel && isHighVowel) //consider swapping only when both s[low] and s[high] are vowels
            {
                swap(s[low], s[high]);
                low++; high--; //move low to right, high to left as we have swapped them
            }
            else if (!isLowVowel) low++; //if s[low] is not a vowel keep traversing to right in search of a vowel
            else if (!isHighVowel) high--; //if s[high] is not a vowel keep traversing to left in search of vowel
        }
        return s;
        
    }
};