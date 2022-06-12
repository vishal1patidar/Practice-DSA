# Smallest Positive Integer that can not be represented as Sum
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array of size N, find the smallest positive integer value that cannot be represented as sum of some elements from the array.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>
N = 6
array[] = {1, 10, 3, 11, 6, 15}
<strong>Output: </strong>
2
<strong>Explanation:</strong>
2 is the smallest integer value that cannot 
be represented as sum of elements from the array.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>
N = 3
array[] = {1, 1, 1}
<strong>Output: </strong>
4
<strong>Explanation: </strong>
1 is present in the array. 
2 can be created by combining two 1s.
3 can be created by combining three 1s.
4 is the smallest integer value that cannot be 
represented as sum of elements from the array.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You dont need to read input or print anything. Complete the function <strong>smallestpositive() </strong>which takes the array and N as input parameters and returns the smallest positive integer value that cannot be represented as sum of some elements from the array.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(N * Log(N))<br>
<strong>Expected Auxiliary Space: </strong>O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>6</sup><br>
1 ≤ array[i] ≤ 10<sup>9</sup><br>
Array may contain duplicates.</span></p>
 <p></p>
            </div>