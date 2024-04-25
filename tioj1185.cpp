#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> v(3);
    long long a,b,c;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>a>>b>>c){
        v[0] = a;
        v[1] = b;
        v[2] = c;
        sort(v.begin(),v.end());
        if(v[0]+v[1]<=v[2])cout<<"BYE\n";
        else cout<<"SAFE\n";
    }
}
