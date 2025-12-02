// Function to build BST from inorder array
Node* buildBSTfromInorder(int inorder[], int start, int end) {
    if (start > end)
        return NULL;

    // Choose middle element
    int mid = (start + end) / 2;

    Node* root = new Node(inorder[mid]);

    // Recursively build left and right subtrees
    root->left = buildBSTfromInorder(inorder, start, mid - 1);
    root->right = buildBSTfromInorder(inorder, mid + 1, end);

    return root;
}

// Function to print preorder traversal to verify
void preorder(Node* root) {
    if (root == NULL) return;
    void levelOrder(Node * root) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
    }


    int height(Node* root) {
        if (root == NULL)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }


    int countNodes(Node* root) {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int countLeafNodes(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
        isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}



void printDescendants(Node* root) {
    if (root == NULL) return;

    if (root->left != NULL) {
        cout << root->left->data << " ";
        printDescendants(root->left);
    }

    if (root->right != NULL) {
        cout << root->right->data << " ";
        printDescendants(root->right);
    }
}

void printParenthesis(Node* root) {
    if (root == NULL)
        return;

    cout << root->data;

    // If there is at least one child
    if (root->left != NULL || root->right != NULL) {
        cout << "(";

        if (root->left != NULL)
            printParenthesis(root->left);

        cout << ")(";

        if (root->right != NULL)
            printParenthesis(root->right);

        cout << ")";
    }
}

 >
     // helper copy constructor...
Node* copyTree(Node* root) {
    if (root == NULL)
        return NULL;

    Node* newNode = new Node(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}
 // copy in class

  // Copy Constructor
 BST(const BST& other) {
     root = copyTree(other.root);
 }




 // Assignment Operator 
     if (this == &other)
         return *this;
      
     deleteTree(root);

      
     root = copyTree(other.root);

     return *this;
 }

 // Destructor
 ~BST() {
     deleteTree(root);
 }


 void mirror(Node* root) {
     if (root == NULL)
         return;

     Node* temp = root->left;
     root->left = root->right;
     root->right = temp;

     mirror(root->left);
     mirror(root->right);
 }


 void printKDistanceFromRoot(Node* root, int k) {
     if (root == NULL)
         return;

     if (k == 0) {
         cout << root->data << " ";
         return;
     }

     printKDistanceFromRoot(root->left, k - 1);
     printKDistanceFromRoot(root->right, k - 1);
 }


 // Function to find index of value in inorder array
 int search(int inorder[], int start, int end, int value) {
     for (int i = start; i <= end; i++) {
         if (inorder[i] == value)
             return i;
     }
     return -1;
 }

 // Utility function to build tree
 Node* buildTree(int preorder[], int inorder[], int start, int end, int& preIndex) {

     if (start > end)
         return NULL;

     // Pick current root from preorder
     int current = preorder[preIndex++];
     Node* node = new Node(current);

     // If this node has no children
     if (start == end)
         return node;

     // Find index in inorder
     int inIndex = search(inorder, start, end, current);

     // Build left and right subtrees
     node->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
     node->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

     return node;
 }



 // Search function to find index in inorder
 int search(int inorder[], int start, int end, int value) {
     for (int i = start; i <= end; i++) {
         if (inorder[i] == value)
             return i;
     }
     return -1;
 }

 // Recursive function to build tree
 Node* buildTree(int inorder[], int postorder[], int start, int end, int& postIndex) {

     if (start > end)
         return NULL;

     // Root from postorder
     int current = postorder[postIndex--];
     Node* node = new Node(current);

     // If leaf node
     if (start == end)
         return node;

     // Find index in inorder
     int inIndex = search(inorder, start, end, current);

     // IMPORTANT: Build right subtree first
     node->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
     node->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

     return node;
 }