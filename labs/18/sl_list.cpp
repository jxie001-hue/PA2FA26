#include "sl_list.h"

SLList::SLList() {
    head_ = nullptr;
    size_ = 0;
}

SLList::~SLList() {}

void SLList::InsertHead(int head) {
    SLNode* new_node = new SLNode(head);

    new_node->set_next_node(head_);

    head_ = new_node;

    size_++;
}

void SLList::RemoveHead() {
    // just in case empty head_
    if (head_ == nullptr) return;

    // this is the 2nd node of the list
    SLNode* temp_node = head_->next_node();

    // erase current head
    delete head_;

    // declear new head

    head_ = temp_node;

    // update size
    size_--;
}

void SLList::Clear() {
    while (head_ != nullptr) {
        RemoveHead();
    }
}

unsigned int SLList::size() const {
    return size_;
}

std::string SLList::ToString() const {
    std::string content = "";
    SLNode* current_node = head_;

    for (unsigned int x = 0; x < size_; x++) {
        content += std::to_string(current_node->contents());
        if (x+1 < size_) content += ", ";
        current_node = current_node->next_node();
    }

    return content;
}
