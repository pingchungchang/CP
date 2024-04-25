#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    int ans = INT_MAX;
    for(int i = 0;i<10;i++){
        vector<int> times(10,0);
        for(auto j:v){
            for(int k = 0;k<10;k++){
                if(j[k]-'0' == i){
                    times[k]++;
                }
            }
        }
        int tmp = 0;
        for(int i = 0;i<10;i++){
            tmp = max(tmp,10*(times[i]-1)+i);
        }
        ans = min(ans,tmp);
    }
    cout<<ans;
}
