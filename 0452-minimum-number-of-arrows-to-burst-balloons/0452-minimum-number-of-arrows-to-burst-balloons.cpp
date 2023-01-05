
        






//Approach

//Greedy algorithm

//1.An arrow shoots through multiple intervals, all of which are coincident. 
//We try to stack the overlapping intervals together and give a jump.

//2.To facilitate identifying coincidence in a single traversal, we sort in
//ascending order on the right

//Complexity

//Time complexity:O(NlogN)

//Space complexity:O(1)

//Code

class Solution {

public:

    int findMinArrowShots(vector<vector<int>>& p) {

        if(p.size() == 0) return 0;

        sort(p.begin(), p.end());

        int lastpoint = p[0][1];

        int ans = 1;

        for(auto point : p) {

            if(point[0] > lastpoint) {

                ans++;

                lastpoint = point[1];

            }

            lastpoint = min(point[1],lastpoint);

        }

        return ans;

    }

};