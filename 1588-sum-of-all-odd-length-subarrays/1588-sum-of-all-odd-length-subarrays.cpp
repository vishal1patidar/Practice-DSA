class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr.size(); j++)
            {
                for (int k = i; k <= j; k++)
                    
                    if ((i + j + 1) % 2 != 0 || i + j == 0)
                        ans = ans + arr[k];
            }
        }
        return ans;
    }
};
