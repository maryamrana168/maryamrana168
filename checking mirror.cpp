bool isMirror(Node* a, Node* b) {
    if (a == nullptr && b == nullptr) 
        return true;

    if (a == nullptr || b == nullptr) 
        return false;

    return (a->data == b->data &&
            isMirror(a->left, b->right) &&
            isMirror(a->right, b->left));
}

