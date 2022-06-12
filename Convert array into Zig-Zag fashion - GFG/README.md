# Convert array into Zig-Zag fashion
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array <strong>Arr</strong> (distinct elements) of size <strong>N</strong>. Rearrange the elements of array in zig-zag fashion. The converted array should be in form <strong>a &lt; b &gt; c &lt; d &gt; e &lt; f.</strong> The relative order of elements is same in the output <strong>i.e</strong> you have to iterate on the original array only.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7
Arr[] = {4, 3, 7, 8, 6, 2, 1}
<strong>Output: </strong>3 7 4 8 2 6 1
<strong>Explanation:</strong> 3 &lt; 7 &gt; 4 &lt; 8 &gt; 2 &lt; 6 &gt; 1</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
Arr[] = {1, 4, 3, 2}
<strong>Output:</strong> 1 4 2 3
<strong>Explanation: </strong>1 &lt; 4 &gt; 2 &lt; 3</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>zigZag()</strong>&nbsp;which takes the&nbsp;array of&nbsp;integers&nbsp;<strong>arr&nbsp;</strong>and&nbsp;<strong>n</strong><strong>&nbsp;</strong>as parameters and returns void. You need to modify the array itself.<br>
<strong>NOTE:</strong> In the mentioned complexity, only a unique solution will exist.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
0 &lt;= Arr<sub>i</sub> &lt;= 10<sup>6</sup></span></p>

<p>&nbsp;</p>
 <p></p>
            </div>