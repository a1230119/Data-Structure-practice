Knight's tour

1. �{���������� : Win8.1
2. �{���y�� : C

<main> (Warnsdoff�W�h)

1.ktmove1[i], ktmove2[i] (i=1,...,8) ����M�h�i�ಾ�ʪ��K�Ӥ�V

2.board[i][j]=p ����M�h�b��p�B�����m(i, j)�A�٨S���L�h���]p=0

3.size ��ܴѽL�j�p e.g.size=5��ܬ�5*5���ѽL

4.��do-while�j����M�h�樫(�̦h�B�Ƭ�p=size*size)

  (1)(nexti[l], nextj[l]) ���(i, j)�U�@�B�i���ު���l�M��

  (2)npos ��ܥi���ު���l�� => �p��覡�� "nexti[l], nextj[l]���i�W�L�ѽL�d��"�B"�|���Q�M�h���޹L"
     ((i+ktmove1[k]>=0) && (i+ktmove1[k]<size) && (j+ktmove2[k]>=0) && (j+ktmove2[k]<size) && (board[i+ktmove1[k]][j+ktmove2[k]]==0))
     (�ҥH�`�O�i�H�o�� 0<=npos<=8 )(1<=l<=npos)

  (3)�Y�M�h�٨S����(p!=size*size)��npos=0�A����M�h���޴������� => �^������
     �Ynpos=1�A����M�h�u���@�Ӧ�m�i�H���� => �h�M�h���������@�B

  (4)else(��L���p)�Aexits[l] ��ܬ� (nexti[l], nextj[l])���X�f��(�N�Y�p��(nexti[l], nextj[l])���U�@�B�i�ਵ���I)
     ��min���ȳ]���X�f�Ƴ̤p����m

  (5)�]�w i=nexti[min], j=nextj[min] (���M�h���s��m)

5.��X�}�Cboard����M�h�����|