#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a,b;
    int n;
    cin>>n;
    cin>>a>>b;
    n = a.size();
    int wa = 0,wb = 0;
    for(int i = 0;i<n;i++){
        if(a[i]>b[i])wa++;
        else if(b[i]>a[i])wb++;
    }
    if(wa == wb)cout<<"EQUAL\n";
    else if(wa>wb)cout<<"RED\n";
    else cout<<"BLUE\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
