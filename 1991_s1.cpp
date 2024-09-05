#include <cstdio>
struct Node{
    int left;
    int right;
}list [26];

void preorder(int index){
    if(index==-1) return;
    printf("%c", index+'A');
    if(list[index].left) preorder(list[index].left);
    if(list[index].right) preorder(list[index].right);
}

void inorder(int index){
    if(index==-1) return;
    if(list[index].left) inorder(list[index].left);
    printf("%c", index+'A');
    if(list[index].right) inorder(list[index].right);
}

void postorder(int index){
    if(index==-1) return;
    if(list[index].left) postorder(list[index].left);
    if(list[index].right) postorder(list[index].right);
    printf("%c", index+'A');
}

int main(){
    int n;
    scanf("%d", &n);
    char val, left, right;
    for(int i=0; i<n;++i){
        scanf(" %c %c %c", &val, &left, &right);
        list[val-'A'].left = left == '.' ? -1 : left-'A';
        list[val-'A'].right = right == '.' ? -1 : right-'A';
    }
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    return 0;

}