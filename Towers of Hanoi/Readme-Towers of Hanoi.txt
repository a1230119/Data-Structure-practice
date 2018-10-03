Towers of Hanoi

1. 程式執行環境 : Win8.1
2. 程式語言 : C

<move>

遞迴終止條件為layer=1，將disk從A移到B  =>  printf("Move disk %d from %c to %c\n", layer, A, B);

而其他層則進行三個步驟:
1. 將最下層以外的disks從A移到C借放一下 => move(layer-1, A, C, B);
2. 將最下層disk從A移到B => printf("Move disk %d from %c to %c\n", layer, A, B);
3. 再將剛剛disks從C移到B =>  move(layer-1, C, B, A);

每移動一個disk則i加一，用來計算全部的步驟數

<main>

scanf輸入disk_num(disks number)
用if-else判斷disk_number是否在限制數量(3~64)內，若沒有則要求重新輸入