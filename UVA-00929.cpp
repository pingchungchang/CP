#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int x;
    int y;
    int value;
}node;
class Compare{
public:
    bool operator()(node a,node b){
        return a.value>b.value;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int asd=0;asd<t;asd++){
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        priority_queue<node,vector<node>,Compare> pq;
        node s;
        s.x = 0;
        s.y = 0;
        s.value = arr[0][0];
        int beento[n][m];
        memset(beento,0,n*m*sizeof(int));
        /*for(int i =0;i<n;i++){
            for(int j =0;j<m;j++)cout<<beento[i][j]<<' ';
            cout<<endl;
        }*/
        beento[0][0] = -1;
        pq.push(s);
        while(!pq.empty()){
            node now = pq.top();
            //cout<<now.x<<' '<<now.y<<' '<<now.value<<'\n';
            pq.pop();
            if(now.x>0&&beento[now.x-1][now.y] == 0){
                node l;
                l.y = now.y;
                l.x = now.x-1;
                l.value=now.value+ arr[now.x-1][now.y];
                if(l.value!=0)beento[l.x][l.y] = l.value;
                else beento[l.x][l.y] = -1;
                pq.push(l);
            }
            if(now.x<n-1&&beento[now.x+1][now.y] == 0){
                node r;
                r.x = now.x+1;
                r.y = now.y;
                r.value =now.value+ arr[now.x+1][now.y];
                if(r.value !=0)beento[r.x][r.y] = r.value;
                else beento[r.x][r.y] = -1;
                pq.push(r);
            }
            if(now.y>0&&beento[now.x][now.y-1]==0){
                node up;
                up.x = now.x;
                up.y = now.y-1;
                up.value =now.value+ arr[now.x][now.y-1];
                if(up.value !=0)beento[up.x][up.y] = up.value;
                else beento[up.x][up.y] = -1;
                pq.push(up);
            }
            if(now.y<m-1&&beento[now.x][now.y+1]==0){
                node down;
                down.x = now.x;
                down.y = now.y+1;
                down.value =now.value+ arr[now.x][down.y];
                if(down.value !=0)beento[down.x][down.y] = down.value;
                else beento[down.x][down.y] = -1;
                pq.push(down);
            }
            if(beento[n-1][m-1]!=0)break;
        }
        if(n==1&&m==1)cout<<arr[0][0];
        else if(beento[n-1][m-1] == -1)cout<<0;
        else cout<<beento[n-1][m-1];
        if(asd!= t-1)cout<<'\n';
    }
}
