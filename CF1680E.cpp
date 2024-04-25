#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
void solve(){
    int n;
    cin>>n;
    vector<string> v(2);
    cin>>v[0]>>v[1];
    n = v[0].size();
    vector<pii>all;
    int l = INT_MAX,r = 0;
    for(int i = 0;i<n;i++){
        if(v[0][i] == '*'&&v[1][i] == '*'){
            all.push_back(make_pair(-1,1));
            l = min(l,i);
            r = max(r,i);
            continue;
        }
        if(v[0][i] == '*'){
            l = min(l,i);
            r = max(r,i);
            if(all.size() == 0||all.back().fs != 0){
                all.push_back(make_pair(0,1));
            }
            else all.back().sc++;
        }
        if(v[1][i] == '*'){
            l = min(l,i);
            r = max(r,i);
            if(all.size() == 0||all.back().fs != 1){
                all.push_back(make_pair(1,1));
            }
            else all.back().sc++;
        }
    }
    int now = 0;
    int ans1 = 0;
    for(auto i:all){
        if(i.fs == -1){
            ans1++;
            now = -1;
            continue;
        }
        if(now == i.fs||now == -1){
            now = i.fs;
        }
        else if(i.sc>=2){
            now^=1;
            ans1++;
        }
        else{
            ans1++;
            now = -1;
        }
    }
    int ans2 = 0;
    now = 1;
    for(auto i:all){
        if(i.fs == -1){
            ans2++;
            now = -1;
            continue;
        }
        if(now == i.fs||now == -1){
            now = i.fs;
            continue;
        }
        else if(i.sc>=2){
            now^=1;
            ans2++;
        }
        else{
            ans2++;
            now = -1;
        }
    }
    cout<<min(ans2,ans1)+(r-l)<<'\n';

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
