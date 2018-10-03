Union

1. OS : Win8.1
2. 程式語言 : C

<main>
設定初始值，每個node的parent值為-1
因起始狀態為每個node即為一棵樹，也就是樹的高度為1，因此parent值同時也代表高度(height=-parent[i])

<heightUnion>
若樹i的高度小於j(parent[i]>parent[j])，則j為i的parent;否則i為j的parent
其中若兩者高度相同，則i為j的parent，但因為會使i的高度加1，故parent[i]-1

(d)
Experiment with functions weightedUnion and heightUnion to determine which one produces better results when used in conjunction with function collapsingFind.
Please compare these two situations with functions weightedUnion and heightUnion.

Ans:

Situation 1 即為(a)的假設
而 weightedUnion 和 heightUnion 都會形成
		(0)
	   /  /     \   \
	  (1)(2)...(n-2)(n-1)  的樣子
故與 collapsingFind 配合使用之結果相同

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
(Tree4,Tree5為節點數相同的樹)
Tree1,2,3 使用 weightedUnion 和 heightUnion 得出之結果相同
使用 weightedUnion 容易得到像Tree4的樹
使用 heightUnion 則容易得到像Tree5的樹
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

比較節點(13)和(21):
同樣是該subtree裡序號最後一個的點，但(13)的高度較少，搭配 collapsingFind 較快找到root
而(21)高度較高，搭配 collapsingFind 較慢達到root
=>Tree4使用 collapsingFind 效果較好
=>weightedUnion 與 collapsingFind 配合使用之效果較佳

