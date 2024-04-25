#include <iostream>
#include <algorithm>

using namespace std;
int trifib(int k, vector<int> &v){
    if(v[k] != -1) return v[k];
    else{
        v[k] = trifib(k-1,v)+trifib(k-2,v)+trifib(k-3,v);
        return v[k];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(37,-1);
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    v[4] = 7;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        cout<<trifib(k,v)<<"\n";
    }
    return 0;
}
