#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int i =0;i<t;i++){
        ll x,y;
        cin>>y>>x;
        ll base =0;
        if(x>=y){
            if(x&1==0){
                base += (x-1)*(x-1);
                base +=y;
            }
            else{
                base += x*x;
                base -= (y-1);
            }
        }
        else{
            if(y&1 == 1){
                y--;
                base += y*y;
                base += x;
            }
            else{
                base += y*y;
                base -=(x-1);
            }
        }
        cout<<base<<'\n';
    }
}
//failed
