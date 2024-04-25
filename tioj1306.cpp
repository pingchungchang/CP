#include <bits/stdc++.h>
using namespace std;


string s,t;

void solve(){
    int a = s.size(),b = t.size();
    vector<int> p(b,0);
    if(b>1&&t[0] == t[1])p[1] = 1;
    for(int i = 2;i<b;i++){
        int pt = i-1;
        p[i] = p[pt];
        while(t[p[pt]] != t[i]){
            pt = p[pt]-1;
            p[i] = p[pt];
            if(pt<0){
                p[i] = -1;
                break;
            }
        }
        p[i]++;
    }
    int ans = 0;
    int idx = 0;
    for(int m = 0;m<a-b+1;){
        while(idx<b&&s[idx+m] == t[idx]){
            idx++;
        }
        idx--;
        if(idx == b-1)ans++;
        if(idx == -1){
            idx = 0;
            m++;
        }
        else{
            m = m+idx-p[idx]+1;
            idx = p[idx];
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    for(int asd = 0;asd<tt;asd++){
        cin>>s;
        int q;
        cin>>q;
        for(int i = 0;i<q;i++){
            cin>>t;
            solve();
        }
    }
}

