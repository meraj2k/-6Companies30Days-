

//  https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/



class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        queue<string> q;
        q.push("");
        for(int i=0;i<n;i++){
            while(q.front().size()==i){
                for(char ch:mp[a[i]]){
                    q.push(q.front()+ch);
                }
                q.pop();
            }
        }
        vector<string> v;
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        return v;
    }
};