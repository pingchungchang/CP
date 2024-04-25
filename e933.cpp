#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char,vector<int>> m;
    for(int i =0;i<s.size();i++){
        m[s[i]].push_back(i);
    }
    int allclear =0;
    string k;
    unordered_map<char,vector<int>> x;
    while(cin>>k){
        // cout<<k<<allclear;
        if(k.size()!= s.size()||allclear==1)continue;
        for(int i =0;i<k.size();i++){
            x[k[i]].push_back(i);
        }
        int done = 1;
        for(int i =0;i<k.size();i++){
            if(s[i] == k[i])done = 0;
            else if(m[s[i]].size()!=x[k[i]].size())done = 0;
            else{
                for(int j =0;j<k.size();j++){
                if(m[s[i]][j]!=x[k[i]][j]) done = 0;
                if(done == 0)break;
                }
            }    
            if(done == 0)break;
            if(i == k.size()-1){
                cout<<k<<"\n\n";
                allclear = 1;
            }
        }
        for(int i =0;i<k.size();i++){
            x[k[i]] = {};
        }
    }
    if(allclear == 0)cout<<"impossible\n\n";
}