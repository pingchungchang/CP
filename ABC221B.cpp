#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int n = a.size();
    vector<int> difs;
    if(a == b){
        cout<<"Yes";
        return 0;
    }
    for(int i =0;i<n-1;i++){
        if(a[i]!= b[i]){
            swap(a[i],a[i+1]);
            if(a == b){
                cout<<"Yes";
                return 0;
            }
            else {
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
