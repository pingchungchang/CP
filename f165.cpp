#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(b == 0||a == 0)cout<<"OK!";
    else if(a%b ==0)cout<<"OK!";
    else cout<<a%b;
}
