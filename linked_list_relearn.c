#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// struct 1 node in linked list
struct Node
{
    int data;
    struct Node * next;
};
// function make a new node
struct Node * createNode(int data)
{
    struct Node * newNode = (struct Node) * malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
// function add element to final of list
void addLast(struct Node ** head, int k)
{
    // if list is NULL, add element to the first of list
    if(*head == NULL)
    {
        *head = createNode(k);
        return ;
    }
    // scan to the final of list to add element
    struct Node * temp = *head;
    while(temp -> next != NULL)
    {
        if(temp -> data == k)
        {
            return ;
        }
        temp = temp -> next;
    }
    // check when element is in list
    struct Node * temp = *head;
    while(temp != NULL)
    {
        if(temp -> data == k)
        {
            return;
        }
        temp = temp -> next;
    }
    // make a new node and add to list
    struct Node * newNode = createNode(k);
    newNode -> next = *head;
    *head = newNode;
}
// function add element after the elememt equal v
void addAfter(struct Node ** head, int u, int v)
{
    struct Node * temp = *head;
    struct Node * prev = NULL;
    // scan list to find element equal v
    
}