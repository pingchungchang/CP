#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    string ia,ib,fa,fb;
    for(int i = 0;i<=a.size();i++){
        if(a[i] == '.'||i == a.size()){
            ia = a.substr(0,i);
            break;
        }
    }
    for(int i = 0;i<=b.size();i++){
        if(b[i] == '.'||i == b.size()){
            ib = b.substr(0,i);
            break;
        }
    }
    for(int i = 0;i<b.size();i++){
        if(b[i] == '.')fb = b.substr(i+1,b.size()-i);
    }
    for(int i = 0;i<a.size();i++){
        if(a[i] == '.')fa = a.substr(i+1,a.size()-i);
    }
    if(ia!= ib){
        if(ia.size()>ib.size())cout<<a;
        else if(ia.size()<ib.size())cout<<b;
        else if(ia>ib)cout<<a;
        else cout<<b;
        return 0;
    }
    if(fa>fb)cout<<a;
    else cout<<b;
}
