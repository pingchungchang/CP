#include <bits/stdc++.h>
using namespace std;
class Compare{
    public:
    bool operator()(pair<char,pair<int,int>>a,pair<char,pair<int,int>> b){
        return a.first<b.first;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,s;
    cin>>n>>m>>s;
    vector<pair<char,pair<int,int>>> v;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            char c;
            cin>>c;
            if(c != '0')v.push_back(make_pair(c,make_pair(i,j)));
        }
    }
    if(s>v.size()){
        cout<<"Mission fail.";
        return 0;
    }
    sort(v.begin(),v.end(),Compare());
    for(int i =0;i<s;i++){
        cout<<v[i].second.first<<' '<<v[i].second.second;
        if(i != s-1)cout<<'\n';
    }
}