/*
Mỗi nút của Cây tìm kiếm nhị phân (BST) T có một khóa (khóa của các nút phải khác nhau).
Thực hiện một chuỗi các phép toán trên Cây tìm kiếm nhị phân T (bắt đầu từ BST rỗng) bao gồm:
- chèn k: chèn một nút mới có khóa = k vào T
- preorder: in (trên một dòng mới) chuỗi các khóa của các nút 
của T được duyệt qua bằng lệnh Pre-Order (các phần tử được 
phân tách bằng ký tự SPACE)
- postorder: in (trên một dòng mới) chuỗi các khóa của các nút 
của T được duyệt qua bằng lệnh Post-Order (các phần tử được 
phân tách bằng ký tự SPACE)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int key;
    struct Node * left;
    struct Node * right;
};
struct Node * newNode(int item)
{
    struct Node*temp = (struct Node*) malloc(sizeof(struct Node));
    temp -> key = item ;
    temp -> left = temp -> right = NULL;
    return temp ;
}
struct Node * insert(struct Node * node, int key)
{
    // neu cay rong tra ve node moi
    if(node == NULL) 
    {
        return newNode(key);
    }
    if(key < node -> key)
    {
        node -> left = insert(node-> left, key);
    }
    else if(key > node-> key)
    {
        node -> right = insert(node -> right, key);
    }
    return node;
}
void preOrder(struct Node * root)
{
    if(root != NULL)
    {
        printf("%d ", root -> key);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}
void postOrder(struct Node * root)
{
    if(root != NULL)
    {
        printf("%d ", root -> key);
        postOrder(root -> right);
        postOrder(root -> left);
    }
}
int main()
{
    struct Node * root = NULL;
    char command[50];
    int key;
    while(1)
    {
        fgets(command, sizeof(command), stdin);
        if(command[0] == '#')
        {
            break;
        }
        if(strncmp(command, "insert", 6) == 0)
        {
            sscanf(command + 7, "%d", &key);
            root = insert(root, key);
        }
        preOrder(root);
        postOrder(root);
    }
    return 0;
}