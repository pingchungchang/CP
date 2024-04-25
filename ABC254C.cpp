#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<priority_queue<int,vector<int>,greater<int>>> pqv(k);
    for(int i = 0;i<n;i++){
        int tmp;
        cin>>tmp;
        pqv[i%k].push(tmp);
    }
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        v[i] = pqv[i%k].top();
        pqv[i%k].pop();
    }
    for(int i = 1;i<n;i++){
        if(v[i]<v[i-1]){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}
