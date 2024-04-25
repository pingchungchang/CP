#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(cin>>n){
        vector<int> sticks(n,0);
        for(int i = 0;i<n;i++){
            int k;
            cin>>k;
            sticks[i] = k;
        }
        int ans = 0;
        sort(sticks.begin(),sticks.end());
        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int l = j+1;l<n;l++){
                    if(sticks[i]*sticks[i]+sticks[j]*sticks[j]==sticks[l]*sticks[l])ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
