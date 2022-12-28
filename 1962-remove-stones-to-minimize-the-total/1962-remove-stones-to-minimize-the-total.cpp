class Solution 
{
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        //use max-heap priority queue to get maximum values from piles
        priority_queue<int> pq; 
        for(auto &it:piles) pq.push(it); //put all elements in the priority queue

        int n;
        while(k-- && !pq.empty()) //apply operation k times
        {
            n = pq.top(); pq.pop(); //take max element
            n = n-n/2; //remove stones
            pq.push(n); //put remaining stones
        }

        int sum=0;
        while(!pq.empty()) //count total number of stones
        {
            sum += pq.top(); pq.pop();
        }
        
        return sum;
    }
};