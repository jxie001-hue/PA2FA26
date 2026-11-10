#include "sl_node.h"

SLNode::SLNode() {
        contents_ = 0;
        next_node_ = nullptr;
    }

SLNode::SLNode(int x) {
        contents_ = x;
        next_node_ = nullptr;
    }

SLNode::~SLNode() {}

void SLNode::set_contents(int x) {
        contents_ = x;
    }
int SLNode::contents() const {
    return contents_;
}

void SLNode::set_next_node(SLNode* next_node) {
    next_node_ = next_node;
}

SLNode* SLNode::next_node() const {
    return next_node_;
}
