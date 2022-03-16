//The algorithm: (vector pushed emulates stack, pushId emulates size of the stack)

//At i iteration place pushed[i] at the top of the stask.
//While pushed[pushId] == popped[poppId]. Pop top-element of the stack
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pushId = -1, poppId = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            pushed[++pushId] = pushed[i];
            while (pushId >= 0 and pushed[pushId] == popped[poppId]) {
                --pushId;
                ++poppId;
            }
        }
        return pushId == -1;
    }
};