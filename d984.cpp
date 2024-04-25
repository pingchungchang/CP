#include <bits/stdc++.h>
using namespace std;
class Compare{
    public:
    bool operator()(pair<long long,char> a,pair<long long,char> b){
        return a.first>b.first;
    }
};
int main(){
    char arr[3] = {'A','B','C'};
    long long votes[3] = {0};
    while(cin>>votes[0]>>votes[1]>>votes[2]){
        priority_queue<pair<long long,char>,vector<pair<long long,char>>,Compare> pq;
        for(long long i = 0;i<3;i++){
            pq.push(make_pair(votes[i],arr[i]));
        }
        pair<long long,char> smallers = pq.top();
        pq.pop();
        smallers.first += pq.top().first;
        smallers.second = pq.top().second;
        pq.pop();
        if(pq.top().first>smallers.first) printf("%c\n",pq.top().second);
        else printf("%c\n",smallers.second);
        pq.pop();
    }
}