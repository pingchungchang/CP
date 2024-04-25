#include <bits/stdc++.h>
using namespace std;

int fac(int k){
    int re = 1;
    for(int i = 1;i<=k;i++)re *= i;
    return re;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int cnt = 0;
    for(int i = 1;i<10;i++){
        for(int ii = 0;ii<10;ii++){
            for(int iii = 0;iii<10;iii++){
                for(int iiii = 0;iiii<10;iiii++){
                    for(int iiiii = 0;iiiii<10;iiiii++){
                        for(int iiiiii = 0;iiiiii<10;iiiiii++){
                            cnt++;
                            if(cnt == n)cout<<i<<i<<ii<<iii<<iiii<<iiii<<iiiii<<iiiiii<<iiiii;
                        }
                    }
                }
            }
        }
    }
    return 0;
}