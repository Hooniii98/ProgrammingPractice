#include <stdio.h>

int get_answer (void) {
  int c;
  int answer = 0;
  while ((c = getchar ()) != EOF && c != '\n') {
      //this loop makes "getchar()" to fetch characeters from the stdin buffer until it reaches EOF or '\n'
      //this totally clears and empties the stdin buffer
      if (answer == 0 && (c == 'y' || c == 'n')) {
        //if c hasn't fetched either 'y' or 'n' yet and the character fetched from the buffer is either 'y' or 'n', then stores the character into "answer"
        answer = c;
      }
  }

  return answer;
}

int main (void) {
  int F, C;
  char line[4096];

  printf ("Do you have a Fever? y/n\n");
  F = get_answer ();

  printf ("Do you have a runny nose or cough? y/n\n");
  C = get_answer ();


  printf ("Here are the results you input:\n");
  printf ("Do you have a fever? %c\n", F);
  printf ("Do you have a runny nose or cough? %c\n", C);

  return 0;
}
