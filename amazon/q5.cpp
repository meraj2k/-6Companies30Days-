
//  https://practice.geeksforgeeks.org/problems/phone-directory4628/1/


struct Node{
    struct Node * child[26]={NULL};
    bool isEnd=false;
};


void find(Node *root,string temp,vector<string> & res){
    if(root==NULL){
        return;
    }
    if(root->isEnd){
        res.push_back(temp);
    }
    for(int j=0;j<26;j++){
        if(root->child[j]){
            find(root->child[j],temp+char(j+'a'),res);
        }
    }
}
vector<string> find_all(string s,Node* root){
    vector<string> res;
    for(char ch: s){
        if(root->child[ch-'a']){
            root=root->child[ch-'a'];
        }
        else{
            return {"0"};
        }
    }
    find(root,s,res);
    return res;
}

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Node * root=new Node();
        for(int i=0;i<n;i++){
            string str=contact[i];
            Node * curr=root;
            for(char ch: str){
                //cout<<ch;
                if(!curr->child[ch-'a']){
                    curr->child[ch-'a']=new Node();
                }
                curr=curr->child[ch-'a'];
            }
            curr->isEnd=true;
            //cout<<endl;
        }
        string temp;
        vector<vector<string>> res;
        for(char ch: s){
             Node * curr=root;
            temp+=ch;
            res.push_back(find_all(temp,curr));
        }
        return res;
    }
};