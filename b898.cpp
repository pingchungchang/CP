#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(string a,string b){
        if(a.size()!=b.size()){
            return a.size()<b.size();
        }
        int j = 0;
        while(a[j] == b[j]) j++;
        return a[j]<b[j];
    }
};
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string a,b,c;
        cin>>a>>b>>c;
        priority_queue<string,vector<string>,Compare> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        cout<<pq.top()<<endl;
    }
}
