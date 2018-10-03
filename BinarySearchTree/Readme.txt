Binary Search Tree

1. OS : Win8.1
2. 程式語言 : C

<search>

尋找k是否已在tree裡
有的話回傳該節點，若沒有則回傳k將來可插入在哪個節點之下

<insert>

尋找node可插入在哪個節點之下

<printp>

印出data，若是空節點則印出*

<delet>

刪除節點
1.若該節點是leaf(!(ptr->leftChild) && !(ptr->rightChild))=>直接刪除
2.若其左子樹為空(!(ptr->leftChild))=>使其右節點直接取代它
3.若其右子樹為空(!(ptr->rightChild))=>使其左節點直接取代它
4.若左右子樹皆非空=>使其左子樹之最大值移至該位置

<main>
1.先使用do-while迴圈輸入data
2.再使用insert把所有節點接上
3.把tree依序放入queue裡，並同時用一整數r來計數，data有值時r+1
  當r=input的數量時直接把queue裡的東西印出來
4.整數t和pow(2,t)用來決定何時換行
5.使用for迴圈供使用者刪除節點，其中用布林值check判斷輸入值是否再tree裡
  直到使用者不刪除節點才跳出迴圈，結束程式

<time complexity>...h為binary search tree的高度
1.search:O(h)，因為每到一層判斷一次大小，最多得經過h層
2.insert:O(h)，因為要先搜尋樹，剩餘的部分是Θ(1)
3.printp:Θ(1)
4.delet:O(h)，每刪除一個節點，要將下面的都往上移一層，最多會動h次