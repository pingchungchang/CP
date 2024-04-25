#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> s;
    int n;
    cin>>n;
    int ans =0;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        s.insert(k);
    }
    cout<<s.size();
}
