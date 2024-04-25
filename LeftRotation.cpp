#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> v;
    for(int i =0;i<N;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<v[M%N];
    for(int i =M+1;i<M+N;i++){
        cout<<' '<<v[(M+1)%N];
    }
}
