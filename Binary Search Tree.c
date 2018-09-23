#include<stdio.h>
struct Tree {
    int data;
    struct Tree *left, *right;
};
struct Tree* insertTree(struct Tree *root,int item) {
    if(root == NULL) {
        struct Tree* nn=(struct Tree *)malloc(sizeof(struct Tree));
        nn->data=item;
        nn->left=nn->right=NULL;
        return nn;
    }
    if(item < root->data) root->left=insertTree(root->left,item);
    else if(item > root->data) root->right=insertTree(root->right,item);
    return root;
}
int findMax(struct Tree *root) {
    while(root->right) findMax(root->right);
    return root->data;
}
struct Tree* deleteData(struct Tree *root,int item) {
    if(root->data == item) {
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        else {
            int x=findMax(root->left);
            root->data=x;
            deleteData(root->left,root->data);
            return root;
        }
    }
    if(root->data < item) root->right=deleteData(root->right,item);
    else if(root->data > item) root->left=deleteData(root->left,item);
    return root;
}
void printTree(struct Tree *root) {
    if(root) {
        printTree(root->left);
        printf("%d ",root->data);
        printTree(root->right);
    }
}
void main() {
    int n;
    printf("Enter number of elements you want to enter in Tree : ");
    scanf("%d",&n);
    printf("\nEnter elements...\n");
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    struct Tree *root=NULL;
    root=insertTree(root,arr[0]);
    for(int i=1; i<n; i++) insertTree(root,arr[i]);
    printf("\nEnter the data you want to delete from Tree : ");
    int x,flag=1;
    scanf("%d",&x);
    for(int i=0; i<n; i++) {
        if(arr[i] == x) {
            flag=0;
            deleteData(root,x);
            printTree(root);
        }
    }
    if(flag) printf("\nElement not found!\n");
}
