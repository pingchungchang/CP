#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        vector<int> v(x,-1);
        for(int j = 0;j<4;j++){
            int a;
            cin>>a;
            v[j] = a;
     //       cout<<v[j];
        }
        for(int j = 4;j<v.size();j++){
            v[j] = v[j-1]+v[j-4];
        }
        sort(v.begin(),v.end());
        if(v.size()%2 == 0) cout<<(v[v.size()/2-1]+v[v.size()/2])/2<<endl;
        else cout<<v[v.size()/2]<<endl;
    }
}
