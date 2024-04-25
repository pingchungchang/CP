#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x = 2;
    unordered_map<int,int> m;
    vector<int> factors;
    while(x<=n){
        if(n%x == 0){
            if(m.count(x) == 0){
                factors.push_back(x);
                m[x] = 1;
            }
            else{
                m[x]++;
            }
            n/=x;
            x = 2;
        }
        else{
            x++;
        }
    }
    for(int i = 0;i<factors.size();i++){
        cout<<factors[i];
        if(m[factors[i]]>1){
            cout<<"^"<<m[factors[i]];
        }
        if(i != factors.size()-1){
            cout<<" * ";
        }
    }
}
