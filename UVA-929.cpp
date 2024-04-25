#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Compare{
public:
    bool operator()(vector<int> a,vector<int> b){
        return a[2]>b[2];
    }
};
int main(){
    int n;
    cin>>n;
    for(int p = 0;p<n;p++){
        int row,column;
        cin>>row>>column;
        vector<vector<int>> graph(row,vector<int>(column,0));
        for(int i = 0;i<row;i++){
            for(int j = 0;j<column;j++){
                int a;
                cin>>a;
                graph[i][j] = a;
            }
        }
        vector<vector<int>> distance(row,vector<int>(column,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        pq.push({0,0,graph[0][0]});
        while(!pq.empty()){
            vector<int> now = pq.top();
            pq.pop();
            int r = now[0];
            int c = now[1];
            int value = now[2];
            if(distance[row-1][column-1] != INT_MAX) break;
            if(distance[r][c] == INT_MAX){
                distance[r][c] = value;
                if(r != 0&&distance[r-1][c] == INT_MAX)pq.push({r-1,c,value+graph[r-1][c]});
                if(r != row-1&& distance[r+1][c] == INT_MAX)pq.push({r+1,c,value+graph[r+1][c]});
                if(c != 0&&distance[r][c-1] == INT_MAX)pq.push({r,c-1,value+graph[r][c-1]});
                if(c != column-1&& distance[r][c+1] == INT_MAX)pq.push({r,c+1,value+graph[r][c+1]});
            }
        }
        cout<<distance[row-1][column-1]<<"\n";
    }
}
