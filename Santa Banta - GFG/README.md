# Santa Banta
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Santa is still not married. He approaches a marriage bureau and asks them to hurry the process.<br>
The bureau checks the list of eligible girls (n) and hands it over to Santa.<br>
Santa being conscious about his marriage, determined to find a girl with maximum connections so that he can gather more information about her.<br>
Accordingly, he looks to figure out the maximum number of girls (from the list) who know each other to achieve the above purpose.<br>
In order to finalize the girl, he needs to find the Kth prime.<br>
Where k = largest group of girls who know each other.<br>
Considering Santa's poor knowledge in Maths, he seeks Banta's help for the answer.<br>
Now you, being a fan of Santa Banta Jokes, take this prestigious opportunity to solve the problem.</span></p>

<p><span style="font-size:18px">In case no of connections is zero, print "-1".</span></p>

<p><span style="font-size:18px"><strong>Note :</strong><br>
Suppose girl "a" knows girl "b" and girl "b" knows girl "c", then girl "a" also knows girl "c".<br>
Transitivity holds.<br>
Consider 1 composite no.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[] = {{1,2},{2,3},{3,4},{4,5},
                            {6,7},{9,10}}
N = 10 and M = 6
<strong>Output :</strong> 11
<strong>Explanation:</strong>
Here in this graph there are 4 groups. 
In 1<sup>st</sup> group: (1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5) are 
there. In 2<sup>nd</sup>&nbsp;group: (6 -&gt; 7) are there.
In 3<sup>rd </sup>group: (8) is there.
In 4<sup>th</sup>&nbsp;group: (10 -&gt; 9) are there.
In these 4 group the maximum number of 
value is 5. So, K = 5 and the 5<sup>th</sup>&nbsp;prime number 
is 11. Return 11.

</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {{1, 2}}
N = 2 and M = 1 <strong>
Output :</strong> 3</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong></span></p>

<p><span style="font-size:18px">This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>helpSanta()</strong> that takes a number of girls <strong>(n)</strong>, a number of connection <strong>(m),</strong>&nbsp;adjacency list of girls connections&nbsp;<strong>(g)</strong>, and return the Kth prime no if there are no connections then return -1. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N + M).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N + M).</span></p>

<p>&nbsp;</p>

<p><br>
<br>
<span style="font-size:18px"><strong>Output:</strong><br>
Each new line of the output contains Kth prime no.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span></p>

<p><span style="font-size:18px">1 ≤ n ≤ 10<sup>5</sup><br>
0 ≤ m ≤ 10<sup>5</sup><br>
1 ≤ u, v ≤ n</span></p>
 <p></p>
            </div>