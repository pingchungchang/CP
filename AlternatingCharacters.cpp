#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        string s;
        cin>>s;
        int ans = 0;
        for(int j = 0;j<s.size()-1;j++){
            if(s[j] == s[j+1]) ans ++;
        }
        cout<<ans;
        if(i !=n-1) cout<<"\n";
    }
}
