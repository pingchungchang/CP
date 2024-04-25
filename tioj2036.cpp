#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll cnt[3][10];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int c,a,b,cc;
        cin>>c>>a>>b>>cc;
        int tmp = 0;
        if(a)tmp^=4;
        if(b)tmp^=2;
        if(cc)tmp^=1;
        cnt[c-1][tmp]++;
    }
    long long ans = 0;
    for(int i= 0;i<10;i++){
        for(int j = 0;j<10;j++){
            for(int k =0;k<10;k++){
                if((i|j|k) == 7){
                    ans += cnt[0][i]*cnt[1][j]*cnt[2][k];
                }
            }
        }
    }
    cout<<ans;
}