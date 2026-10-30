#ifndef SL_LIST_H
#define SL_LIST_H

#include "sl_node.h"
#include <string>

class SLList {
 private:
  SLNode* head_;
  unsigned int size_;

 public:
  SLList();

  ~SLList();

  void InsertHead(int head);

  void RemoveHead();

  void Clear();

  unsigned int size() const;

  std::string ToString() const;
};

#endif
