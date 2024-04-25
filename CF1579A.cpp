#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int asd=0;asd<t;asd++){
        string s;
        cin>>s;
        int arr[3] = {0};
        int n = s.size();
        for(int i =0;i<n;i++){
            arr[s[i]-'A']++;
        }
        if(arr[0]+arr[2]==arr[1])cout<<"YES\n";
        else cout<<"NO\n";
    }
}
