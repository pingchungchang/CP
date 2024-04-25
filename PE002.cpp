#include <bits/stdc++.h>
using namespace std;


#define ll long long
int main(){
    ll a = 1,b = 2,total = 0;
    while(a<=4*1e6){
        if(a%2 == 0)total += a;
        swap(a,b);
        b = a+b;
    }
    cout<<total;
}
