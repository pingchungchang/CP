#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    vector<int> v;
    for(int i =0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    cout<<v[0]<<' '<<v[v.size()-1]<<' ';
    for(int i =1;i<v.size();i++){
        if(v[i]-v[i-1] != 1){
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}
