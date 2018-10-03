Maze

1. 程式執行環境 : Win8.1
2. 程式語言 : C

<main>

1.typedef struct{
	short int vert;
	short int horiz;
  }offsets;
   offsets move[8] => 存每種移動方向的陣列

2.typedef struct{
	short int vert;
	short int col;
	short int dir;
  }element;
   element position;
   element stack[s]; => 存各點的位置資訊

3.老鼠可拜訪每一個位置至多一次
  => 堆疊大小只需要與迷宮中位置為0的個數相等即可
  => s為迷宮中0的個數(s初始值為2是包含s和d)

4.陣列mark紀錄迷宮中已經確認過的位置(初始值為0，走過後值設定為1)

5.while(top>-1 && !found) =>有堆疊而且沒找到出口 (top=-1為堆疊頂端)
  if(nextRow==destination_row && nextCol==destination_col) => 找到出口
  else if((maze[nextRow][nextCol]-'0')!=1 && mark[nextRow][nextCol]!=1) => 有可以走且是沒走過的路
  
6.maze[stack[t].row][stack[t].col]='*' => 將走過的路用*標記