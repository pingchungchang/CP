#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        vector<int> v(3,0);
        for(int i = 0;i<3;i++){
            int k;
            cin>>k;
            v[i] = k;
        }
        //cout<<v[0]<<v[1]<<v[2];
        sort(v.begin(),v.end());
        cout<<"Case "<<i+1<<": "<<v[1]<<endl;
    }
}
