#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a;
    cin>>a;
    vector<int> dolls;
    for(int i = 0;i<a;i++){
        int k;
        cin>>k;
        dolls.push_back(k);
    }
    int ans = 0;
    sort(dolls.begin(),dolls.end());
    for(int i = 0;i<dolls.size();i+=2){
        ans += dolls[i+1]-dolls[i];
    }
    cout<<ans;
    return 0;
}
