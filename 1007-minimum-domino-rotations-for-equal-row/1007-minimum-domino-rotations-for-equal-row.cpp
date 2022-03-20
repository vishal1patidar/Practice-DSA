// ALGORITHM
// We will keep faceA for count the occurences of numbers in tops.
// faceB for count the occurences of n umbers in bottoms.
// same for counting the same occurences in top & bottom.
// We wiil try all possibilities of domino from 1 to 6.
// If we can make number i in a whole row it should satisfy that faceA[i] + faceB[i] - same[i] == n
// eg the first test Case.
// tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// faceA[2] = 4 , as tops[0] = tops[2] = tops[4] = tops[5]
// faceB[2] = 3, as bottoms[1] = bottoms[3] = bottoms[5]
// same[2] = 1, as tops[5] = bottoms[5]
// Therefore we have faceA[2] + faceB[2] - same[2] = 6, (size of arr)
// Therfore we can make 2 in a whole row.
// ANALYSIS :-

// TIME COMPLEXITY :- O(n)
// SPACE COMPLEXITY :- O(1)
// CODE WITH EXPLANATION

			
// class Solution {
// public:
//     int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         int n = tops.size();
        
//         // faceA for counting the occurence in tops
// 		// faceB for counting occurence of numbers in bottoms
//         // same for counting when both tops and bottoms have same occurences
//         vector<int> faceA(7), faceB(7), same(7);
        
//         for(int i = 0; i < n; ++i)
//         {
//             ++faceA[tops[i]];
//             ++faceB[bottoms[i]];
            
//             if(tops[i] == bottoms[i])
//                 ++same[tops[i]];
//         }
        
//         int minRotation = INT_MAX;
        
// 		// all possibilities from 1 to 6
//         for(int i = 1; i<=6; ++i)
//         {
//             if(faceA[i] + faceB[i] - same[i] == n)
//                 minRotation = min(minRotation , min(faceA[i],faceB[i]) - same[i]);
//         }
        
//         return minRotation == INT_MAX ? -1 : minRotation;
        
//     }
// };
// APPROACH 2
// AlGORITHM

// As we have to find minimum Number of Rotations to make both array same.
// we try to make all tops faces same, & all bottoms faces same.
// we will iterate for all 6 values and calculate the swap for all 6 values, by 3 conditions :-
// if (tops[j] == i) (means no need to swap therefore we will continue)
// else if (bottoms[j] == i) (means swap is possible) we increment the swap.
// else swap is not possible and neither values are same we break the loop.
// As iteration reaches the end we check if (minRotaion > swap) & update minRotaion as we have to find minimum.
// we will get the number of rotaion of making both tops faces same & bottoms faces same.
// now we have to return min of both , or if (ab == -1) then ba or if (ba == -1) then ab.
// ANALYSIS :-

// TIME COMPLEXITY :- O(n)
// SPACE COMPLEXITY :- O(1)
// CODE WITH EXPLANATION


class Solution {
public:
    
    int dominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        int minRotation = INT_MAX;
        for(int i = 1; i <= 6; ++i)
        {
            int swap = 0 , j;
            for(j = 0; j<tops.size(); ++j)
                {
                    if(tops[j] == i)
                        continue;
                    else if(bottoms[j] == i)
                        ++swap;
                    else
                        break;
                }
                
                // if we reach at the end of vector && minRotation > swap
                if(j == tops.size() && minRotation > swap)
                    minRotation = swap;
        }
        return minRotation == INT_MAX ? -1 : minRotation;
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        // try to make all tops faces same
        int ab = dominoRotations(tops,bottoms);
        
        // try to make all tops faces same
        int ba = dominoRotations(bottoms,tops);
        
        return ab == -1 ? ba : ba == -1 ? ab : min(ab,ba);
    }
};