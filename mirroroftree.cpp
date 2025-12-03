Node* mirrorCopy(Node* root) {
    if (root == nullptr)
        return nullptr;

    Node* newRoot = new Node(root->data);
    newRoot->left  = mirrorCopy(root->right);
    newRoot->right = mirrorCopy(root->left);

    return newRoot;
}

