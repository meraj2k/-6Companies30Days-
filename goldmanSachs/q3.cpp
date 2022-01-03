//  https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int count=0,i=0,j=0,temp=1;
        while(j<n){
            temp*=a[j];
            while(temp>=k){
                count+=j-i;
                temp/=a[i];
                i++;
            }
            j++;
        }
        count+=(j-i)*(j-i+1)/2;
        return count;
    }
};
