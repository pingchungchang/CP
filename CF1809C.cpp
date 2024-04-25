#include <bits/stdc++.h>
using namespace std;

int calc(int arr[],int n,int k){
    int pos = 0,neg = 0;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            int total = 0;
            for(int k = i;k<=j;k++)total += arr[k];
            if(total<0)neg++;
            else pos++;
        }
    }
    return pos;
}

void solve(){
    int n;
    cin>>n;
    int arr[n] = {};
    int p = 0;
    int k;
    cin>>k;
    int pref = 0;
    int pcnt = 0;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(cnt == k)arr[i] = -1000;
        else{
            int dif = k-cnt;
            if(dif>=pcnt+1){
                arr[i] = 2;
                cnt += pcnt+1;
                pref += 2;
                pcnt++;
            }
            else{
                arr[i] = -2*(pcnt-dif+1)+1;
                cnt += dif;
                pcnt = dif;
                pref += arr[i];
            }
        }
    }
    for(auto &i:arr)cout<<i<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}