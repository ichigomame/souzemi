#include<stdio.h>
void ban(void);
void saki(void);
void ato(void);
int win();
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

  ban();
  while(1){
    saki();
    ban();
    win();
    printf("%d\n",w);
    if(w==1){
      printf("X Win!\n");
      return(0);
    }
    c++;
    ato();
    ban();
    win();
    printf("%d\n",w);
    if(w==2){
      printf("O Win!\n");
      return(0);
    }
    c++;
    if(c==20)
    break;
  }
  printf("ひきわけ～\n");
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
  while(1){
    printf("X?  ");
    scanf("%x",&k);
    if(0<=k&&k<12){
      for(i=11;0<=i;i--){
	if(masu[i][k]==0){
	  masu[i][k]=1;
	  hi[k]--;
	  printf("\n");
	  return;
	}
      }
      printf("error! full!\n");
    }else
      printf("error! 0~B!\n");
  }
}

void ato(void){
  while(1){
    printf("O?  ");
    scanf("%x",&k);
    if(0<=k&&k<12){
      for(i=11;0<=i;i--){
	if(masu[i][k]==0){
	  masu[i][k]=2;
	  hi[k]--;
	  printf("\n");
	  return;
	}
      }
      printf("error! full!\n");
    }else
      printf("error! 0~B!\n");
  }
}

int win(){
  for(i=0;i<12;i++){
    for(n=0;n<12;n++){
      if(masu[hi[i]][n]==1&&masu[hi[i]+1][n-1]==1&&masu[hi[i]+2][n-2]==1&&masu[hi[i]+3][n-3]==1){//左下
	w++;
	break;
      }else if(masu[hi[i]][n]==1&&masu[hi[i]+1][n]==1&&masu[hi[i]+2][n]==1&&masu[hi[i]+3][n]==1){//下
	w++;
        break;
      }else if(masu[hi[i]][n]==1&&masu[hi[i]+1][n+1]==1&&masu[hi[i]+2][n+2]==1&&masu[hi[i]+3][n+3]==1){//右下
	w++;
	break;
      }else if(masu[hi[i]][n]==1&&masu[hi[i]][n+1]==1&&masu[hi[i]][n+2]==1&&masu[hi[i]][n+3]==1){//横
	w++;
	break;
      }else if(masu[hi[i]][n]==2&&masu[hi[i]+1][n-1]==2&&masu[hi[i]+2][n-2]==2&&masu[hi[i]+3][n-3]==2){//左下
	w+=2;
	break;
      }else if(masu[hi[i]][n]==2&&masu[hi[i]+1][n]==2&&masu[hi[i]+2][n]==2&&masu[hi[i]+3][n]==2){//下
	w+=2;
	break;
      }else if(masu[hi[i]][n]==2&&masu[hi[i]+1][n+1]==2&&masu[hi[i]+2][n+2]==2&&masu[hi[i]+3][n+3]==2){//右下
	w+=2;
	break;
      }else if(masu[hi[i]][n]==2&&masu[hi[i]][n+1]==2&&masu[hi[i]][n+2]==2&&masu[hi[i]][n+3]==2){//横
	w+=2;
	break;
      }
    }
    if(w==1||w==2)
      break;
  }
  return(0);
}
