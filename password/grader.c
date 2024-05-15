/**
 * Sample grader for contestants' use.
 *
 * Usage: place your input data in the file password.in in the format
 *
 * line 1: N S
 * line 2: hidden_password
 *
 * Then compile this grader together with your implementation.
 * Run the binary to see your guessing strategy at work!
 * Set DEBUG to 1 to print all queries.
 **/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEBUG 0
#define MAX_QUERIES 50000
#define MAX_N 5000
#define MAX_SIGMA 26

static char password[MAX_N + 1]; /* allow room for \0 */
static int n, s, numQueries;

static void end(int success, const char* format, ...) {
  va_list args;
  va_start(args, format);

  printf(success ? "SUCCESS! " : "ERROR: ");
  vprintf(format, args);
  printf("\n");

  exit(0);
}

int query(char* q) {
  if (++numQueries > MAX_QUERIES) {
    end(0, "Could not guess the password with %d questions.", MAX_QUERIES);
  }

  int len = strlen(q);

  /* validation */
  if (len < 1 || len > n) {
    end(0, "Query '%s' should have length between 1 and %d characters.", q, n);
  }

  for (int i = 0; i < len; i++) {
    if (q[i] < 'a' || q[i] >= 'a' + s) {
      end(0, "Illegal character '%c' found.", q[i]);
    }
  }

  /* while possible, advance one character in q and find its next */
  /* occurrence in password */
  char *p = password, *qSave = q;
  while (*p && *q) {
    while (*p && (*p != *q)) {
      p++;
    }
    if (*p) { /* found a match */
      p++;
      q++;
    }
  }

  if (DEBUG) {
    printf("Question #%d [%s] answer %ld\n", numQueries, qSave, q - qSave);
  }
  return q - qSave;
}

char* guess(int n, int s);

int main() {

  FILE *f = fopen("password.in", "r");
  assert(f);
  assert(fscanf(f, "%d %d %s", &n, &s, password) == 3);
  fclose(f);

  char* answer = guess(n, s);
  if (DEBUG) {
    printf("Your answer: [%s]\n", answer);
  }

  if (strcmp(answer, password)) {
    end(0, "Your answer was [%s] which does not match the password [%s].",
        answer, password);
  } else {
    end(1, "You guessed the password with %d queries.", numQueries);
  }

	return 0;
}
