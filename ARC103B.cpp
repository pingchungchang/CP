#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i = 1;i<n;i++){
        if(abs(v[i].first+v[i].second)%2 != abs(v[i-1].first+v[i-1].second)%2){
            cout<<-1;
            return 0;
        }
    }
}
