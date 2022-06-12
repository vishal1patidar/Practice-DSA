# Hexadecimal to decimal counter
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You are given a number str(in string format)&nbsp;in hexadecimal. A new number can be made from the number str&nbsp;by selecting any subsequence of it (in HexaDecimal) and rearranging it.<br>
You have tell the number of distinct numbers that can be made from number n.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>str = "1F"
<strong>Output: </strong>4
<strong>Explanation: </strong>For 1F possible combination are 
1, F, 1F, F1.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>str = "1FF"
<strong>Output: </strong>8
<strong>Explanation: </strong>For 1FF possible combinations are
1, F, 1F, F1, FF, 1FF, F1F, FF1.</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anyhthing. Your task is to complete the function&nbsp;<strong>countOfDistinctNo()&nbsp;</strong>which takes str in string format as input and returns the total possible combination modulo 10<sup>9</sup>+7.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Compelxity:&nbsp;</strong>O(L*L)&nbsp;where L is the length of the string str.<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(L)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= n &lt;= 2<sup>8000</sup>&nbsp;where n = str in decimal.</span></p>
 <p></p>
            </div>