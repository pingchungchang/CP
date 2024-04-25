#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int m;
        cin>>m;
        vector<int> v(m,0);
        for(int j = 0;j<m;j++){
            int k;
            cin>>k;
            v[j] = k;
        }
        sort(v.begin(),v.end());
        for(int j = v.size()-1;j>=2;j--){
            if(v[j]<v[j-1]+v[j-2]){
                cout<<"YES\n";
                break;
            }
            else if(j==2){
                cout<<"NO\n";
            }
        }
    }
}