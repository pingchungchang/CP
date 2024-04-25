#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string ans;
    cin>>ans;
    int k;
    cin>>k;
    for(int i = 0;i<k;i++){
        string s;
        cin>>s;
        int right = 0;
        for(int j = 0;j<min(ans.size(),s.size());j++){
            if(s[j] == ans[j]) right++;
        }
        cout<<100 * right/ans.size()<<endl;
    }
}
