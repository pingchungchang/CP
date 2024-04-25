#include <bits/stdc++.h>
using namespace std;

int ask(int a,int b){
    cout<<"? "<<a<<' '<<b<<endl;
    int re;
    cin>>re;
    return re;
}
void solve(){
    int n;
    cin>>n;
    int a = 1,b = 2;
    for(int i = 3;i<=n;i++){
        int ta = ask(a,i),tb = ask(b,i);
        if(ta>tb)b = i;
        else if(ta<tb)a = i;
        else{
            continue;
        }
    }
    cout<<"! "<<a<<' '<<b<<endl;
    int re;
    cin>>re;
    assert(re != -1);
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}