Shortest Path

1.OS：macOS Sierra
2.程式語言：C


<insert>

將一個資料欄位為k的新節點插入鏈中節點x之後

<main>

1.cost[MAX_VERTICES][MAX_VERTICES]是相鄰矩陣，用99表示之間沒有路徑
2.兩次for迴圈為計算所有對最短路徑，用 path[i][j]=k 紀錄過程中曾經經過k使distance變成最少
3.用listPointer連接路徑之頂點
4.if(distance[input1][input2]!=cost[input1][input2])
  =>表示起點到終點路上有經過其他點，並用 insert(first,path[input1][input2]) 將該點插入到路徑中間
  while(distance[input1][middle->data]!=cost[input1][middle->data])
  =>若起點與中間點之間仍有經過其他點，使用一樣的步驟找出中間點，直到找完
  while(distance[middle->data][middle->link->data]!=cost[middle->data][middle->link->data])
  =>若中間點與終點之間仍有經過其他點，使用一樣的步驟找出中間點，直到找完
5.最後將結果依序print出來
  