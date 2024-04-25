#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    map<int,vector<pii>> mp;
    vector<pii> v;
    int nn = n;
    while(n--){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    n = nn;
    string s;
    cin>>s;
    for(int i = 0;i<n;i++){
        if(s[i] == 'L')mp[v[i].sc].push_back({v[i].fs,1});
        else mp[v[i].sc].push_back({v[i].fs,0});
    }
    bool flag = false;
    for(auto &i:mp){
        sort(i.sc.begin(),i.sc.end());
        // for(auto &j:i.sc)cout<<j.fs<<' '<<j.sc<<',';cout<<endl;
        int c = 0;
        for(int j = 0;j<i.sc.size();j++){
            if(j!= 0&&i.sc[j].sc == 1&&c)flag = true;
            if(i.sc[j].sc == 0)c++;
        }
        c = 0;
        for(int j = i.sc.size()-1;j>=0;j--){
            if(j != i.sc.size()-1&&i.sc[j].sc == 0&&c)flag = true;
            if(i.sc[j].sc == 1)c++;
        }
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
}