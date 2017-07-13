#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void playersInfo();
void displayGrid();
int gameLoop();
int gameUmpire(int, int);
int whoWho();
   char player1[30];
   char player2[30];
   char grid[7][7];


   int rows=6,countR[7]={0};
   int cols=0,countC[7]={0};
   int moves=0;

int main(){


   int i,j,result;

   initializer();

   playersInfo();
   system("cls");
   displayGrid();

   result=gameLoop();

   if(result==1)
    printf(" %s  won the game  ",player1);
   else printf(" %s  won the game  ",player2);
   return 0;

}

void initializer(){

  int i,j;
  system("cls");
  for(i=0;i<7;i++){
    for(j=0;j<7;j++){
        grid[i][j]='0';
        printf("    %c ",grid[i][j]);
    }
    printf("\n\n");
  }

}


void playersInfo(){

   printf("enter player1 name: ");
   scanf("%s",player1);
   printf("enter player2 name: ");
   scanf("%s",player2);

}


void displayGrid(){

  int i,j;
  system("cls");
  for(i=0;i<7;i++){
    for(j=0;j<7;j++){

        printf("    %c ",grid[i][j]);
    }
    printf("\n\n");
  }

}
int gameLoop(){

   int n;

     a: printf("%s enter your move: ",player1);
      scanf("%d",&n);
       if(n<1||n>7){
        printf("invalid move\n");
        goto a;
      }
      if(countR[rows]==8)rows--;
      if(countR[rows]<=8){
        if(countC[n-1]>6){
            printf("invalid move\n");
            goto a;
        }
      }

      if(gameUmpire(n ,1)) return 1;


     b: printf("%s enter your move: ",player2);
      scanf("%d",&n);
      if(n<1||n>7){
        printf("invalid move\n");
        goto b;
      }
      if(countR[rows]==8)rows--;
       if(countR[rows]<=8){
        if(countC[n-1]>6){
            printf("invalid move\n");
            goto b;
        }
      }
      if(gameUmpire(n ,2)) return 2;

      gameLoop();
}

int gameUmpire(int n, int a){
    moves++;
   char connect;


   if(a==1) connect='X';
   else connect='#';


      if(grid[rows][n-1]=='0'){

          grid[rows][n-1]=connect;
          countR[rows]+=1;
          countC[n-1]+=1;

      }

      else{

         grid[rows-countC[n-1]][n-1]=connect;
         countR[rows-countC[n-1]]+=1;
         countC[n-1]+=1;
      }




  displayGrid();
  //remove down line after game project completes

  return whoWon( rows-countC[n-1], n-1);


}

int whoWon(int row, int col){
    int i,j,k,x,y,z;
    int count=1;
  for(k=0;k<=6;k++){
    for(i=1,j=0;i<=6;i++){
        if(grid[k][i]==grid[k][j]&&grid[k][i]!='0'&&grid[k][j]!='0'){
            count++;
            if(count==4) return 1;
        }
        else{
            count=1;
            j=i;
        }

    }
    count=1;
    for(i=1,j=0;i<=6;i++){
        if(grid[i][k]==grid[j][k]&&grid[i][k]!='0'&&grid[j][k]!='0'){
            count++;
            if(count==4) return 1;
        }
        else{
            count=1;
            j=i;
        }
    }
    count=1;

    for(i=k+1,j=k;i<=6;){
        if(grid[j-k][j]==grid[i-k][i]&&grid[j-k][j]!='0'&&grid[j-k][j]!='0'){
            count++;
            if(count==4) return 1;
            i++;
        }
        else{
            count==1;
            j=i;
            i++;
        }
    }
     count=1;
    for(i=k+1,j=k;i<=6;){
        if(grid[j][j-k]==grid[i][i-k]&&grid[j][j-k]!='0'&&grid[i][i-k]!='0'){
            count++;
            if(count==4) return 1;
            i++;
        }
        else{
            count==1;
            j=i;
            i++;
        }
    }
    count=1;
  }
  count=1;
  for(k=0;k<=6;k++){
    for(j=k,i=j+1,x=6,y=6;i<=6;){
        if(grid[j][y]==grid[i][x-1]&&grid[j][y]!='0'&&grid[i][x-1]!='0'){
            count++;
            if(count==4) return 1;
                x--;
                i++;
        }
        else{
            j=i;
            i++;
            --x;
            y=x;
            count=1;
        }
     }
  }
     count=1;
   for(k=0;k<=6;k++){
     for(j=0,i=j+1,x=6-k,y=6-k;i<=6-k;){
        if(grid[y][j]==grid[x-1][i]&&grid[y][j]!='0'&&grid[x-1][i]!='0'){
            count++;
            if(count==4) return 1;
                x--;
                i++;
        }
        else{
            j=i;
            i++;
            --x;
            y=x;
            count=1;
        }
     }
  }

  return 0;
}
