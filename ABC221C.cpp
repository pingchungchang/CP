#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    priority_queue<char,vector<char>,less<char>> pq;
    for(int i =0;i<s.size();i++)pq.push(s[i]);
    string a;
    string b;
    while(!pq.empty()){
        char x = pq.top();
        pq.pop();
        if(pq.empty()){
            if(stoi(a+x)*stoi(b)>stoi(b+x)*stoi(a))a += x;
            else b += x;
        }
        else{
            char y = pq.top();
            pq.pop();
            if(stoi(a+y)*stoi(b+x)>stoi(a+x)*stoi(b+y)){
                a += y;
                b += x;
            }
            else{
                a += x;
                b += y;
            }
        }
    }
    cout<<stoi(a)*stoi(b);
}
