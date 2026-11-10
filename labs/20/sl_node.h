#ifndef SL_NODE_H
#define SL_NODE_H

class SLNode {
 private:
  int contents_;
  SLNode* next_node_;

 public:
  SLNode();

  SLNode(int x);

  ~SLNode();

  void set_contents(int x);
  int contents() const;

  void set_next_node(SLNode* next_node);
  SLNode* next_node() const;
};
#endif
