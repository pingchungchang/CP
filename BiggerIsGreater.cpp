#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    while(cin>>s){
        if(next_permutation(s.begin(),s.end())){
            cout<<s<<endl;
        }
        else{
            cout<<"no answer\n";
        }
    }
}