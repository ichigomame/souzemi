#include<stdio.h>
void ban(void);
void saki(void);
void ato(void);
int masu[12][12];
int hi[12];
int i,j,n,k,c,w=0;

int main(void){
  for(i=0;i<12;i++){
    for(j=0;j<12;j++){
      masu[i][j]=0;
    }
  }
  for(i=0;i<12;i++){
    hi[i]=11;
  }

  while(1){
    printf("XorO?  ");
    scanf("%s",&k);
    if(k=='X'){
      ban();
      saki();
      return(0);
    }else if(k=='O'){
      ban();
      ato();
      return(0);
    }else{
      printf("error! XorO!\n");
    }
  }
  return(0);
}

void ban(void){
  for(i=0;i<12;i++){
    for(j=0;j<12;j++){
      if(masu[i][j]==0)
	printf(" .");
      if(masu[i][j]==1)
	printf(" X");
      if(masu[i][j]==2)
	printf(" O");
    }
    printf("\n");
  }
  printf(" 0 1 2 3 4 5 6 7 8 9 A B\n");
  return;
}
void saki(void){
  for(j=0;j<=11;j++){
    for(i=11;0<=i;i--){
      if(masu[i][j]==0){
	hi[j]=i+1;
      }
    }
  }
  for(i=0;i<12;i++){
    for(n=0;n<12;n++){
      if(masu[hi[i]][n]==2&&masu[hi[i]+1][n-1]==2&&masu[hi[i]+2][n-2]==2){//左下
	if(masu[hi[i]-1][n+1]==0)
	printf("%d  ",masu[hi[i]-1][n+1]);
	if(masu[hi[i]+3][n-3]==0)
	printf("%d  ",masu[hi[i]+3][n-3]);
	break;
      }else if(masu[hi[i]][n]==2&&masu[hi[i]+1][n]==2&&masu[hi[i]+2][n]==2){//下
	if(masu[hi[i]-1][n]==0)
	printf("%d  ",masu[hi[i]-1][n]);
	break;
      }else if(masu[hi[i]][n]==2&&masu[hi[i]+1][n+1]==2&&masu[hi[i]+2][n+2]==2){//右下
	if(masu[hi[i]-1][n-1]==0)
	printf("%d  ",masu[hi[i]-1][n-1]);
	if(masu[hi[i]+3][n+3]==0)
	printf("%d  ",masu[hi[i]+3][n+3]);
	break;
      }else if(masu[hi[i]][n]==2&&masu[hi[i]][n+1]==2&&masu[hi[i]][n+2]==2){//横
	if(masu[hi[i]][n-1]==0)
	printf("%d  ",masu[hi[i]][n-1]);
	if(masu[hi[i]][n+3]==0)
	  printf("%d  ",masu[hi[i]][n+3]);
	break;
      }else{
	printf("none");
	c++;
	break;
      }
    }
    if(c==1)
      break;
  }
  printf("\n");
  return;
}

void ato(void){
  for(j=0;j<=11;j++){
    for(i=11;0<=i;i--){
      if(masu[i][j]==0){
	hi[j]=i+1;
      }
    }
  }
  for(i=0;i<12;i++){
    for(n=0;n<12;n++){
      if(masu[hi[i]][n]==1&&masu[hi[i]+1][n-1]==1&&masu[hi[i]+2][n-2]==1){//左下
	if(masu[hi[i]-1][n+1]==0)
	printf("%d  ",masu[hi[i]-1][n+1]);
	if(masu[hi[i]+3][n-3]==0)
	printf("%d  ",masu[hi[i]+3][n-3]);
	break;
      }else if(masu[hi[i]][n]==1&&masu[hi[i]+1][n]==1&&masu[hi[i]+2][n]==1){//下
	if(masu[hi[i]-1][n]==0)
	printf("%d  ",masu[hi[i]-1][n]);
        break;
      }else if(masu[hi[i]][n]==1&&masu[hi[i]+1][n+1]==1&&masu[hi[i]+2][n+2]==1){//右下
	if(masu[hi[i]-1][n-1]==0)
	  printf("%d  ",masu[hi[i]-1][n-1]);
	if(masu[hi[i]+3][n+3]==0)
	  printf("%d  ",masu[hi[i]+3][n+3]);
	break;
      }else if(masu[hi[i]][n]==1&&masu[hi[i]][n+1]==1&&masu[hi[i]][n+2]==1){//横
	if(masu[hi[i]][n-1]==0)
	  printf("%d  ",masu[hi[i]][n-1]);
	if(masu[hi[i]][n+3]==0)
	  printf("%d  ",masu[hi[i]][n+3]);
	break;
      }else{
	printf("none");
	c++;
	break;
      }
    }
    if(c==1)
      break;
  }
  printf("\n");
  return;
}
