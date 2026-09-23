bool heap_insert_value(PMinHeap pq, int value) {
    if (pq->heap_size == pq->capacity) {
        // 堆已满，无法插入元素
        return false;
    }

    // 创建新的堆节点
    PMinHeapNode newNode = (PMinHeapNode)malloc(sizeof(MinHeapNode));
    if (newNode == NULL) {
        // 内存分配失败
        return false;
    }

    // 将元素插入到堆的最后一个位置
    int i = pq->heap_size;
    pq->heap_array[i].value = value;

    // 更新堆大小
    pq->heap_size++;

    // 从插入位置开始向上调整堆，以维持最小堆的性质
    while (i != 0 && pq->heap_array[parent(i)].value > pq->heap_array[i].value) {
        swap_node(&pq->heap_array[i], &pq->heap_array[parent(i)]);
        i = parent(i);
    }

    return true;
}