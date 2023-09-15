
struct Node {
    int data; 
    Node* left;
    Node* right;
};

Node* root = new Node();

Node* GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data) {
    if(root == NULL) 
        root = GetNewNode(data);
    else 
    if(data <= root->data) 
        root->left = Insert(root->left,data);
    else 
        root->right = Insert(root->right,data);
    return root;
}

bool Search(Node* root, int data) {
    if(root == NULL) 
        return false;
    else 
    if(root->data == data) 
        return true;
    else 
    if(data <= root->data) 
        return Search(root->left,data);
    else 
        return Search(root->right,data);
}

Node* FindMin(Node* t) {
    if(t == NULL)
        return NULL;
    else 
    if(t->left == NULL)
        return t;
    else
        return FindMin(t->left);
}

Node* FindMax(Node* t) {
    if(t == NULL)
        return NULL;
    else 
    if(t->right == NULL)
        return t;
    else
        return FindMax(t->right);
}

Node* Remove(Node* t, int x) {
    Node* temp;
    if(t == NULL)
        return NULL;
    else 
    if(x < t->data)
        t->left = Remove(t->left, x);
    else 
    if(x > t->data)
        t->right = Remove(t->right, x);
    else 
    if(t->left && t->right) {
        temp = FindMin(t->right);
        t->data = temp->data;
        t->right = Remove(t->right, t->data);
    }
    else {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else 
        if(t->right == NULL)
            t = t->left;
        delete temp;
    }
    return t;
}

void preorder(Node* t) {
    if(t == NULL) 
        return;
    cout << t->data << " ";
    preorder(t->left);
    preorder(t->right);
}

void inorder(Node* t) {
    if(t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}
