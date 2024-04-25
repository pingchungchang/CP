#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> pos,pref;

ll f(ll tar){
    ll ans = 1e13;
    for(int i = 1;i+tar<=pref.size();i++){
        if(tar&1){
            ll cen = i+tar/2;
            ll s = pos[cen]-tar/2,e = pos[cen]+tar/2;
            ll l = i,r = i+tar-1;
            // cout<<s<<','<<pos[cen]<<','<<e<<":"<<(s+pos[cen])*(pos[cen]-s+1)/2-(pref[cen]-pref[l-1]) <<','<< (pref[r]-pref[cen]) - (e+pos[cen]+1)*(e-pos[cen])/2<<endl;
            ans = min(ans,(s+pos[cen])*(pos[cen]-s+1)/2-(pref[cen]-pref[l-1]) + (pref[r]-pref[cen]) - (e+pos[cen]+1)*(e-pos[cen])/2);
        }
        else{
            ll cen = i+tar/2;
            ll s = pos[cen]-tar/2,e = pos[cen]+tar/2-1;
            ll l = i,r = i+tar-1;
            // cout<<s<<','<<pos[cen]<<','<<e<<":"<<(s+pos[cen])*(pos[cen]-s+1)/2-(pref[cen]-pref[l-1]) <<','<< (pref[r]-pref[cen]) - (e+pos[cen]+1)*(e-pos[cen])/2<<endl;
            cen = i+tar/2-1;
            s = pos[cen]-tar/2+1,e = pos[cen]+tar/2;
            ans = min(ans,(s+pos[cen])*(pos[cen]-s+1)/2-(pref[cen]-pref[l-1]) + (pref[r]-pref[cen]) - (e+pos[cen]+1)*(e-pos[cen])/2);
            // cout<<s<<','<<pos[cen]<<','<<e<<":"<<(s+pos[cen])*(pos[cen]-s+1)/2-(pref[cen]-pref[l-1]) <<','<< (pref[r]-pref[cen]) - (e+pos[cen]+1)*(e-pos[cen])/2<<endl;
        }
    }
    // cout<<tar<<":"<<ans<<endl;
    // cout<<tar<<":"<<ans<<endl;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    ll k;
    cin>>s>>k;
    pos.push_back(0);
    for(int i = 0;i<s.size();i++){
        if(s[i] == 'Y')pos.push_back(i);
    }
    pref = pos;
    for(int i = 1;i<pos.size();i++)pref[i] += pref[i-1];
    // for(auto &i:pref)cout<<i<<' ';cout<<endl;
    ll l = 1,r = pos.size()-1;
    if(pos.size() == 1){
        cout<<"0";
        return 0;
    }
    while(l != r){
        ll mid = (l+r+1)>>1;
        if(f(mid)<=k)l = mid;
        else r = mid-1;
        // cout<<l<<' '<<r<<' '<<k<<endl;
    }
    cout<<l;
}