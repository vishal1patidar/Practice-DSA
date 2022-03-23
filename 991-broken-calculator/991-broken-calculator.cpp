// After reading the problem first approach which would come in my mind is based on the operation which is given.
// That is multiplying and subtracting for reaching from 'startValue' to 'target' value.
// There would be possibly three cases in this...
// 1. If startValue == target then it will be zero.
// 2. If startValue > target then we only subtract by 1 till we get startValue == target.
// 3. If startValue < target then we only multiply it by till we get startValue equal to target or startValue > target. If startValue get greater than target then we only perform decrementing it.
 
//  But this approach fails in second case '\U0001f605'  
// 	I/P startValue = 5 target = 8
// 	Acc to my approach 
// 	First we go from 5->10 ( X 2 )
// 	Second we subtract 10 -> 9 -> 8 
// 	Total steps is 3.
// 	But the answer is 2;
// 	HOW ?? by just decreasing by 1 and then multiplying by 2 i.e 5 -> 4 -> 8.
// Second Approach
// Instead of going from startValue to target value we go for opposite i.e target value to startValue.
// By reversing the operation i.e instead of multiplying we go for dividing and instead of subtarcting we go for adding.
// There would be also possibly three cases in this...
// 1. If target == startValue then it will be zero.
// 2. If  target > startValue then we only divide it by 2 till we get startValue == target or startValue get greater than target. 
// 	IN STEP SECOND WE HAVE ONE MORE SUB CASES.
// 	We only go for division if target is even else we only increase target by 1.
// 3. If target < startValue then we only increment it by 1.

// Example 
// 	I/P  startValue = 5   target = 8
// 	Step - 1 target > startValue then divide target by 2 , it becomes 4.
// 	Step - 2 target < startValue then we only add by 1 till we get target == startValue. We can only find it by subtracting startValue - target value as startValue is > than target in this case.
// 	Therfore total no of steps taken is divide->add i.e '2' which is the answer.
// ALGORITHM

// Step-1 Declare step counter with initial value 0.
// Step-2 Start Iterating with condition check whether target value is greater than startValue or not.
// Step-3 If target > startValue increment step counter by 1. And check whether target value is even or odd.
// Step-4 If target value is even then divide it by 2 else if it is odd add target value by 1.
// Step-5 Loop continues till target become small or equal to startValue.
// Step-6 If target <  startValue then we only add target by 1 till it become equal. So total number of add required can be found by 'startValue - target'. Because currently startValue is > targetValue.
// Step-7 Return step+startValue - target ;
// IF there is some typing mistake then for that i apologize. Thanks for reviewing my idea.

// IMPORTANT POINTS
// Thanks to  brent7890\U0001f601
// The reason why we increment then immediately divide by 2, rather than incrementing more than once and dividing by 2, is simply because, well, better explained in an example:

// say our target is 201. Then, say input is 10, or whatever, something smaller.

// If, somehow, we think, maybe
// 102*2 = 204 then 204 - 1 - 1 - 1 = 201, in total this is 4 operations.

// instead, if we consider
// 102 - 1 = 101 then 101 * 2 = 202 then 202 - 1 = 201, in total is only 3 operations.

// But, to put it in reverse, starting from the target, the way to think about this intuitively is, if we start from a target (prior to dividing by 2) and increment to a larger number, how every many times we increment, we're incrementing by a factor of 2 more than if we simply divide by 2 first, then increment on the smaller number.

// That's why this process is optimal.
// CODE
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int result=0;
        while(target>startValue)
        {
            result++;
            if(target%2==0)
                target=target/2;
            else
                target+=1;
        }
        result=result+(startValue-target);
        return result;
    }
};