#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int odd = 0,even = 0;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(k%2 == 0)even++;
        else odd++;
    }
    int ans = 0;
    for(int j = 0;j<m;j++){
        int k;
        cin>>k;
        if(k%2 == 0&&odd != 0){
            odd--;
            ans++;
        }
        else if(k%2 == 1&&even != 0){
            even--;
            ans++;
        }
    }
    cout<<ans;
}
