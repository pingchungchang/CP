#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    long long sum = 0;
    vector<long long> heros(n);
    for(long long i =0;i<n;i++){
        long long k;
        cin>>k;
        heros[i] = k;
        sum+=k;
    }
    sort(heros.begin(),heros.end());
    long long t;
    cin>>t;

    for(long long i =0;i<t;i++){
        long long def,atk;
        cin>>def>>atk;
        if(def>=heros[n-1]){
            long long ans = def-heros[n-1];
            long long totaldef = sum-heros[n-1];
            if(totaldef<atk)ans += atk-totaldef;
            cout<<ans;
        }
        else{
            long long send = lower_bound(heros.begin(),heros.end(),def)-heros.begin();
            long long totaldef = sum-heros[send];
            long long ans = 0;
            if(totaldef>=atk){
                cout<<0<<'\n';
                continue;
            }
            else{
                ans = atk-totaldef;
            }
            if(send != 0)ans = min(ans,def-heros[send-1]+max((long long)0,atk-sum+heros[send-1]));
            cout<<ans;
        }
        cout<<'\n';
    }
}




















/*
        long long def,atk;
        cin>>def>>atk;
        if(def+atk>=sum&&heros[0]<=def){
            cout<<def+atk-sum<<'\n';
        }
        else if(heros[0]>def){
            sum -= heros[0];
            cout<<max(0,atk-sum)<<'\n';
        }
        else{
            long long send = lower_bound(heros.begin(),heros.end(),def)-heros.begin();
            if(heros[n-1]<def){
                cout<<def-heros[n-1]<<'\n';
            }
            else{
                long long totaldef = sum-heros[send];
                if(totaldef>=atk)cout<<0<<'\n';
                else{
                    long long ans = atk-totaldef;
                    ans = min(ans,def-heros[send-1]);
                    cout<<ans<<'\n';
                }
            }
        }
*/
