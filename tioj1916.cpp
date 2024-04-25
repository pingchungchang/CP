#include <bits/stdc++.h>
using namespace std;


const int mxn = 2020;
int arr[mxn][mxn];
int n;
unordered_map<int,int> mp;
int sx,sy,ex,ey;

int calc(int tar){
    int cnt = 0;
    for(int i = sx;i<=ex;i++){
        for(int j = sy;j<=ey;j++){
            if(arr[i][j] == tar)cnt++;
        }
    }
    return cnt;
}
void solve(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++)cin>>arr[i][j];
    }
    int q;
    cin>>q;
    while(q--){
        cin>>sx>>ex>>sy>>ey;
        int x[7],y[7];
        for(auto &i:x)i = rand()%(ex-sx+1);
        for(auto &i:y)i = rand()%(ey-sy+1);
        int area = (ex-sx+1)*(ey-sy+1);
        bool flag = false;
        for(auto &i:x){
            if(flag)break;
            for(auto &j:y){
                if(calc(arr[sx+i][sy+j])>area/2){
                    cout<<arr[sx+i][sy+j]<<'\n';
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)cout<<"-1\n";
    }
    return;
}
int main(){
    srand(time(NULL));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        if(!n)return 0;
        solve();
    }
}