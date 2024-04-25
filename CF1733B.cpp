#include <bits/stdc++.h>
using namespace std;

void solve(){
//x+y = n
//ax+by = n-1
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    if(a == b){
        cout<<"-1\n";
        return;
    }
    if(a<b)swap(a,b);
    int y = (1LL*n*a-n+1)/(a-b);
    int x = n-y;
    if(x<0||y<0||a*x+b*y != n-1){
        cout<<"-1\n";
        return;
    }
    // cout<<a<<' '<<x<<' '<<b<<' '<<y<<":";
    int p = 1,cnt = 0;
    for(int i = 2;i<=n;i++){
        if(cnt == a){
            cnt = 0;
            p = i;
            if(x == 0){
                swap(a,b);
                swap(x,y);
            }
            else x--;
        }
        cout<<p<<' ';
        cnt++;
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}