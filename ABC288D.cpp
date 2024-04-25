#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    // #define cin fin
    // ifstream fin("input.txt");
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll k;
    cin>>k;
    vector<vector<ll>> pref(n+1,vector<ll>(k,0));
    ll arr[n+1];
    arr[0] = 0;
    ll diff[n];
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        diff[i] = arr[i]-arr[i-1];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<k;j++)pref[i][j] = pref[i-1][j];
        pref[i][i%k] += diff[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        bool flag = true;
        // ll tmp[n+1];
        // for(int i = 1;i<=n;i++)tmp[i] = arr[i];
        // for(int i = l;i+k-1<=r;i++){
        //     for(int j = i+1;j<i+k;j++)tmp[j] -= tmp[i];
        //     tmp[i] = 0;
        // }
        // for(int i = l;i<=r;i++){
        //     cout<<tmp[i]<<' ';
        //     if(tmp[i] != 0)flag = false;
        // }
        // if(flag)cout<<"Yes\n";
        // else cout<<"No\n";
        // continue;
        for(int i = 0;i<k;i++){
            auto sum = pref[r][i]-pref[l][i];
            if(i%k == (r+1)%k)continue;
            if(l%k == i)sum += arr[l];
            // cout<<i<<' '<<sum<<endl;
            if(sum != 0)flag = false;
        }
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
/*
-16 4 21 21 37 17
0 20 37 37 37 17
0 0 17 17 17 17
a[k]:
k = 3
1 4 2 8 5 7
0 3 1 8 5 7
0 0 -2 6 5 7

3 -1 1 -2 2 0 5
3 -4 2 -3 4 -2
0 2 -3 0 -2
0 0 -3 0 0
-16 4 21 21 37 17
-16 20 17 0 16 -20
0 1 1 -1 -1 -1
1 2 1 0 -1

2
18 -2 5 -8 3 
18 -20 7 -13 11
*/