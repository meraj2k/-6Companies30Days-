
//  Https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        int res=(K-1+(M%N))%N;
        return res==0?N:res;
    }
};
