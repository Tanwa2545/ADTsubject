#include <stdio.h>

int traverseMaze(int n, char **maze, int i, int j) {
  if (i>=n || j>=n || i<0 || j<0)
    return 0;
  if (maze[i][j]=='#')
    return 0;
  if (maze[i][j]=='G')
    return 1;
  if (maze[i][j]==' ' || maze[i][j]=='S'){
    maze[i][j]='.';
    if (traverseMaze(n,maze,i+1,j) || traverseMaze(n,maze,i,j+1) || traverseMaze(n,maze,i-1,j) || traverseMaze(n,maze,i,j-1)){
      return 1;
    }
    maze[i][j]=' ';
  }
  return 0;
}

int main(void) {
  int i,j,n,si,sj;
  char **maze;
  scanf("%d",&n);
  getchar();
  maze = (char **)malloc(sizeof(char *)*n);
  for(i=0;i<n;i++){
    char rows[200];
    fgets(rows,sizeof(rows),stdin);
    rows[strcspn(rows, "\n")] = '\0';
    maze[i] = (char *)malloc(sizeof(char)*n);
    strcpy(maze[i],rows);
  }
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      if (maze[i][j]=='S'){
        si=i;
        sj=j;
      }
    }
  }
  traverseMaze(n,maze,si,sj);
  maze[si][sj]='S';
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      printf("%c",maze[i][j]);
    }
    printf("\n");
  }
  return 0;
}
/*
############
#   #      #
S # # #### #
### #    # #
#    ### # G
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
############
*/