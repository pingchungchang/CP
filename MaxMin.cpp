#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i =0;i<n;i++){
        int j;
        cin>>j;
        v.push_back(j);
    }
    int ans = 9999999999;
    sort(v.begin(),v.end());
    for(int i =0;i<v.size()-k+1;i++){
        ans = min(ans,v[i+k-1]-v[i]);
    }
    cout<<ans;
    return 0;
}
