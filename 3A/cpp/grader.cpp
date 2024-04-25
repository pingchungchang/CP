#include <cstdio>
#include <string>
#include <utility>
#include <vector>

const int MAX_LENGTH = 1048576;

// Functions to be implemented in the solution.
std::pair<int, std::vector<std::string>> count_and_partition(const std::string& S, int K);

int main() {
  int n_case;
  char tmp[MAX_LENGTH];
  scanf("%d", &n_case);
  for (int i = 0; i < n_case; ++i) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", tmp);
    auto result = count_and_partition(std::string(tmp), k);
    printf("%d %lu\n", result.first, result.second.size());
    for (const auto& y : result.second) {
        printf("%s\n", y.c_str());
    }
  }
  return 0;
}
