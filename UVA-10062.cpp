#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> m;
class Compare{
public:
    bool operator()(char a,char b){
        if(m[a] == m[b]){
            return a<b;
        }
        return m[a]>m[b];
    }
};
int main(){
    string s;
    while(getline(cin,s)){
        priority_queue<char,vector<char>,Compare> pq;
        for(int i =0 ;i<s.size();i++){
            if(m.count(s[i]) == 0){
                m[s[i]] = 0;
                pq.push(s[i]);
            }
            else if(m[s[i]] == 0)pq.push(s[i]); 
            m[s[i]]++;
        }
        priority_queue<char,vector<char>,Compare> pq2;
        while(!pq.empty()){
            pq2.push(pq.top());
            pq.pop();
        }
        while(!pq2.empty()){
            printf("%d %d\n",(int)pq2.top(),m[pq2.top()]);
            m[pq2.top()]=0;
            pq2.pop();
        }
        printf("\n");
    }
}