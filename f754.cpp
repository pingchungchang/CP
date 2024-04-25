#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cout<<"Case "<<i+1<<" :\n";
        long long a,b;
        cin>>a>>b;
        for(int j = 0;j<b-1;j++){
            cout<<"第"<<j+1<<"位 : 拿"<<a/b<<"元並說DD! BAD!"<<endl;
            a -= a/b;
        }
        cout<<"第"<<b<<"位 : 拿"<<a<<"元並說DD! BAD!";
        if(i != n-1) cout<<endl;
    }
}
