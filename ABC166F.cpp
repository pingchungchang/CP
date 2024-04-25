#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,arr[3];
    string ans;
    cin>>n>>arr[0]>>arr[1]>>arr[2];
    vector<string> req(n);
    for(int i = 0;i<n;i++)cin>>req[i];
    for(ll i = 0;i<n;i++){
        char x = req[i][0],y = req[i][1];
        int a= x-'A';
        int b = y-'A';
        if(arr[a] == 0&&arr[b] == 0){
            cout<<"No";
            return 0;
        }
        if(arr[a]>arr[b]){
            ans += y;
            arr[a]--;
            arr[b]++;
        }
        else if(arr[a]<arr[b]){
            ans += x;
            arr[a]++;
            arr[b]--;
        }
        else{
            if(i == n-1){
                ans+= x;
                break;
            }
            else if(req[i+1][0] == x||req[i+1][1] == x){
                if(arr[3-a-b] == 0){
                    arr[a]++;
                    arr[b]--;
                    ans += x;
                }
                else{
                    arr[b]++;
                    arr[a]--;
                    ans += y;
                }
            }
            else{
                arr[b]++;
                arr[a]--;
                ans += y;
            }
        }
    }
    cout<<"Yes\n";
    for(auto i:ans)cout<<i<<'\n';
}
