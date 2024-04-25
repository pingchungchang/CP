#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int sub;
const int mxn = 2808;
ll a[mxn][mxn],b[mxn][mxn];
int main(){
    ll n,p;
    cin>>sub;
    cin>>n>>p;
    for(int i = 1;i<=n;i++)for(int j =1;j<=n;j++)cin>>a[i][j];
    for(int i = 1;i<=n;i++)for(int j =1;j<=n;j++)cin>>b[i][j];
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                ans[i][j] += a[i][k]*b[k][j];
            }
            ans[i][j] %= p;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=n;j++){
            if(ans[i][j] != 0){
                cout<<i<<' '<<j<<' '<<ans[i][j]<<'\n';
            }
        }
    }
    return 0;
}