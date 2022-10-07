class MyCalendarThree {
    map<int, int> times;
public:
    int book(int s, int e) {
        times[s]++; 
        times[e]--; 
        int events_on = 0, ans = 0;
        for (pair<int, int> x : times)
            ans = max(ans, events_on += x.second);
        return ans;
    }
};