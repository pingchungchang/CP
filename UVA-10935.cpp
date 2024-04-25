#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main(){
    int k;
    int j = 0;
    vector<vector<int>> op;
    while(cin>>k){
        if(k==0) break;
        queue<int> cards;
        // vector<int> ans;
        for (int i = 1; i <= k;i++){
            cards.push(i);
        }
        op.push_back({});        
        while(cards.empty()==false){
            // cout << k;
            op[j].push_back(cards.front());
            cards.pop();
            if(cards.empty()==true) break;
            cards.push(cards.front());
            cards.pop();
        }
        j += 1;
    }
    for (int i = 0; i < op.size();i++){
        // cout << i << op[i].size();
        cout << "Discarded cards:";
        if(op[i].size()!=1) cout << ' ';
        for (int w = 0; w < op[i].size()-2;w++){
            if(op[i].size()==1){
                cout << endl;
                break;
            } 
            cout << op[i][w] << ", ";
        }
        if(op[i].size()!=1) cout<<op[i][op[i].size()-2]<<endl;
        cout << "Remaining card: " << op[i][op[i].size() - 1] << endl;
    }
}
// 問題:資料無法輸出