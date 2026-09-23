/*十字链表

十字链表相关定义如下：

typedef int ElemType;

// 非零元素结点结构
typedef struct OLNode
{
    int row,col;
    ElemType value;
    struct OLNode *right,*down;
}OLNode,*OLink;

// 十字链表结构
typedef struct
{
    OLink *rowhead,*colhead;
    int rows,cols,nums;
}CrossList, *PCrossList;
1）实现十字链表的初始化操作：

 int init_cross_list(PCrossList L, const ElemType *A, int m, int n);
其中 L 指向 CrossList 结构，且各成员已被初始化为0；
A 为 ElemType 类型数组中第一个元素的地址，元素的个数为 m×n 个，按行优先存储（即A[0] 为十字链表第1行第1列的元素；
A[1] 为第1行第2列的元素，A[n] 为第2行第1列的元素，A[n+1] 为第2行第2个元素）；
m 表示十字链表的行数，n 表示十字链表的列数。
init_cross_list 函数将 ElemType 数组中非0元素保存到十字链表中，函数返回非 0 元素的个数。

2）实现十字链表的删除操作：

 int del_cross_list(PCrossList L, ElemType k);
其中 L 指向 要处理的 CrossList 结构，k 为要删除的元素；
del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。*/

int init_cross_list(PCrossList L, const ElemType *A, int m,int n)
{
L->rows=m;
L->cols=n;
L->nums=0;
//分配内存
L->rowhead=(OLink*)malloc((m+1)*sizeof(OLink*));
L->colhead=(OLink*)malloc((n+1)*sizeof(OLink*));
//行列头指针初始化为NULL
for(int i=0;i<m;i++)
L->rowhead[i]=NULL;
for(int i=0;i<n;i++)
L->colhead[i]=NULL;

for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        int cur_value=A[i*n+j];
        if(cur_value==0)
            continue;
        OLink newNode=(OLink)malloc(sizeof(OLNode));
        newNode->row=i+1;
        newNode->col=j+1;
        newNode->value=cur_value;
        newNode->right=NULL;
        newNode->down=NULL;

        //找到插入位置
        OLink pre=NULL;
        OLink cur=L->rowhead[i];
        while (cur&&cur->col<j)
        {
            pre=cur;
            cur=cur->right;
        }
        if (!pre)
        {
            newNode->right=L->rowhead[i];
            L->rowhead[i]=newNode;
        } else
        {
            newNode->right=pre->right;
            pre->right=newNode;
        }

        pre = NULL;
        cur = L->colhead[j];
        while (cur&&cur->row<i)
        {
            pre=cur;
            cur=cur->down;
        }
        if (!pre)
        {
            newNode->down=L->colhead[j];
            L->colhead[j]=newNode;
        } else
        {
            newNode->down=pre->down;
            pre->down=newNode;
        }
    L->nums++;
    }
}
return L->nums;
}


int del_cross_list(PCrossList L, ElemType k)
{
if(L->nums==0)
    return 0;
int del_count=0;

for (int i=0;i<L->rows;i++)
{
    OLink pre=NULL;
    OLink cur=L->rowhead[i];
    while (cur!=NULL)
    {
        if (cur->value==k)
        {
            OLink temp=cur;
            int j=temp->col;  //记录结点的矩阵列号

            //从行链表删除(只断开链)
            if (pre==NULL)
                L->rowhead[i]=cur->right;
            else
                pre->right=cur->right;
            cur=cur->right;

            //从列链表删除(从这一列找到这个节点)
            OLink c_pre = NULL;
            OLink c_cur = L->colhead[j-1];
            while (c_cur=NULL&&c_cur!=temp)
            {
                c_pre=c_cur;
                c_cur=c_cur->down;
            }
            if (c_cur!=NULL)
            {
                if (c_pre==NULL)
                    L->colhead[j-1]=c_cur->down;
                else
                    c_pre->down=c_cur->down;
            }
            free(temp);
            del_count++;
            L->nums--;
        }
        else
        {
            pre = cur;
            cur=cur->right;
        }
    }
}
return del_count;
}
