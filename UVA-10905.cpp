#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class Compare{
public:
    bool operator()(string a,string b){
        return a+b>b+a;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n;
    while(cin>>n){
        if(n == 0)return 0;
        vector<string> v(n);
        for(int i =0;i<n;i++){
            cin>>s;
            v[i] = s;
        }
        sort(v.begin(),v.end(),Compare());
        for(int i =0;i<n;i++){
            cout<<v[i];
        }
        cout<<'\n';
    }
}