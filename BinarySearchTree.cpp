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

class BST {
    struct node {
        int data;
        node* left;
        node* right;
    };
    node* root;
    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    node* insert(int x, node* t) {
        if(t == NULL) {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else 
        if(x < t->data)
            t->left = insert(x, t->left);
        else 
        if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t) {
        if(t == NULL)
            return NULL;
        else 
        if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else 
        if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else 
        if(x < t->data)
            t->left = remove(x, t->left);
        else 
        if(x > t->data)
            t->right = remove(x, t->right);
        else 
        if(t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
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
    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else 
        if(x < t->data)
            return find(t->left, x);
        else 
        if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST() {
        root = NULL;
    }
    ~BST() {
        root = makeEmpty(root);
    }
    void insert(int x) {
        root = insert(x, root);
    }
    void remove(int x) {
        root = remove(x, root);
    }
    void display() {
        inorder(root);
        cout << endl;
    }
    void search(int x) {
        root = find(root, x);
    }
};

void solve() {
    BST tree;
  
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
