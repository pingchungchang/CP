#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class point{
    public:
        point *next;
        point *before;
        int value;
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    point* l;
    l->value = 1;
    point *begin = l;
    for (int i = 2; i <= n;i++){
        point* f;
        f->value = i;
        f->before = l;
        l->next = f;
        l = l->next;
    }
    l->next = begin;
    begin->before = l;
    point *variety = begin;
    for (int i = 0; i < k;i++){
        for (int j = 0; j < m - 1;j++){
            variety = variety->next;
        }
        variety->before->next = variety->next;
        variety->next->before = variety->before;
        variety = variety->next;
    }
    cout << variety->value<<'1';
}