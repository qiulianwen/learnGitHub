/*邻接表2

试在邻接表存储结构上实现图的基本操作 del_vertex，相关定义如下：

typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct ArcNode{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v); //删除顶点 v
当成功删除顶点或边时，函数返回true，否则（如顶点或边不存在、删除边时顶点v或w不存在）返回false。*/

bool del_vertex(ListGraph *G, VertexType v)
{
int v1=locate_vertex(G,v);
if(v1==-1)
    return false;

//删除以这个点为起始点的所有边
ArcNode *p=G->vertex[v1].firstarc;
while(p!=NULL)
{
    ArcNode *temp=p;
    p=p->nextarc;
    G->vertex[v1].firstarc=p;
    free(temp);
    G->arcnum--;
}
//删除指向这个点的边
for(int i=0;i<G->vexnum;i++)
{
    ArcNode *pre=NULL;
    p=G->vertex[i].firstarc;
    while(p!=NULL)
    {
        if(p->adjvex==v1)
        {
            if(pre==NULL)
                G->vertex[i].firstarc=p->nextarc;
            else
                pre->nextarc=p->nextarc;
            
            ArcNode *temp=p;
            p=p->nextarc;
            free(temp);
            G->arcnum--;
        }
        else
        {
            pre=p;
            p=p->nextarc;
        }
    }
}
//顶点数组后面的节点前移
for(int i=v1;i<G->vexnum-1;i++)
    G->vertex[i]=G->vertex[i+1];
G->vexnum--;
//所有>v1的adjvex需要-1
for(int i=0;i<G->vexnum;i++)
{
    p=G->vertex[i].firstarc;
     while(p!=NULL)
    {
        if(p->adjvex>=v1)
            p->adjvex--;
        p=p->nextarc;
    }
}
return true;
}