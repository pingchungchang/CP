#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int l = 1,r = 1;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(k == 0)l = i+1;
        else r = i+1;
    }
    cout<<min(l,r);
}
