#include <stdio.h>
#include <stdlib.h>

typedef int TElement;
typedef struct node {
  TElement value;
  struct node *left;
  struct node *right;
} TreeNode;

typedef TreeNode *tree;

bool IsEmpty(tree T) { return T == NULL; }

tree Left(tree T) {
  if (IsEmpty(T)) {
    return NULL;
  } else {
    return T->left;
  }
}

tree Right(tree T) {
  if (IsEmpty(T)) {
    return NULL;
  } else {
    return T->right;
  }
}

bool IsLeave(tree T) {
  if (IsEmpty(T)) {
    return false;
  } else {
    return (T->left == NULL && T->right == NULL);
  }
}

bool IsInternalNode(tree T) {
  if (IsEmpty(T)) {
    return false;
  } else {
    return (!IsLeave(T));
  }
}

unsigned Height(tree T) {
  if (IsEmpty(T)) {
    return 0;
  } else {
    unsigned left_height = Height(Left(T));
    unsigned right_height = Height(Right(T));
    return (left_height > right_height ? left_height : right_height) + 1;
  }
}

unsigned NbNode(tree T) {
  if (IsEmpty(T)) {
    return 0;
  } else {
    return 1 + NbNode(Left(T)) + NbNode(Right(T));
  }
}

unsigned NbLeaves(tree T) {
  if (IsEmpty(T)) {
    return 0;
  } else if (IsLeave(T)) {
    return 1;
  } else {
    return NbLeaves(Left(T)) + NbLeaves(Right(T));
  }
}

unsigned NbInternalNode(tree T) {
  if (IsEmpty(T)) {
    return 0;
  } else if (IsLeave(T)) {
    return 0;
  } else {
    return 1 + NbInternalNode(Left(T)) + NbInternalNode(Right(T));
  }
}

void DFS_prefix(tree T) {
  if (!IsEmpty(T)) {
    printf("%d ", T->value);
    DFS_prefix(Left(T));
    DFS_prefix(Right(T));
  }
}

void DFS_infix(tree T) {
  if (!IsEmpty(T)) {
    DFS_infix(Left(T));
    printf("%d ", T->value);
    DFS_infix(Right(T));
  }
}

void DFS_postfix(tree T) {
  if (!IsEmpty(T)) {
    DFS_postfix(Left(T));
    DFS_postfix(Right(T));
    printf("%d ", T->value);
  }
}

void BFS(tree T) {
  if (IsEmpty(T)) {
    return;
  }

  Queue q;
  InitQueue(&q);
  Enqueue(&q, T);

  while (!IsEmptyQueue(q)) {
    tree cur = Dequeue(&q);
    printf("%d ", cur->value);

    if (cur->left != NULL)
      Enqueue(&q, cur->left);

    if (cur->right != NULL)
      Enqueue(&q, cur->right);
  }
}

tree Create(TElement val, tree ls, tree rs) {
  tree T = (tree)malloc(sizeof(TreeNode));
  T->value = val;
  T->left = ls;
  T->right = rs;
  return T;
}

void AddElt(tree src, TElement elt) {
  if (IsEmpty(src)) {
    src = Create(elt, NULL, NULL);
    return;
  }

  Queue q;
  InitQueue(&q);
  Enqueue(&q, src);

  while (!IsEmptyQueue(q)) {
    tree cur = Dequeue(&q);

    if (cur->left == NULL) {
      cur->left = Create(elt, NULL, NULL);
      return;
    } else {
      Enqueue(&q, cur->left);
      if (cur->right == NULL) {
        cur->right = Create(elt, NULL, NULL);
        return;
      } else {
        Enqueue(&q, cur->right);
      }
    }
  }

  bool Exist(tree src, TElement elt) {
    if (IsEmpty(src)) {
      return false;
    }

    if (src->value == elt) {
      return true;
    } else {
      return Exist(src->left, elt) || Exist(src->right, elt);
    }
  }

  void Erase(tree * src) {
    if (*src == NULL) {
      return;
    }

    Erase(&((*src)->left));
    Erase(&((*src)->right));
    free(*src);
    *src = NULL;
  }

  void BFS(tree T) {
    if (IsEmpty(T)) {
      return;
    }

    Queue q;
    InitQueue(&q);
    Enqueue(&q, T);

    while (!IsEmptyQueue(q)) {
      tree cur = Dequeue(&q);
      printf("%d ", cur->value);

      if (cur->left != NULL)
        Enqueue(&q, cur->left);

      if (cur->right != NULL)
        Enqueue(&q, cur->right);
    }
  }

  tree Create(TElement val, tree ls, tree rs) {
    tree T = (tree)malloc(sizeof(TreeNode));
    T->value = val;
    T->left = ls;
    T->right = rs;
    return T;
  }

  void AddElt(tree src, TElement elt) {
    if (IsEmpty(src)) {
      src = Create(elt, NULL, NULL);
      return;
    }

    Queue q;
    InitQueue(&q);
    Enqueue(&q, src);

    while (!IsEmptyQueue(q)) {
      tree cur = Dequeue(&q);

      if (cur->left == NULL) {
        cur->left = Create(elt, NULL, NULL);
        return;
      } else {
        Enqueue(&q, cur->left);
      }

      if (cur->right == NULL) {
        cur->right = Create(elt, NULL, NULL);
        return;
      } else {
        Enqueue(&q, cur->right);
      }
    }
  }