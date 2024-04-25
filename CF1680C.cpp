#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
string s;
vector<pair<int,int>> pref;
vector<pair<int,int>> suff;
void solve(){
    cin>>s;
    s+="0";
    s = "0"+s;
    pref = vector<pii>(s.size()+1,make_pair(0,0));
    suff = vector<pii>(s.size()+1,make_pair(0,0));
    int total = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '1')pref[i+1].sc++;
        else pref[i].fs++;
        if(s[i] == '0')total++;
        if(i != 0)pref[i].fs+= pref[i-1].fs;
        if(i != 0)pref[i].sc+= pref[i-1].sc;
    }
    for(int i = s.size()-1;i>=0;i--){
        if(s[i] == '1')suff[i].sc ++;
        else suff[i].fs++;
        if(i != s.size()-1)suff[i].fs += suff[i+1].fs;
        if(i != s.size()-1)suff[i].sc += suff[i+1].sc;
    }
    int n = s.size();
    int ans = max(total,pref[n-1].sc);
    for(int i = 0;i<n;i++){
        int l = i+1,r = n-1;
        while(l != r){
            int mid = (l+r)/2;
            if(mid == n-1)break;
            //if(pref[i].sc+suff[mid].sc== total-pref[i].fs-suff[mid].fs)break;
            if(pref[i].sc+suff[mid].sc>total-pref[i].fs-suff[mid].fs)l = mid+1;
            else r = mid;
        }
        //cout<<max(pref[i].sc+suff[l].sc,total-pref[i].fs-suff[l].fs)<<' '<<l<<'\n';
        ans = min(ans,max(pref[i].sc+suff[l].sc,total-pref[i].fs-suff[l].fs));
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
