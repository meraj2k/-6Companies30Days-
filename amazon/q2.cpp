
//  https://leetcode.com/problems/longest-mountain-in-array/

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int count = 0, res = 0, n = arr.size();
        int j = 1;
        while (1)
        {
            while (j < n && arr[j - 1] < arr[j])
            {
                count++;
                j++;
            }
            if (j == n)
                return res == 0 ? 0 : res + 1;
            if (arr[j - 1] == arr[j])
            {
                count = 0;
                j++;
                continue;
            }
            while (j < n && arr[j - 1] > arr[j])
            {
                count += count ? 1 : 0;
                j++;
            }
            res = max(count, res);
            count = 0;
        }
        return res == 0 ? 0 : res + 1;
    }
};