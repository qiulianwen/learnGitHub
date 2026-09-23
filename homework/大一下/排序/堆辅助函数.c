/*堆辅助函数

二叉堆是完全二叉树或者是近似完全二叉树。二叉堆有两种：最大堆和最小堆。

最大堆(大顶堆)：父结点的键值总是大于或等于任何一个子节点的键值，即最大的元素在顶端；
最小堆(小顶堆)：父结点的键值总是小于或等于任何一个子节点的键值，即最小的元素在顶端。
二叉堆子结点的大小与其左右位置无关。
二叉堆一般用数组来表示。例如，根节点在数组中的位置是0，第n个位置的子节点分别在2n+1和 2n+2。 因此，第0个位置的子节点在1和2，1的子节点在3和4。以此类推。这种存储方式便于寻找父节点和子节点。在二叉堆上可以进行插入节点、删除节点、取出值最小的节点、减小节点的值等基本操作。

“最小堆”的定义如下：

typedef struct _otherInfo
{
    int i;
    int j;
}OtherInfo;

typedef struct _minHeapNode
{
    int value;
    OtherInfo otherInfo;
}MinHeapNode, *PMinHeapNode;

typedef struct _minPQ {
    PMinHeapNode heap_array; // 指向堆元素数组
    int heap_size; // 当前堆中的元素个数
    int capacity;  //堆数组的大小
}MinHeap, *PMinHeap;
请实现最小堆的四个辅助函数：

int parent(int i); //返回堆元素数组下标为 i 的结点的父结点下标
int left(int i);  //返回堆元素数组下标为 i 的结点的左子结点下标
int right(int i);  //返回堆元素数组下标为 i 的结点的右子结点下标
void swap_node(MinHeapNode *x, MinHeapNode *y);  //交换两个堆元素的值*/

int parent(int i){
return (i+1)/2-1;
}

int left(int i){
return 2*(i+1)-1;
}

int right(int i){
return 2*(i+1);
}

void swap_node(MinHeapNode *x, MinHeapNode *y){
MinHeapNode temp=*x;
*x=*y;
*y=temp;
}