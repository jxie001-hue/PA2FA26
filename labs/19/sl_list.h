#ifndef SL_LIST_H
#define SL_LIST_H

#include "sl_node.h"
#include <string>

class SLList {
 private:
  SLNode* head_;
  SLNode* tail_;
  unsigned int size_;

 public:
  SLList();

  ~SLList();

  void InsertHead(int head);
  // dis one
  void InsertTail(int tail);

  void RemoveHead();
  // dis one
  void RemoveTail();

  // dis one
  int GetHead() const;
  // dis one
  int GetTail() const;

  void Clear();

  unsigned int size() const;

  std::string ToString() const;
};

#endif
