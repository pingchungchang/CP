#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    while(cin>>a>>b){
        int p1=0,p2=0;
        while(p1<a.size()&&p2<b.size()){
            if(a[p1] == b[p2])p1++;
            p2++;
        }
        if(p1>=a.size())cout<<"Yes\n";
        else cout<<"No\n";
    }
}
