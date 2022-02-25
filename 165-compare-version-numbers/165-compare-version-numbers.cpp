class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i = 0, j= 0, n1 = version1.length(), n2 = version2.length(), num1 = 0, num2 = 0;
        
        while(i < n1 || j < n2)
        {
            while(i < n1 && version1[i] != '.')
            {
                // converting version1[i] to int for comparison
                num1 = num1*10 + (version1[i] - '0');
                ++i;
            }
            while(j < n2 && version2[j] != '.')
            {
                // converting version2[i] to int for comparison
                num2 = num2 * 10 + (version2[j] - '0');
                ++j;
            }
            
            // acc to ques if version1 > version2 return 1;
            if(num1 > num2)
                return 1;
            // acc to ques if version1 < version2 return 1;
            if(num1 < num2)
                return -1;
            
            ++i, ++j; // for the case when version[i] == '.' , we will skip that
            // If a version number does not specify a revision at an index,
            // then we have to treat the revision as 0
            num1 = 0, num2 = 0;
                
        }
        return 0;
        
    }
};