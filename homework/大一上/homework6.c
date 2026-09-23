#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define GOODS_FILE_NAME "goodsinfo.txt"

#define MAX_ID_LEN 30

#define MAX_NAME_LEN 30

#define MAX_PRICE_LEN 30

#define MAX_DISCOUNT_LEN 30

int CurrentCnt=0;

typedef struct {
char goods_id[MAX_ID_LEN];
char goods_name[MAX_NAME_LEN];
int goods_price;
char goods_discount[MAX_DISCOUNT_LEN];
int goods_amount;
int goods_remain;
} GoodsInfo;

typedef struct node
{
GoodsInfo data;
struct node *next;
} GoodsList;

GoodsInfo read_goods_info();
void init_list(GoodsList **L);
void destory_list(GoodsList **L);
void destory_list_and_file(GoodsList **L);
int save_to_file(GoodsList *L);
void output_one_item(GoodsList *L);
void output_all_items(GoodsList *L);
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
bool delete_item(GoodsList *L, char* goods_id);
GoodsList* search_item(GoodsList *L, char* goods_id);
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
void bubble_sort(GoodsList *L);
int read_line(char str[], int n);

int main()
{
GoodsList* goodlist;
init_list(&goodlist);
GoodsInfo new_info;
char ID[MAX_NAME_LEN];

while(1){
int choice=0;
printf("1.显示所有商品的信息\n"
       "2.修改某个商品的信息\n"
       "3.插入某个商品的信息\n"
       "4.删除某个商品的信息\n"
       "5.查找某个商品的信息\n"
       "6.商品存盘并退出系统\n"
       "7.对商品价格进行排序\n"
       "8.(慎用)删除所有内容\n"
       "其他.不存盘并退出系统\n");
scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        output_all_items(goodlist);
        break;
    case 2:
        read_line(ID,MAX_ID_LEN);
        new_info=read_goods_info();
        change_item(goodlist,ID,new_info);
        break;
    case 3:
        new_info=read_goods_info();
        int choose;
        scanf("%d",&choose);
        insert_item(goodlist,new_info,choose);
        break;
    case 4:
        read_line(ID,MAX_ID_LEN);
        delete_item(goodlist,ID);
        break;
    case 5:
        read_line(ID,MAX_ID_LEN);
        search_item(goodlist,ID);
        break;
    case 6:
        save_to_file(goodlist);
        return 0;
    case 7:
        bubble_sort(goodlist);
        break;
    case 8:
        destory_list_and_file(&goodlist);
        break;
    default:
        destory_list(&goodlist);
        return 0;
    }
}
}

void init_list(GoodsList **L)
{
    FILE* fp;
    GoodsInfo goodsinfo;
    GoodsList* temp,*tail;
    (*L)=(GoodsList*)malloc(sizeof(GoodsList));
    tail=(*L);

    if((fp=fopen(GOODS_FILE_NAME,"r"))==NULL)
        {if((fp=fopen(GOODS_FILE_NAME,"w"))==NULL)
            printf("提示：不能创建商品文件\n");}
    else 
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s",goodsinfo.goods_id);      
            fscanf(fp, "\t%s", goodsinfo.goods_name);
            fscanf(fp, "\t%d", &goodsinfo.goods_price);
            fscanf(fp, "\t%s", goodsinfo.goods_discount);
            fscanf(fp, "\t%d", &goodsinfo.goods_amount);
            fscanf(fp, "\t%d\n", &goodsinfo.goods_remain);
            temp=(GoodsList*)malloc(sizeof(GoodsList));
            temp->data=goodsinfo;
            tail->next=temp;
            tail=temp;
            CurrentCnt++;
        }
    }
    fclose(fp);
    tail->next=NULL;
}
bool insert_item(GoodsList *L, GoodsInfo item, int choice)
{
GoodsList* find=L;
    switch (choice)
    {
        case 0:
        {
             while(find->next!=NULL)
            {
                find=find->next;
            }
            find->next=(GoodsList*)malloc(sizeof(GoodsList));
            find->next->data=item;
            find->next->next=NULL;
            CurrentCnt++;
            return true;
        }
        case 1:
        {
            find=(GoodsList*)malloc(sizeof(GoodsList));
            find->data=item;
            find->next=L->next;
            L->next=find;
            CurrentCnt++;
            return true;
        }
        default:
        {
            for(int i=1;i<choice;i++)
                find=find->next;
            GoodsList* new=(GoodsList*)malloc(sizeof(GoodsList));
            new->data=item;
            new->next=find->next;
            find->next=new;
            CurrentCnt++;
            return true;
        }
    }
}
bool delete_item(GoodsList *L, char* goods_id)
{
GoodsList *cur=L,*pre=NULL;

for(;strcmp(goods_id,cur->data.goods_id);pre=cur,cur=cur->next)
{
    if(cur->next==NULL)
    return false;
}

if(pre==NULL)
{
L=L->next;//这里有逻辑漏洞，删除第一个时并不能将新的L返回
free(cur);
CurrentCnt--;
return true;
}
else
{
pre->next=cur->next;
free(cur);
CurrentCnt--;
return true;
}
}
GoodsList *search_item(GoodsList* L, char* goods_id)
{
while(L!=NULL&&strcmp(L->data.goods_id,goods_id))
L = L->next;

return L;
}
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info)
{
for (;L!=NULL&&strcmp(L->data.goods_id,goods_id);L=L->next)
    ;
    if(L==NULL)
        return false;
    else
    L->data=new_info;
return true;
}
void output_one_item(GoodsList *p)
{
    if (p!=NULL)
    {
        GoodsInfo temp = p->data;
        printf("%s\n%s\n%d\n%s\n%d\n%d\n", temp.goods_id, temp.goods_name, temp.goods_price, temp.goods_discount, temp.goods_amount, temp.goods_remain);
    }
}
void output_all_items(GoodsList *L)
{
for(L=L->next;L!=NULL;L=L->next)
{output_one_item(L);}
}
void destory_list(GoodsList** L)
{
    for (; *L; *L = (*L)->next)
        free(*L);
    CurrentCnt=0;  //第九题
}
void destory_list_and_file(GoodsList **L)
{
    destory_list(L);
    remove("goodinfo.txt");

}
int save_to_file(GoodsList* L)
{
    int count=0;
    FILE* txt;
    txt = fopen("goodsinfo.txt", "w+");
    for (L=L->next;L!=NULL; L = L->next)
    {
        GoodsInfo temp = L->data;
        fprintf(txt, "%s\n%s\n%d\n%s\n%d\n%d\n", temp.goods_id, temp.goods_name, temp.goods_price, temp.goods_discount, temp.goods_amount, temp.goods_remain);
        count++;
    }
    fclose(txt);
    return count;
}
void bubble_sort(GoodsList *L)
{
    GoodsInfo temp;
    GoodsList* cur;
    int len = 0;

    cur = L->next;
    while (cur != NULL) {
        len++;
        cur = cur->next;
    }

    for (int i = 0; i < len - 1; i++)
    {
        cur = L->next;
        for (int j = 0; j < len - 1 - i; j++) 
        {
            if (cur->data.goods_price > cur->next->data.goods_price) 
            {
                temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;
            }
            cur = cur->next;
        }
    }
}
GoodsInfo read_goods_info()
{
    GoodsInfo goods;
    read_line(goods.goods_id, MAX_ID_LEN);
    read_line(goods.goods_name, MAX_NAME_LEN);
    scanf("%d", &goods.goods_price);
    read_line(goods.goods_discount, MAX_PRICE_LEN);
    scanf("%d", &goods.goods_amount);
    scanf("%d", &goods.goods_remain);
    return goods;
}