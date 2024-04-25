#include <stdio.h>

#include "nice_lines.h"

void solve(int subtask_id, int N) {
    printf("subtask_id = %d, N = %d\n", subtask_id, N);
    printf("query(0, 0) = %Lf\n", query(0, 0));
    printf("query(1, 1) = %Lf\n", query(1, 1));
    the_lines_are({1}, {0});
}
