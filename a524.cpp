#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        string s;
        for(int i = 0;i<n;i++){
            s = (char)('1'+i)+s;
        }
        cout<<s<<endl;
        while(prev_permutation(s.begin(),s.end())){
            cout<<s<<endl;
        }
    }
}
