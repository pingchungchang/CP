#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        int cons = 1;
        int ans = 0;
        for(int j =0;j<s.size();j++){
            if(s[j] == 'O'){
                ans += cons;
                cons++;
            }
            else{
                cons = 1;
            }
        }
        cout<<ans<<endl;
    }
}
