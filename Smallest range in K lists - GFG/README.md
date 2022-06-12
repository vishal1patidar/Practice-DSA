# Smallest range in K lists
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given <strong>K</strong> sorted lists of integers,&nbsp;<strong>KSortedArray[]</strong>&nbsp;of size <strong>N</strong> each. The task is to find the smallest range that includes at least one element from each of the <strong>K</strong> lists. If more than one such range's are found, return&nbsp;the first such range found.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
<strong>Output: </strong>1 2<strong>
Explanation: </strong>K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
<strong>Output: </strong>4 9</span></pre>

<p><span style="font-size:18px"><strong>Your Task</strong> : </span></p>

<p><span style="font-size:18px">Complete the function&nbsp;<strong><em>findSmallestRange</em></strong>() that receives array , array size n and k as parameters and returns the output range (as a pair in cpp and array of size 2 in java and python)</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity </strong>:&nbsp;O(n * k *log k)<br>
<strong>Expected Auxilliary Space&nbsp;</strong>&nbsp;: O(k)</span></p>

<div><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= K,N &lt;= 500</span></div>

<div><span style="font-size:18px">0 &lt;= a[ i ] &lt;= 10<sup>5</sup></span></div>
 <p></p>
            </div>