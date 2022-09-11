// Intuition:
// We can notice one thing that no matter who we choose for K Engineers, we should use the minimum value of efficiency among them. So, simple we can fix the Engineer who has the minimum efficiency by sorting the whole array based on the efficiency in decreasing order.

// Approach:

// Let's say that efficiency[i] >= efficiency[j] where i < j.
// While we iterate the array, we can assume that ith engineer should be the member of K.
// So what we should do is to find out the maximum top k-1 engineer from 0 - i-1.
// So we can use the min heap to keep the minimum value of speed, If the size is already k, then ith member cannot be included. So you can pop the worker who has the minimum speed.
// C++:

class Solution{
public:
    const int mod = (int)1e9 + 7;
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k){
      // to maintain the heap of size k we will use priority queue
      priority_queue<int, vector<int>, greater<int>> pq;
      // to store the pair of efficiency and speed
      vector<pair<int, int>> v;
      for (int i = 0; i < n; i++){
        v.push_back({efficiency[i], speed[i]});
      }
	  // sort in decreasing order of efficiency
      sort(v.rbegin(), v.rend()); 
	  // totSpeed is the sum of speed of k engineers
      long totSpeed = 0, ans = 0;
	  // iterate over all engineers
      for (int i = 0; i < n; i++) {
        int currEff = v[i].first;
        int currSpeed = v[i].second;
		// if the size of pq is k
        if (pq.size() == k) {
		  // remove the minimum speed from the pq
          totSpeed -= pq.top();
          pq.pop();
        }
		// push the current speed in the pq
        pq.push(currSpeed); 
		// add the current speed to the totSpeed
        totSpeed += currSpeed; 
		// update the ans
        ans = max(ans, totSpeed * currEff); 
      }
      return ans % mod;
    }
};

// Time Complexity: O(N * (logN + logK))
// Space Complexity: O(N + K) where N is the total number of candidates and K is the size of team

