#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    char n;
    string m;
    while(cin>>n>>m){
        if(m.size() == 1&&m[0] == '0'&&n == '0') return 0;
        string ans;
        for(int i = 0;i<m.size();i++){
            if(m[i] != n){
                ans += m[i];
            }
        }
        if(ans.size() == 0){
            cout<<0<<endl;
            continue;
        }
        int start = 0;
        string realans;
        while(ans[start] == '0'){
            if(start == ans.size()-1) break;
            start ++;
        }
        for(int i = start;i<ans.size();i++){
            realans += ans[i];
        }
        if(realans.size() == 0)  cout<<0<<endl;
        else cout<<realans<<endl;
    }
}
