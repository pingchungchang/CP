#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int x =0;x<t;x++){
        int a,b,c;
        cin>>a>>b>>c;
        int total = abs(a-b);
        total*=2;
        if(total<a||total<b||total<c)cout<<-1<<'\n';
        else{
            int dif = abs(a-b);
            if(c>dif)cout<<c-dif<<'\n';
            else cout<<c+dif<<'\n';
        }
    }
}
