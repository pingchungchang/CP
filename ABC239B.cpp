#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x;
    cin>>x;
    if(x>0)cout<<x/10;
    else cout<<-((abs(x)+9)/10);
}