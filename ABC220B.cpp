#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    long long c;
    cin>>c>>a>>b;
    long long na =0,nb=0;
    long long k = 1;
    for(int i = a.size()-1;i>=0;i--){
        na += k*(a[i]-'0');
        k*= c;
    }
    k = 1;
    for(int i = b.size()-1;i>=0;i--){
        nb += k*(b[i]-'0');
        k*=c;
    }
    cout<<na*nb;
}
