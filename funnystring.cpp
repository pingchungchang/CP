#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N;i++){
        vector<int> v;
        string s;
        bool funny = true;
        cin >> s;
        for (int i = 1; i < s.size();i++){
            v.push_back(s[i-1] - s[i]);
        }
        for (int i = 0; i < v.size() / 2;i++){
            if(v[i] !=v[v.size()-1-i]&&v[i]!=0-v[v.size()-1-i]) funny = false;
        }
        if(funny) cout<<"Funny"<<endl;
        else cout<<"Not Funny"<<endl;
    }
}