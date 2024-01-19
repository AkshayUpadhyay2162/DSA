#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createTree(node* root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;

    root = new node(data);
    if(data==-1){
        return NULL;
    }
    
    cout<<"Enter data for left node of "<<data<<endl;
    root->left = createTree(root->left);
    cout<<"Enter data for right node of "<<data<<endl;
    root->right = createTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}

void inOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
    
}

void preOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    if(root==NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root:"<<endl;
    int data;
    cin>>data;
    root = new node(data);  
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left node of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter data for right node of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
}
}
int main(){
    node* root = NULL;
    
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    // root = createTree(root);

    // // Level Order Traversal
    // cout<<"Level order traversal output:"<<endl;
    // levelOrderTraversal(root);
    // cout<<"InOrder Traversal output:"<<endl;
    // inOrderTraversal(root);
    // cout<<endl;
    // cout<<"preOrder Traversal output:"<<endl;
    // preOrderTraversal(root);
    // cout<<endl;
    // cout<<"postOrder Traversal output:"<<endl;
    // postOrderTraversal(root);
    // cout<<endl;
    return 0;
}