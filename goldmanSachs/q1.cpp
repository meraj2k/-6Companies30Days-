//question link
//  https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string,vector<string>> mp;
        for(string s:string_list){
            string t=s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it=mp.begin();it!=mp.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
};
