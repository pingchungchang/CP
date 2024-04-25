#include <bits/stdc++.h>
using namespace std;


#define ll long long
int n;
ll target;
void re(ll* ans,ll* arr,int s,int e){
    if(target == -1||s>=n-2||e<=2)return;
    ll x = target;
    x -=arr[s];
    x -=arr[e];
    int p1 = 1+s,p2=e-1;
    //cout<<s<<' '<<e<<endl;
    while(p1 < p2){
        if(arr[p1]+arr[p2]>x)p2--;
        else if(arr[p1]+arr[p2]<x)p1++;
        else{
            for(int i =0;i<n;i++){
                if(ans[i] == arr[s]){
                    cout<<i+1<<' ';
                    ans[i] = INT_MAX;
                    break;
                }
            }
            for(int i =0;i<n;i++){
                if(ans[i] == arr[p1]){
                    cout<<i+1<<' ';
                    ans[i] = INT_MAX;
                    break;
                }
            }
            for(int i =0;i<n;i++){
                if(ans[i] == arr[p2]){
                    cout<<i+1<<' ';
                    ans[i] = INT_MAX;
                    break;
                }
            }
            for(int i =0;i<n;i++){
                if(ans[i] == arr[e]){
                    cout<<i+1;
                    break;
                }
            }
            target = -1;
            return;
        }
    }
    re(ans,arr,s+1,e);
    re(ans,arr,s,e-1);
    return;
}
int main(){
    cin>>n>>target;
    ll arr[n];
    ll ans[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
        ans[i] = arr[i];
    }
    sort(arr,arr+n);
    re((ll*)ans,(ll*)arr,0,n-1);
    if(target != -1)cout<<"IMPOSSIBLE";
}
//failed
