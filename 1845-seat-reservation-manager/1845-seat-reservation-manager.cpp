class SeatManager {
public:
//this set will keep the track of all the unreserved seat
    set<int>st;

    SeatManager(int n) 
    {
    //fillin the st with all the values
    for(int i=1;i<=n;i++)
    {
        st.insert(i);
    }        
    }
        
    int reserve() 
    {
        int seat = *(st.begin());
        st.erase(st.begin());
        return seat;
    }
    void unreserve(int seat) 
    {
        st.insert(seat);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */