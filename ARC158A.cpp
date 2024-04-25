#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    if((a+b+c)%3 != 0){
        cout<<"-1\n";
        return;
    }
    if(a%2!= b%2||b%2 != c%2||c%2 != a%2){
        cout<<"-1\n";
        return;
    }
    ll arr[] = {a,b,c};
    sort(arr,arr+3);
    ll avg = (arr[0]+arr[1]+arr[2])/3;
    ll cnt = 0;
    for(auto &i:arr)if(i>avg)cnt += i-avg;
    assert(cnt%2 == 0);
    cnt/=2;
    cout<<cnt<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}