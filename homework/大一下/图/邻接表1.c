/*邻接表1

试在邻接表存储结构上实现图的基本操作 insert_vertex 和 insert_arc，相关定义如下：

typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct ArcNode
{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
}VNode;

typedef struct
{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph* G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(ListGraph *G, VertexType v);
bool insert_arc(ListGraph *G, VertexType v, VertexType w);
当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。*/

bool insert_vertex(ListGraph *G, VertexType v)
{
//顶点已存在无法插入
if(locate_vertex(G,v)!=-1)
    return false;

G->vexnum++;
G->vertex[G->vexnum-1].data=v;
G->vertex[G->vexnum-1].firstarc=NULL;

return true;
}


bool insert_arc(ListGraph *G, VertexType v, VertexType w)
{
int v1=locate_vertex(G,v),v2=locate_vertex(G,w);

//顶点不存在无法插入
if(v1==-1||v2==-1)
    return false;
//边已存在无法插入
ArcNode *p=G->vertex[v1].firstarc;
while(p!=NULL)
{
    if(p->adjvex==v2)
        return false;
    p=p->nextarc;
}

ArcNode *new=(ArcNode*)malloc(sizeof(ArcNode));
new->adjvex=v2;

new->nextarc=G->vertex[v1].firstarc;
G->vertex[v1].firstarc=new;

G->arcnum++;
return true;
}