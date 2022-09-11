// The question simply asks us to find an element in the given array whose frequency is 1.All the other elements have a frequency=2.
// We have to do so in :

// Linear Time
// Using Constant Space
// METHOD 1 : USING MAPS (NOT USING CONSTANT SPACE )
// The question states that we have to find an element in the array with frequency=1.
// So , the first idea that pops in the mind is to store the frequency of each element in a map (or a frequency array) and then traverse that map/array and return the element with frequency=1.

// Map the given array's elements to their frequency. ( KEY : ELEMENT , VALUE : FREQUENCY )
// Traverse that map and return the key whose value =1.
// CODE :
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       unordered_map<int,int> a;
	   for(auto x: nums)
		   a[x]++;
	   for(auto z:a)
		   if(z.second==1)
			   return z.first;
	   return -1;
    }
};
// TC: O(N)
// SC: O(N)

// Now , if we see the above method uses variable extra space, which is why it can't be our answer.
// (Although it is an approach to solve this problem).
// Then how do we solve this ??
// Imagine you have blocks with the array elements inscribed on them. Now , if I sort the array for you and now ask you to find the element , CAN YOU DO SO ??

// Yes , upon sorting , every element will have a similar element adjacent to it , if it has the frequency of 2.

// METHOD 2 : USING SORTING (USING CONSTANT SPACE )
// As explained above , we do the following :

// Sort the array.
// Traverse the array and check if one of the adjacent elements is equal to the current element or not.
// If yes , move ahead. Else return the current element.
// CODE :
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) { 
//        sort(nums.begin(),nums.end());
//         for(int i=1;i<nums.size();i+=2)
//         {
//             if(nums[i]!=nums[i-1])
//                 return nums[i-1];
//         }
//         return nums[nums.size()-1];
//     }
// };
// TC: O(NlogN)
// SC: O(1)

// The above approach can be used to solve the problem . But what if we can improve the time complexity ??
// What if we don't have to sort the array ??
// The following method deals with that approach.

// METHOD 3 : USING BITWISE XOR OPERATOR (USING CONSTANT SPACE )
// To use this approach you first need to understand about Bitwise XOR operator.
// Most of us who have a background in physics ( highschool level ) , are aware of the LOGIC GATES.
// One of such gates is the XOR Gate :
// According to this gate , the output is true , only if both the inputs are of opposite kind .
// That is ,
// A B Y
// 0 0 0
// 0 1 1
// 1 0 1
// 1 1 0

// We apply the extended version of this gate in our bitwise XOR operator.
// If we do "a^b" , it means that we are applying the XOR gate on the 2 numbers in a bitwise fashion ( on each of the corresponding bits of the numbers).
// Similarly , if we observe ,

// A^A=0
// A^B^A=B
// (A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
// Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
// Google It for more details.

// We apply the above observations :

// Traverse the array and take the Bitwise XOR of each element.
// Return the value.
// Why does this work ??
// Because , the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.

// CODE :
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) { 
//        int ans=0;
// 	   for(auto x:nums)
// 	   ans^=x;
// 	   return ans;
//     }
// };
// TC: O(N)
// SC: O(1)

// PS : METHOD 4: SUM OF ELEMENTS
// All the unique elements , in the array have a frequency of 2 , except one element.

// Store all the unique elements in set.
// Add the elements of the set and multiply by 2 (SUM_1).
// Add all the elements of the array(ARRAY_SUM).
// Return (SUM_1 - ARRAY_SUM) .
// Why does this work ??
// ARRAY_SUM = 2*(a1+a2+a3...+ak) + a(k+1)
// SUM_1 = 2*(a1+a2+a3+....+ak+ a(k+1))

// a(x) represents the xth unique element in the array.
// a(k+1) represents the element with frequency=1.