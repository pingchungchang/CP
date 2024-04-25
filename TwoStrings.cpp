#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i =0;i<N;i++){
        string a;
        string b;
        cin>>a>>b;
        int ans = 0;
        unordered_map<char,int> map;
        for(int i =0;i<a.size();i++){
            map[a[i]] = 1;
        }
        for(int i =0;i<b.size();i++){
            if(map.count(b[i]) !=0){
                ans = 1;
            }
        }
        if(ans)cout<<"YES";
        else cout<<"NO";

    }
}
