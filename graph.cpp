#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
class edge{
public:
    int value;
    vector<int> paths;
    vector<int> weights;
};
class Compare{
public:
    bool operator()(pair<edge*,int> e1,pair<edge*,int> e2){
        return e1.second<e2.second;
    }
};
int main(){
    int maximum = 99999999;
    int n,l;
    cin>>n>>l;
    unordered_map<int,edge*> m;
    for(int i = 0;i<n;i++){
        //edge* x = new edge;//pointer issue
        edge* w =new edge;
        w->value = maximum;
        m[i] = w;
        cout<<w<<' ';
    }
    for(int i = 0;i<l;i++){
        int a,b,c;
        cin>>a>>b>>c;
        m[a]->paths.push_back(b);
        m[a]->weights.push_back(c);
        m[b]->paths.push_back(a);
        m[b]->weights.push_back(c);
    }
    int s,e;
    cin>>s>>e;
    priority_queue<pair<edge*,int>, vector<pair<edge*,int>>,Compare> pq;
    pq.push(make_pair(m[s],0));
    while(!pq.empty()){
        pair<edge*,int> k = pq.top();
        pq.pop();
        if(k.first->value>= maximum){
            k.first->value = k.second;
            for(int i = 0;i<k.first->paths.size();i++){
                pq.push(make_pair(m[k.first->paths[i]],k.first->value+k.first->weights[i]));
            }
        }
    }
    cout<<m[e]->value;
    return 0;
}
