#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll arr[3];
    for(auto &i:arr)cin>>i;
    sort(arr,arr+3);
    if(arr[2]>arr[1]+arr[0]){
        cout<<"-1";
        return 0;
    }
    ll d1 = arr[1]-arr[0];
    ll ans = 0;
    ans += d1;
    arr[1] =arr[0];
    arr[2] -= d1;
    ll d2 = arr[2]-arr[1];
    ans += d2*2;
    arr[1] -= d2;
    ans += arr[1];
    cout<<ans;

}

/*
13
42

31
24

42
13

24
31

12
34

*/