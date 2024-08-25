#include <cstdio>

struct list{
    list(int data){
        this->data=data;
    }
    ~list(){
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }
    int data;
    list* next;
    list* prev;
};

struct list* root;
struct list* current;

int main(){
    int n,k;
    scanf("%d %d",&n, &k);
    root = new list(1);
    current = root;
    for(int i=2;i<n+1;++i){
        current->next = new list(i);
        current->next->prev = current;
        current = current->next;
    }
    printf("<");
    current->next = root;
    root->prev = current;
    current = root;
    while(current->next != nullptr && current->next != current){
        for(int i=0;i<k-1;++i)
            current = current->next;
        printf("%d, ",current->data);
        list* temp = current->next;
        delete current;
        current = temp;
    }
    printf("%d>",current->data);
}