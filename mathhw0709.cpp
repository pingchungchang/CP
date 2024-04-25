#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ans;
    unordered_map<int,int> UsedorNot;
    for(int i = 1;i<=n;i++){
        UsedorNot[i] = 1;
        if(i%2 == 0) UsedorNot[i/2] = 0;
    }
    for(int i = 1;i<=n;i++){
        if(UsedorNot[i] == 1) ans.push_back(i);
    }
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}
