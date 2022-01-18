

//      https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int i = 0, j = 0;
        long long sum = 0;
        while (j < n)
        {
            sum += arr[j++];
            while (sum > s)
            {
                sum -= arr[i++];
            }
            if (sum == s)
            {
                return {i + 1, j};
            }
        }
        return {-1};
    }
};