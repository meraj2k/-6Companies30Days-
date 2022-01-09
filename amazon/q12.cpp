
// https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/

class Solution
{
public:
    string colName(long long int n)
    {
        // your code here
        string t;
        if (n <= 26)
        {
            t += 'A' + n - 1;
            return t;
        }
        if (n % 26 == 0)
        {
            t += 'Z';
            return colName(n / 26 - 1) + t;
        }
        else
        {
            t += ('A' + n % 26 - 1);
            return colName(n / 26) + t;
        }
    }
};