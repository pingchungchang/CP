#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,head,k;
    cin>>N>>head;
    vector<vector<int>> v(N,vector<int>(N,0));
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            cin>>k;
            v[i][j] = k;
        }
    }
    vector<vector<int>> way = {{0,-1},{-1,0},{0,1},{1,0}};
    vector<int> position = {N/2,N/2};
    cout<<v[position[0]][position[1]];
    for(int i =1;i<N;i++){
        for(int j =0;j<2;j++){
            for(int l = 0;l<i;l++){
                position[0] +=way[head][0];
                position[1] +=way[head][1];
                cout<<v[position[0]][position[1]];
            }
            head = (head+1)%4;
        }
    }
    for(int i =0;i<N-1;i++){
        position[0] +=way[head][0];
        position[1] +=way[head][1];
        cout<<v[position[0]][position[1]];
    }
    cout<<"\n";

}
