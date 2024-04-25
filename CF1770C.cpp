#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 101;
bitset<mxn> isp;
vector<int> primes;
void solve(){
    int n;
    cin>>n;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(arr[i]== arr[j]){
                cout<<"NO\n";
                return;
            }
        }
    }
    for(auto &i:primes){
        int cnt[i] = {};
        for(auto &j:arr){
            cnt[j%i]++;
        }
        if(*min_element(cnt,cnt+i)>=2){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 2;i<mxn;i++){
        if(!isp[i]){
            primes.push_back(i);
            for(int j = i+i;j<mxn;j+=i)isp[j] = true;
        }
    }
    int t;
    cin>>t;
    while(t--)solve();
}