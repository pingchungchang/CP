#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans = 0;
    int now = 0;
    for(int i = 0;i<n;i++){
        string k;
        cin>>k;
        if(k == "L") now--;
        else if(k == "R") now++;
        else{
            int r;
            cin>>r;
            if(now == r) ans++;
        }
    }
    cout<<ans<<endl;
}