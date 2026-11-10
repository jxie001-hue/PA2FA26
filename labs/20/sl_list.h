#ifndef SL_LIST_H
#define SL_LIST_H

#include "sl_node.h"
#include <string>

class SLList {
 private:
  SLNode* head_;
  SLNode* tail_;
  unsigned int size_;

  void InsertHead(int head);

  void InsertTail(int tail);

  void RemoveHead();

  void RemoveTail();

 public:
  SLList();

  ~SLList();
  // dis one
  void Insert(int num);
  // dis one
  bool RemoveFirstOccurence(int num);


  int GetHead() const;

  int GetTail() const;

  void Clear();

  unsigned int size() const;

  std::string ToString() const;
};

#endif
