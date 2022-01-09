

// https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/

class Solution
{
public:
    //Function to count number of ways to reach the nth stair
    //when order does not matter.
    long long countWays(int m)
    {
        // your code here
        // either we select 0 two's 1 two's 2 two's upt to m/2 two's;
        return m / 2 + 1;
    }
};
