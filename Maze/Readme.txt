Maze

1. �{���������� : Win8.1
2. �{���y�� : C

<main>

1.typedef struct{
	short int vert;
	short int horiz;
  }offsets;
   offsets move[8] => �s�C�ز��ʤ�V���}�C

2.typedef struct{
	short int vert;
	short int col;
	short int dir;
  }element;
   element position;
   element stack[s]; => �s�U�I����m��T

3.�ѹ��i���X�C�@�Ӧ�m�ܦh�@��
  => ���|�j�p�u�ݭn�P�g�c����m��0���ӼƬ۵��Y�i
  => s���g�c��0���Ӽ�(s��l�Ȭ�2�O�]�ts�Md)

4.�}�Cmark�����g�c���w�g�T�{�L����m(��l�Ȭ�0�A���L��ȳ]�w��1)

5.while(top>-1 && !found) =>�����|�ӥB�S���X�f (top=-1�����|����)
  if(nextRow==destination_row && nextCol==destination_col) => ���X�f
  else if((maze[nextRow][nextCol]-'0')!=1 && mark[nextRow][nextCol]!=1) => ���i�H���B�O�S���L����
  
6.maze[stack[t].row][stack[t].col]='*' => �N���L������*�аO