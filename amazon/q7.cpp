
//   https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1


class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string res;
		    int count[26]={0};
		    queue<char> q;
		    for(int i=0;i<A.length();i++){
		        count[A[i]-'a']++;
		        if(count[A[i]-'a']==1){
		            q.push(A[i]);
		        }
		        while(!q.empty() && count[q.front()-'a']>1){
		            q.pop();
		        }
		        res+=q.empty()?'#':q.front();
		    }
		    return res;
		}

};
