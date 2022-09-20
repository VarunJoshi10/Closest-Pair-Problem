# Closest-Pair-Problem
The repository includes a C++ solution for n dimensional closest pair problem.

# Aim
Implement a solution to find a minimum distance between two points.
Input array: each element defined as [a,b] for example [2,3]
Use distance formula.

# Solution
## Bruteforce method
Brute force method is a simple approach and provides a solution easily implementable. Basic idea is to compare each n dimensional points with each other, and calculate the distances. Afterwards, select the minimum of the distances, and return the point pair it belongs to. This is a compute heavy method, where n(n-1)/2 comparison is needed. Using this algorithm the problem can be solved in O(n^2) time where n is the number of points. Implementation can be found under */closestpairproblem.cpp*

## Divide and conquer method
Divide and conquer method approach in n dimension is not trivial. Implementation steps should be the following: first, the input set (S) needs to be divided into two halves, then recursively find their minimum. Choose the smallest from the two minimums (δ). After, points of S are projected to H hyperplane, where S' represents points that are within δ to H. Using δ as sparsity condition, only O(n) pairs need to be recursively examined. Calculation can be done in O(n(log n)^d−1 time where d is dimension. The algorithm can be optimized up to O(n log n).

# Steps to find closest pair
-1) We sort all points according to x coordinates.<br>
-2) Divide all points in two halves.<br>
-3) Recursively find the smallest distances in both subarrays.<br>
<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/mindis.png" width="350" title="hover text">
</p>
-4) Take the minimum of two smallest distances. Let the minimum be d.<br> 
-5) Create an array strip[] that stores all points which are at most d distance away from the middle line dividing the two sets.<br>
<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/closepair.png" width="350" title="hover text">
</p>
-6) Find the smallest distance in strip[]. <br>
-7) Return the minimum of d and the smallest distance calculated in above step 6.<br>

# Time Complexity
Let Time complexity of above algorithm be T(n). Let us assume that we use a O(nLogn) sorting algorithm. The above algorithm divides all points in two sets and recursively calls for two sets.
After dividing, it finds the strip in O(n) time. Also, it takes O(n) time to divide the  array around the mid vertical line. Finally finds the closest points in strip in O(n) time.<br> 
So T(n) can be expressed as follows<br> 
-T(n) = 2T(n/2) + O(n) + O(n) + O(n) <br>
-T(n) = 2T(n/2) + O(n) <br>
-T(n) = T(nLogn)<br>



# Test Cases
## Test Case 1
Array[]={{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}<br>
Output=The smallest distance is 1.41421

## Test Case 2
Array[]={{4, 1}, {15, 20}, {30, 40}, {8, 4}, {13, 11}, {5, 6}}<br>
Output=The smallest distance is 3.60555
