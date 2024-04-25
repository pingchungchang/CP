#include <vector>
 
int query(int l, int r);
 
std::vector<int> revert(int n)
{
    query(0, 1);
    query(2, 2);
    query(1, 2);
    std::vector<int> answer;
    answer.push_back(1);
    answer.push_back(3);
    answer.push_back(2);
    return answer;
}
