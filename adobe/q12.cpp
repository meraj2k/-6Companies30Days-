

//    https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/

class Solution
{
    //Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        // Code here
        vector<int> res;

        int mx = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (mx <= a[i])
            {
                mx = a[i];
                res.push_back(mx);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};