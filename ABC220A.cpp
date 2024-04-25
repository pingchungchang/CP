#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int n1 = a/c;
    if(n1*c<a)n1++;
    int n2 = b/c;
    if(n2>=n1)cout<<c*n2;
    else cout<<-1;
}
