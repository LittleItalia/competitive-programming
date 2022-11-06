// Minh Tú 

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define ll  long long
#define db  double
#define pll  pair<ll, ll>
#define str string
#define pii pair<int, int>
#define vpii vector<pii>
#define vl  vector<ll>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define sz(x) x.size()
#define fi first
#define pb push_back
#define se second
#define sqr(i) i * i
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define turn_on(i, m) (m |= (1LL << i))
#define turn_off(i, m) (m &= ~(1LL << i))
#define MASK(i) (1ll << (i))
#define BIT(x, i) (((x) >> (i)) & 1) 
// x << y :  x * (2 ^ y) 
// x >> y :  x / (2 ^ y)
// (((x) >> i) & 1) : lay ra bit thu i cua x
// (m |= (1LL << i)) : bat bit thu i cua m len
// (m &= ~(1LL << i)) : tat bit thu i cua m
// __builtin_clz(n)) : dem so luong so 0 dung dau 
// __builtin_ctz(n)) : dem so luong so 0 dung cuoi
// __builtin_popcount(n) : dem so luong so 1 trong bit
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MAXN = 2e5 + 1000;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

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

void solve() {
    
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
