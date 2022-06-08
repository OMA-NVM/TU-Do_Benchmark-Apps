struct _NODE {
  long iDist;
  long iPrev;
};
typedef struct _NODE NODE;

struct _QITEM {
  long iNode;
  long iDist;
  long iPrev;
  struct _QITEM *qNext;
};
typedef struct _QITEM QITEM;

QITEM *qHead = NULL;

long AdjMatrix[NUM_NODES][NUM_NODES];

long g_qCount = 0;
NODE rgnNodes[NUM_NODES];
long ch;
long iPrev, iNode;
long i, iCost, iDist;

void print_path(NODE *rgnNodes, long chNode) {
  if (rgnNodes[chNode].iPrev != NONE) {
    print_path(rgnNodes, rgnNodes[chNode].iPrev);
  }
  printf(" %d", chNode);
}

void enqueue(long iNode, long iDist, long iPrev) {
  QITEM *qNew = (QITEM *)s_malloc(sizeof(QITEM));
  QITEM *qLast = qHead;

  if (!qNew) {
    printf("Out of memory\n");
    while (1)
      ;
  }
  qNew->iNode = iNode;
  qNew->iDist = iDist;
  qNew->iPrev = iPrev;
  qNew->qNext = NULL;

  if (!qLast) {
    qHead = qNew;
  } else {
    while (qLast->qNext)
      qLast = qLast->qNext;
    qLast->qNext = qNew;
  }
  g_qCount++;
  //               ASSERT(g_qCount);
}

void dequeue(long *piNode, long *piDist, long *piPrev) {
  QITEM *qKill = qHead;

  if (qHead) {
    //                 ASSERT(g_qCount);
    *piNode = qHead->iNode;
    *piDist = qHead->iDist;
    *piPrev = qHead->iPrev;
    qHead = qHead->qNext;
    s_free(qKill);
    g_qCount--;
  }
}

int qcount(void) { return (g_qCount); }