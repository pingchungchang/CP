#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int biggest = 0;
    int smallest = INT_MAX;
    int ans = 0;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(biggest<k){
            if(smallest != INT_MAX){
                ans = max(biggest-smallest,ans);
            }
            biggest = k;
            smallest = k;
        }
        smallest = min(smallest,k);
    }
    ans = max(biggest-smallest,ans);
    cout<<ans;
}