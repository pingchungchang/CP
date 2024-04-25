#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    while(cin>>a>>b){
        int as = a.size();
        int bs = b.size();
        int x = max(as,bs);
        int y = min(as,bs);
        while(y!=0){
            x-=(x/y)*y;
            int buf = x;
            x = y;
            y = buf;
        }
        int done = 1;
        for(int i = x;i>=0;i--){
            string s1 = a.substr(0,x);
            string s2 = b.substr(0,x);
            for(int j = 0;j<as;j+=x){
                if(a.substr(j,x) != s1){
                    done = 0;
                    break;
                }
            }
            for(int j =0;j<bs;j+=x){
                if(b.substr(j,x)!= s2){
                    done = 0;
                    break;
                }
            }
            if(done == 1&&s1==s2){
                cout<<s1<<'\n';
                break;
            }
            else done = 0;
        }
        if(done == 0)cout<<"= =\n";
    }
}