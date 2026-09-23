/*顺序表 删除重复

编写算法，在一非递减的顺序表L中，删除所有值相等的多余元素。要求时间复杂度为O(n)，空间复杂度为O(1)。

函数原型如下：
void del_dupnum(SeqList *L)

相关定义如下：
struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;*/

void del_dupnum(SeqList *L)
{
    int pre=0,cur=1;
    while(cur<=L->last)
    {
        if(L->elem[pre]==L->elem[cur])
            cur+=1;
        else
        {
            pre+=1;
            L->elem[pre]=L->elem[cur];
            cur+=1;
        }
    }
    L->last=pre;
}