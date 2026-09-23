/*数组合并

假设有 n 个长度为 k 的已排好序（升序）的数组，请设计数据结构和算法，将这 n 个数组合并到一个数组，且各元素按升序排列。即实现函数：

 void merge_arrays(const int* arr, int n, int k, int* output);
其中 arr 为按行优先保存的 n 个长度都为 k 的数组，output 为合并后的按升序排列的数组，大小为 n×k。

时间要求(评分规则)，当 n > k 时：

满分：时间复杂度不超过 O(n×k×log(n))
75分：时间复杂度不超过 O(n×k×log(n)×k)
59分：其它，如：时间复杂度为 O(n2×k2) 时。*/

#include <stdlib.h>

typedef struct {
    int val;
    int arr_id;
    int pos;
} Node;

static void swap(Node* a, Node* b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

static void heapify(Node heap[], int size, int idx) {
    int min = idx;
    int l = idx * 2 + 1;
    int r = idx * 2 + 2;
    if (l < size && heap[l].val < heap[min].val) min = l;
    if (r < size && heap[r].val < heap[min].val) min = r;
    if (min != idx) {
        swap(&heap[idx], &heap[min]);
        heapify(heap, size, min);
    }
}

static Node pop_min(Node heap[], int* size) {
    Node res = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return res;
}

// 题目指定传参：row 数组个数，col 每个数组长度
void merge_arrays(const int *arr, int row, int col, int* output)
{
    if (row == 0 || col == 0)
        return;

    Node* heap = (Node*)malloc(row * sizeof(Node));
    int heap_sz = 0;

    // 初始化：每一行第一个元素入堆
    for (int i = 0; i < row; i++)
    {
        Node nd;
        nd.arr_id = i;
        nd.pos = 0;
        nd.val = arr[i * col + 0];

        heap[heap_sz] = nd;
        int cur = heap_sz;
        heap_sz++;
        while (cur > 0)
        {
            int p = (cur - 1) / 2;
            if (heap[cur].val >= heap[p].val)
                break;
            swap(&heap[cur], &heap[p]);
            cur = p;
        }
    }

    int out_idx = 0;
    while (heap_sz > 0)
    {
        Node min_node = pop_min(heap, &heap_sz);
        output[out_idx++] = min_node.val;

        int next_p = min_node.pos + 1;
        if (next_p < col)
        {
            int aid = min_node.arr_id;
            Node nd;
            nd.arr_id = aid;
            nd.pos = next_p;
            nd.val = arr[aid * col + next_p];

            heap[heap_sz] = nd;
            int cur = heap_sz;
            heap_sz++;
            while (cur > 0)
            {
                int p = (cur - 1) / 2;
                if (heap[cur].val >= heap[p].val)
                    break;
                swap(&heap[cur], &heap[p]);
                cur = p;
            }
        }
    }

    free(heap);
}


