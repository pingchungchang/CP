#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    string a;
    string b;
    string k;
    getline(cin,k);
    int n = k[0]-'0';
    for(int i = 0;i<n;i++){
        getline(cin,a);
        getline(cin,b);
        int done = 0;
        queue<char>q1;
        queue<char> q2;
        for(int i = 0;i<a.size();i++){
            q1.push(a[i]);
        }
        for(int i = 0;i<b.size();i++){
            q2.push(b[i]);
        }
        cout<<"Case "<<i+1<<": ";
        while(!q1.empty()&&!q2.empty()){
            if(q1.front() == ' ')q1.pop();
            else if(q2.front() == ' ')q2.pop();
            else if(q1.front() == q2.front()){
                q1.pop();
                q2.pop();
            }
            else break;
        }
        while(!q1.empty()){
            if(q1.front() != ' ') cout<<"Wrong Answer";
            if(i != n-1) cout<<"\n";
            done = 1;
            break;
        }
        if(done == 1)continue;
        while(!q2.empty()){
            if(q2.front() != ' ') cout<<"Wrong Answer";
            if(i != n-1) cout<<"\n";
            done = 1;
            break;
        }
        if(done)continue;
        if(a != b&&!done){
            cout<<"Output Format Error";
            if(i != n-1) cout<<"\n";
        }
        else if(!done){
            cout<<"Yes";
            if(i != n-1) cout<<"\n";
        }
    }
}
