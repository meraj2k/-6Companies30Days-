
//  https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/

class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        // your code here
        if (k == 1)
            return arr;
        deque<int> q;
        vector<int> v;
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && arr[i] > arr[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        v.push_back(arr[q.front()]);
        for (int i = k; i < n; i++)
        {
            while (q.front() <= i - k)
            {
                q.pop_front();
            }
            while (!q.empty() && arr[i] > arr[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            v.push_back(arr[q.front()]);
        }
        return v;
    }
};