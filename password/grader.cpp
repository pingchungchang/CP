// Sample grader for contestants' use.
//
// Usage: place your input data in the file password.in in the format
//
// line 1: N S
// line 2: hidden_password
//
// Then compile this grader together with your implementation.
// Run the binary to see your guessing strategy at work!
// Set DEBUG to 1 to print all queries.
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define DEBUG 1
#define MAX_QUERIES 50000
#define MAX_N 5000
#define MAX_SIGMA 26

static string password;
static int n, s, numQueries;
static stringstream msg;

static void end(int success) {
  cout << (success ? "SUCCESS! " : "ERROR: ") << msg.str() << endl;
  exit(0);
}

int query(string q) {
  if (++numQueries > MAX_QUERIES) {
    msg << "Could not guess the password with " << MAX_QUERIES << " questions.";
    end(0);
  }

  int len = q.size();

  // validation
  if (len < 1 || len > n) {
    msg << "Query '" << q << "' should have length between 1 and "
        << n << " characters.";
    end(0);
  }

  for (int i = 0; i < len; i++) {
    if (q[i] < 'a' || q[i] >= 'a' + s) {
      msg << "Illegal character '" << q[i] << "' found.";
      end(0);
    }
  }

  // while possible, advance one character in q and find its next
  // occurrence in password
  int i = 0, j = 0, plen = password.size();
  while (i < plen && j < len) {
    while ((i < plen) && (password[i] != q[j])) {
      i++;
    }
    if (i < plen) { /* found a match */
      i++;
      j++;
    }
  }

  if (DEBUG) {
    cout << "Question #" << numQueries << " [" << q << "] answer " << j << endl;
  }
  return j;
}

string guess(int n, int s);

int main() {

  ifstream f("password.in");
  f >> n >> s >> password;
  f.close();
  assert(n && s && !password.empty());

  string answer = guess(n, s);
  if (DEBUG) {
    cout << "Your answer: [" << answer << "]\n";
  }

  if (answer.compare(password)) {
    msg << "Your answer was [" << answer
        << "] which does not match the password [" << password << "].";
    end(0);
  } else {
    msg << "You guessed the password with " << numQueries << " queries.";
    end(1);
  }

	return 0;
}
