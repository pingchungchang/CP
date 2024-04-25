#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2e5+10;
int bit[mxn];
void modify(int p,int v){
    for(;p<mxn;p += p&-p)bit[p] += v;
    return;
}
int getval(int s,int e){
    int re = 0;
    for(;e>0;e-= e&-e)re += bit[e];
    s--;
    for(;s>0;s -=s&-s)re -= bit[s];
    return re;
}
void init(int n){
    for(int i = 1;i<=n;i++){
        modify(i,-getval(i,i));
    }
}
void solve(){
    int n;
    cin>>n;
    int a[n+2],b[n+2];
    a[0] = b[0] = INT_MAX;
    b[n+1] = a[n+1] = INT_MAX;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    map<int,int> cnt;
    int m;
    cin>>m;
    while(m--){
        int k;
        cin>>k;
        cnt[k]++;
    }
    for(int i = 1;i<=n;i++){
        if(a[i]<b[i]){
            cout<<"NO\n";
            return;
        }
    }
    set<int> st;
    st.insert(0);
    st.insert(n+1);
    vector<pii> v;
    for(int i = 1;i<=n;i++){
        v.push_back({b[i],i});
    }
    sort(v.rbegin(),v.rend());
    vector<int> wait;
    int now = 0;
    for(auto &i:v){
        if(now != i.fs){
            while(!wait.empty()){
                st.insert(wait.back());
                wait.pop_back();
            }
            now = i.fs;
        }       
        auto lit = --st.upper_bound(i.sc);
        auto rit = st.upper_bound(i.sc);
        // cout<<i.fs<<' '<<i.sc<<' '<<*lit<<' '<<*rit<<',';
        if(i.fs != a[i.sc]&&b[*lit] != i.fs&&b[*rit] != i.fs){
            if(!cnt[i.fs]){
                cout<<"NO\n";
                return;
            }
            cnt[i.fs]--;
        }
        if(i.fs == a[i.sc])wait.push_back(i.sc);
        else st.insert(i.sc);
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}