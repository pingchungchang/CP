#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> v1(c,0);
    vector<int> v2 = v1;
    vector<int> v3=v1;
    for(int i = 0;i<c;i+=a){
        v1[i] = 1;
    }
    for(int i = 0;i<c;i+=b){
        v2[i] = 1;
    }
    for(int i = 0;i<c;i++){
        for(int j = 0;j<c-i;j++){
            v3[i+j] += v1[i]*v2[j];
        }
    }
    for(int i = 0;i<c;i++){
        cout<<v3[i]<<' ';
    }
}
