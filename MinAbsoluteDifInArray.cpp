#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i =0;i<n;i++){
        int j;
        cin>>j;
        v.push_back(j);
    }
    int ans = 9999999;
    sort(v.begin(),v.end());
    for(int i =1;i<v.size();i++){
        ans = min(ans,v[i]-v[i-1]);
    }
    cout<<ans;
}
