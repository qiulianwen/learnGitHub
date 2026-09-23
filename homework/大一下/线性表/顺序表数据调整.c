/*顺序表 数据调整
已知顺序表L中的数据元素类型为int。设计算法将其调整为左右两部分，左边的元素（即排在前面的）均为奇数
右边所有元素（即排在后面的）均为偶数，并要求算法的时间复杂度为O(n),空间复杂度为O（1）。

函数原型如下：
void odd_even(SeqList *L);

相关定义如下：
struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;*/

void odd_even(SeqList *L)
{
    int temp,head=0,tail=L->last;
    while(head<tail)
    {
        if(L->elem[head]%2==0&&L->elem[tail]%2==0)
            tail-=1;
        if(L->elem[head]%2!=0&&L->elem[tail]%2!=0)
            head+=1;
        if(L->elem[head]%2==0&&L->elem[tail]%2!=0)
        {
            temp=L->elem[head];
            L->elem[head]=L->elem[tail];
            L->elem[tail]=temp;
            head+=1;
            tail-=1;
        }
        if(L->elem[head]%2!=0&&L->elem[tail]%2==0)
        {
            head+=1;
            tail-=1;
        }
    }
}