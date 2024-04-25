#include <bits/stdc++.h>
using namespace std;
void build(vector<pair<int,int>> &range,vector<int> &points,vector<pair<int,int>> &segtree,int s,int e,int now){
    if(s == e){
        segtree[now] = make_pair(points[s],points[s]);
        range[now] = make_pair(s,e);
    }
    else{
        build(range,points,segtree,s,(s+e)/2,2*now+1);
        build(range,points,segtree,(s+e)/2+1,e,2*now+2);
        segtree[now] = make_pair(min(segtree[2*now+1].first,segtree[2*now+2].first),max(segtree[2*now+1].second,segtree[2*now+2].second));
        range[now] = make_pair(s,e);
    }
}
pair<int,int> finding(vector<pair<int,int>> &range,vector<int> &points,vector<pair<int,int>> &segtree,int s,int e,int now){
  //  printf("%d %d\n",s,e);
    if(s <= range[now].first&&e>=range[now].second) return segtree[now];
    else if(s>(range[now].first+range[now].second)/2){
        return finding(range,points,segtree,s,e,2*now+2);
    }
    else if(e<=(range[now].first+range[now].second)/2){
        return finding(range,points,segtree,s,e,2*now+1);
    }
    else{
        pair<int,int> lefthalf = finding(range,points,segtree,s,range[2*now+1].second,2*now+1);
        pair<int,int> righthalf = finding(range,points,segtree,range[2*now+2].first,e,2*now+2);
        return make_pair(min(lefthalf.first,righthalf.first),max(lefthalf.second,righthalf.second));
    }
}
int main(){
    int n,m;
    scanf("%d %d\n",&n,&m);
    vector<int> points(n,0);
    for(int i = 0;i<n;i++){
        int k;
        scanf("%d\n",&k);
        points[i] = k;
    }
    vector<pair<int,int>> range(4*n);
    vector<pair<int,int>> segtree(4*n);
    build(range,points,segtree,0,n-1,0);
    for(int i = 0;i<m;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        pair<int,int> dif = finding(range,points,segtree,s-1,e-1,0);
        //printf("%d %d ",dif.first,dif.second);
        printf("%d",dif.second-dif.first);
        if(i != m-1) printf("\n");
        if(i != m-1)scanf("\n");
    }
}