#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        unordered_map<int,vector<string>> m;
        int n = -9999;
        for(int j = 0;j<10;j++){
            string s;
            int k;
            cin>>s>>k;
            n = max(k,n);
            m[k].push_back(s);
        }
        cout<<"Case #"<<i+1<<": \n";
        for(int j = 0;j<m[n].size();j++){
            cout<<m[n][j]<<"\n";
        }
    }
}
