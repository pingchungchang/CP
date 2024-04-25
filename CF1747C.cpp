#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    if(arr[0] == 1){
        cout<<"Bob\n";
        return;
    }
    else{
        arr[0]--;
        if(arr[0] < *min_element(arr+1,arr+n)){
            cout<<"Bob\n";
        }
        else cout<<"Alice\n";
        return;
    }

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}