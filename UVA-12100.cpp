#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class paper{
    public:
        int value;
        int id;
};
int main(){
    int N;
    cin >> N;
    vector<int> ans;
    for (int i = 0; i < N;i++){
        int length;
        int target;
        int time = 0;
        cin >> length >> target;
        queue<paper> q;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int j = 0; j < length;j++){
            int k;
            cin >> k;
            paper a;
            a.value = k;
            a.id = j;
            pq.push(k);
            q.push(a);
        }
        while(true){
            if(q.front().value == pq.top()){
                if(q.front().id == target){
                    time ++;
                    ans.push_back(time);
                    break;
                }
                else{
                    time++;
                    q.pop();
                    pq.pop();
                }
            }
            else{
                paper a = q.front();
                q.pop();
                q.push(a);
            }
        }
    }
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << endl;
    }
}