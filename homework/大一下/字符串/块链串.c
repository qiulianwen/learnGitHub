/*块链串

块链串定义如下：

#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符

typedef struct _block {
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct {
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;

//字符串初始化函数：
void blstr_init(BLString *T) {
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}
这些定义已包含在头文件 dsstring.h 中，请实现块链串的子串查找操作：

bool blstr_substr(BLString src, int pos, int len, BLString *sub);
src为要查找的字符串
pos为子串开始的下标
len为子串的长度
sub在函数调用运行前指向一个已经初始化好的空串，在函数返回时，sub指向串src从第pos个字符起长度为len的子串
函数查找成功返回true，参数不正确返回 false*/


bool blstr_substr(BLString src, int pos, int len, BLString *sub)
{
if (pos<0||pos>=src.len||len<=0)
    return false;

Block *cur=src.head;
// shift：块内偏移量  remain：剩余需要移动的位置数
int shift=0,remain=pos;
// 找到起始字符所在的块并计算块内偏移
while(remain>=BLOCK_SIZE)
{
    cur=cur->next;
    remain-=BLOCK_SIZE;
}
shift=remain;
// count：已提取字符数  sub_shift：子串块内偏移
int count=0,sub_shift=0;
Block *new_block=NULL;
// 计算实际可提取的长度，防止越界
int actual_len = (pos + len > src.len) ? src.len - pos : len;
while(count<actual_len)
{
    // 如果子串没有块或当前块已满则创建新块
    if(new_block==NULL||sub_shift==BLOCK_SIZE)
    {
        new_block=(Block*)malloc(sizeof(Block));
        new_block->next=NULL;
        // 子串为空则设置头尾指针
        if(sub->head==NULL)
        {
            sub->head=new_block;
            sub->tail=new_block;
        }
        // 子串不为空则将新块挂在尾部
        else
        {
            sub->tail->next=new_block;
            sub->tail=new_block;
        }
        sub_shift=0;
    }
    new_block->ch[sub_shift]=cur->ch[shift];
    sub_shift++;
    shift++;
    count++;
    // 源串当前块读完，切换到下一个块
    if(shift==BLOCK_SIZE)
    {
        cur=cur->next;
        shift=0;
    }
}
// 最后一个块按照要求用#补齐
while(sub_shift<BLOCK_SIZE)
{
    new_block->ch[sub_shift]=BLS_BLANK;
    sub_shift++;
}
// 设置子串的有效长度
sub->len=actual_len;
return true;
}