#include<iostream>
#include <vector>
using namespace std;
int recursive(vector<int> v){
    vector<int> vprum;
    if(v.size()==1) return v[0];
    else if(v.size()%2==1){
        for (int i = 2; i < v.size();i+=2){
            vprum.push_back(v[i]);
        }
    }
    else if(v.size()%2==0){
        for (int i = 0; i < v.size();i+=2){
            vprum.push_back(v[i]);
        }
    }
    return recursive(vprum);
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n;i++) v.push_back(i+1);
    cout << recursive(v);
}