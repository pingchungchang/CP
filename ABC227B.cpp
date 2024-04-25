#include <bits/stdc++.h>
using namespace std;

bool f(int now){
    for(int j = 1;j<=now;j++){
        int tmp = now-j*3;
        int c = j*4+3;
        if(tmp%c == 0&&tmp>0)return false;
    }
    return true;
}
int main(){
    int n,s;
    cin>>n;
    int ans = 0;
    for(int i = 0;i<n;i++){
        cin>>s;
        ans += f(s);
    }
    cout<<ans;
}
