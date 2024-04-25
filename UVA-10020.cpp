#include <bits/stdc++.h>
using namespace std;

class Compare{
public:
    bool operator()(pair<int,int> a,pair<int,int>b){
        if(a.first==b.first)return a.second>b.second;
        else return a.first>b.first;
    }
};
int main(){
    int n;
    cin>>n;
    for(int f = 0;f<n;f++){
        int m;
        cin>>m;
        int s,e;
        vector<pair<int,int>> v;
        while(cin>>s>>e){
            if(s == 0&&e==0)break;
            v.push_back(make_pair(s,e));
        }
        sort(v.begin(),v.end(),Compare);
        int ans = 0;
        int nowend = v[0].first;
        for(int i =0;i<v.size();i++){
            if(v[i].second<0)continue;
            if(v[i].first>=nowend)
        }
    }
}
//failed
