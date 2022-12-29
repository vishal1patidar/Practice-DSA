class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        vector<vector<int>> v;

        for (int i = 0; i < tasks.size(); i++)
        {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(v.begin(), v.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        long long curr = v[0][0];
        vector<int> ans;
        int i = 0, n = tasks.size();

        while (i < n || !pq.empty())
        {

            while (i < n && curr >= v[i][0])
            {
                pq.push({v[i][1], v[i][2]});
                i++;
            }

            auto p = pq.top();
            curr += p.first;
            ans.push_back(p.second);
            pq.pop();

            if (i < n && pq.empty() && curr < v[i][0])
            {
                curr = v[i][0];
            }
        }
        return ans;
    }
};