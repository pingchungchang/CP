#include <bits/stdc++.h>
using namespace std;

#define ld long double
int main(){
    int n;
    cin>>n;
    ld ans = 0;
    for(int i = 1;i<n;i++){
        ans += n/(ld)(i);
    }
    cout<<fixed<<setprecision(6)<<ans;
}
