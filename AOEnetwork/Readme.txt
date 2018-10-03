AOEnetwork

1.OS：macOS Sierra
2.程式語言：C

用在topsort的宣告：
typedef struct node *nodePointer;
struct node{
    int vertex;
    int dur;
    nodePointer link;
};
typedef struct{
    int count;
    nodePointer link;
}hdnodes;=>event的struct
每一個event有兩個欄位：
  count:頂點的入分支度
  link:指向相鄰串列第一個節點的指標
  每一個節點有三個欄位：
  	vertex:活動終點
  	dur:活動所需的時間
	link:指向下一個節點

<topsort>

hdnodes graph[]:event陣列
int n:n為event個數
int earliest[]:計算最早事件發生時間
	if(earliest[k]<earliest[j]+ptr->dur)
    	earliest[k]=earliest[j]+ptr->dur;
    =>earliest[k]=max{earliest[j]+<j,k>所需的時間｜j在所有連到頂點k的頂點所形成的集合裡}
int order[]:紀錄stack的順序(latest[]會用到)
int latest[]:計算最晚事件發生時間
	從latest[n-1]=earliest[n-1]開始
    for(i=n-2;i>=0;i--){//從order[n-2]逆推回去
        temp=graph[order[i]].link;
        mindur=latest[temp->vertex]-temp->dur;
        while(temp->link != NULL){
            temp=temp->link;
            if(latest[temp->vertex]-temp->dur<mindur)
                mindur=latest[temp->vertex]-temp->dur;
        }
        latest[order[i]]=mindur;
    }
    =>latest[k]=min{latest[j]-<j,k>所需的時間｜j在所有從頂點k連出去的頂點之集合裡}
    
<main>

1.先初始化event[i]，再用for迴圈將每個事件及活動連接起來，其中以a[],b[],c[]紀錄活動之起點、終點及所需時間
2.呼叫topsort將ee[i],le[i]算好
  ee:earliest event, le:latest event
3.再依ee[i],le[i]計算e[i],t[i],s[i]
  e:early time, t:late time, s:slack
4.將結果印出來
  