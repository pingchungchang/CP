#include <bits/stdc++.h>
using namespace std;
class Compare{
    public:
    bool operator()(vector<int> a,vector<int> b){
        int n = a.size();
        for(int i =0;i<n;i++){
            if(a[i]!= b[i])return a[i]<b[i];
        }
        return a[0]<b[0];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    vector<vector<int>> v;
    for(int i =0;i<a;i++){
        vector<int> temp;
        for(int j =0;j<b;j++){
            int k;
            cin>>k;
            temp.push_back(k);
        }
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i =0;i<a;i++){
        for(int j =0;j<b;j++){
            cout<<v[i][j];
            if(j != b-1)cout<<' ';
        }
        if(i != a-1)cout<<'\n';
    }
    return 0;
}
