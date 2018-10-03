Knight's tour

1. 程式執行環境 : Win8.1
2. 程式語言 : C

<main> (Warnsdoff規則)

1.ktmove1[i], ktmove2[i] (i=1,...,8) 表示騎士可能移動的八個方向

2.board[i][j]=p 表示騎士在第p步走到位置(i, j)，還沒走過則先設p=0

3.size 表示棋盤大小 e.g.size=5表示為5*5的棋盤

4.用do-while迴圈使騎士行走(最多步數為p=size*size)

  (1)(nexti[l], nextj[l]) 表示(i, j)下一步可巡邏的格子清單

  (2)npos 表示可巡邏的格子數 => 計算方式為 "nexti[l], nextj[l]不可超過棋盤範圍"且"尚未被騎士巡邏過"
     ((i+ktmove1[k]>=0) && (i+ktmove1[k]<size) && (j+ktmove2[k]>=0) && (j+ktmove2[k]<size) && (board[i+ktmove1[k]][j+ktmove2[k]]==0))
     (所以總是可以得到 0<=npos<=8 )(1<=l<=npos)

  (3)若騎士還沒走完(p!=size*size)但npos=0，表示騎士巡邏提早結束 => 回報失敗
     若npos=1，表示騎士只有一個位置可以巡邏 => 則騎士必須走那一步

  (4)else(其他情況)，exits[l] 表示為 (nexti[l], nextj[l])的出口數(意即計算(nexti[l], nextj[l])的下一步可能巡邏點)
     把min的值設為出口數最小的位置

  (5)設定 i=nexti[min], j=nextj[min] (為騎士的新位置)

5.輸出陣列board顯示騎士之路徑