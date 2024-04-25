#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        int k;
        cin>>k;
        char c;
        int ans = 0;
        for(int j =0;j<k-1;j++){
            cin>>c;
            //cout<<c<<',';
            if(c == '0')continue;
            else{
                ans += c-'0';
                ans++;
            }
        }
        cin>>c;
        //cout<<c<<'.';
        ans+= c-'0';
        cout<<ans<<'\n';
    }
}
