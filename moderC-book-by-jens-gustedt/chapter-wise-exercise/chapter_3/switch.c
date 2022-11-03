# include <stdlib.h>
# include <stdio.h>

int main(int argv, char* argc[argv+1]){
  printf("Starting Switch Statements\n");

  for (int i=1; i<argv; i++){
    int a = atoi(argc[i]);
    switch (a){
      case 1:
        printf("Case 1\n");
      case 2:
        printf("Case 2\n");
      case 3:
        printf("Case 3\n");
      case 4:
        printf("Case 4\n");
      case 5:
        printf("Case 5\n");
      case 6:
        printf("Case 6\n");
      case 7:
        printf("Case 7\n");
      case 8:
        printf("Case 8\n");
      case 9:
        printf("Case 9\n");
      case 10:
        printf("Case 10\n");
      default:
        printf("Default Case\n");
    }
  }

  return EXIT_SUCCESS;
}

/*
Note: Why break statement is important in switch statements.
If you don't use break statement in switch statements then it will execute all the cases after the matched case.

Sample Output
> ./switch 1 23
Starting Switch Statements
Case 1
Case 2
Case 3
Case 4
Case 5
Case 6
Case 7
Case 8
Case 9
Case 10
Default Case
Default Case
> ./switch 5 23
Starting Switch Statements
Case 5
Case 6
Case 7
Case 8
Case 9
Case 10
Default Case
Default Case
*/
