/*矩阵加法

实现三元组表示的两个稀疏矩阵的加法。相关定义如下：

#define MAXSIZE 100  //假设非零元个数的最大值为100
typedef struct {
    int i,j;		//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;	    //非零元的值
}Triple;

typedef struct {
    Triple data[MAXSIZE];	// 非零元三元组表
    int    m, n, len;		// 矩阵的行数、列数和非零元个数
}TSMatrix;
在三元组中，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
矩阵加法函数的原型为：

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ);
pM, pN, pQ 分别指向三个矩阵，
当 pM 和 pN 两个矩阵不可加时，函数返回 false，
否则函数返回 true，且 pQ 指向两个矩阵的和。*/

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ)
{
if(pM->m!=pN->m||pM->n!=pN->n)
    return false;

pQ->m=pM->m;
pQ->n=pM->n;
pQ->len=0;

int pM_index=0,pN_index=0,pQ_index=0;
while (pM_index<pM->len&&pN_index<pN->len)
{
    int row_M=pM->data[pM_index].i,col_M=pM->data[pM_index].j,
        row_N=pN->data[pN_index].i,col_N=pN->data[pN_index].j;

    if(row_M<row_N||(row_M==row_N&&col_M<col_N)) 
    {
        pQ->data[pQ_index]=pM->data[pM_index];
        pM_index++;
        pQ_index++;
        pQ->len++;
    }
    else if(row_M>row_N||(row_M==row_N&&col_M>col_N))
    {
        pQ->data[pQ_index] = pN->data[pN_index];
        pN_index++;
        pQ_index++;
        pQ->len++;
    }
    else
    {
        ElemType sum=pM->data[pM_index].e+pN->data[pN_index].e;
        if (sum!=0)
        {
            pQ->data[pQ_index].i = row_M;
            pQ->data[pQ_index].j = col_M;
            pQ->data[pQ_index].e = sum;
            pQ_index++;
            pQ->len++;
        }
            pM_index++;
            pN_index++;
    }
}
//由于while中是||,需要处理剩余的
while (pN_index < pN->len)
{
    pQ->data[pQ_index] = pN->data[pN_index];
    pN_index++;
    pQ_index++;
    pQ->len++;
}
while (pM_index < pM->len)
    {
    pQ->data[pQ_index] = pM->data[pM_index];
    pM_index++;
    pQ_index++;
    pQ->len++;
}

return true;
}