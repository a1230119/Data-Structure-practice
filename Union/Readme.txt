Union

1. OS : Win8.1
2. �{���y�� : C

<main>
�]�w��l�ȡA�C��node��parent�Ȭ�-1
�]�_�l���A���C��node�Y���@�ʾ�A�]�N�O�𪺰��׬�1�A�]��parent�ȦP�ɤ]�N����(height=-parent[i])

<heightUnion>
�Y��i�����פp��j(parent[i]>parent[j])�A�hj��i��parent;�_�hi��j��parent
�䤤�Y��̰��׬ۦP�A�hi��j��parent�A���]���|��i�����ץ[1�A�Gparent[i]-1

(d)
Experiment with functions weightedUnion and heightUnion to determine which one produces better results when used in conjunction with function collapsingFind.
Please compare these two situations with functions weightedUnion and heightUnion.

Ans:

Situation 1 �Y��(a)�����]
�� weightedUnion �M heightUnion ���|�Φ�
		(0)
	   /  /     \   \
	  (1)(2)...(n-2)(n-1)  ���ˤl
�G�P collapsingFind �t�X�ϥΤ����G�ۦP

Situation 2

Tree1:        Tree2:
Node parent   Node parent
0    root     1    root
	      2    1
	      3    1
	      4    3

Tree3:
Node parent
5    root
6    5

Tree4:        Tree5:
Node parent   Node parent
7    root     15   root
8    7	      16   15
9    7	      17   16
10   7	      18   17
11   8	      19   18
12   8	      20   19
13   9	      21   20
(Tree4,Tree5���`�I�ƬۦP����)
Tree1,2,3 �ϥ� weightedUnion �M heightUnion �o�X�����G�ۦP
�ϥ� weightedUnion �e���o�칳Tree4����
�ϥ� heightUnion �h�e���o�칳Tree5����
union(1,7):
		(1)
    /  /  /  /	       \
   (0)(2)(3)(5)	       (7)
	  |  |	    /       \
  	 (4)(6)	  (8)      (9)
  		  / \      / \    
		(10)(11)(12)(13)
union(1,15):
		(1)
    /  /  /  /	   \
   (0)(2)(3)(5)	   (15)
	  |  |      |
  	 (4)(6)	   (16)
		    |
  		   (17)
		    |
  		   (18)
		    |
  		   (19)
		    |
  		   (20)
		    |
  		   (21)

����`�I(13)�M(21):
�P�ˬO��subtree�̧Ǹ��̫�@�Ӫ��I�A��(13)�����׸��֡A�f�t collapsingFind ���֧��root
��(21)���׸����A�f�t collapsingFind ���C�F��root
=>Tree4�ϥ� collapsingFind �ĪG���n
=>weightedUnion �P collapsingFind �t�X�ϥΤ��ĪG����

