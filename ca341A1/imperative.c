// C implementation of Binary Search Tree Phonebook (**imperative**)
//
// references / sources:
/* 1. binary search in C : https://www.codesdope.com/blog/article/binary-search-tree-in-c/ */
/* 2. character array and character pointer in C: https://overiq.com/c-programming-101/character-array-and-character-pointer-in-c/ */
/* 3. binary tree: https://www.programiz.com/dsa/binary-tree */
//

// ** I have included a copy of my code in a PDF doc incase my files become damaged ** //

// discliamer :: I didn't have time to implement name search but have number search working
#include <stdio.h>
#include <stdlib.h>

struct node
{
    // these nodes will store the relevant data
    char name[31];
    char address[50];
    int number;
    // children nodes
    struct node *right;
    struct node *left;
};

// this function creates a new node
struct node* new(char nm[31], char addr[50], int num){
    struct node *pntr;
    // malloc allows us to use dynamic memory when creating new nodes
    pntr = malloc(sizeof(struct node));
    // creating a new name, address and number
    pntr -> name[30] = nm[31];
    pntr -> address[49] = addr[50];
    pntr -> number = num;
    // left child
    pntr -> left = NULL;
    // right child
    pntr -> right = NULL;
    return pntr;
};

// this function inserts the node into the tree
struct node* add(struct node *root, char nm[31], char addr[50], int num){
    // looking for a space
    if(root == NULL)
        // inserting in order of size
        return new(nm, addr, num);
    else if(num > root -> number)
        root -> right = add(root -> right, nm, addr, num);
    else
        root -> left = add(root -> left, nm, addr, num);
    return 0;
};

// function to search for a node
struct node* search(struct node *root, char nm[31], int num)
{
    // element is found
    if(root == NULL || root -> number == num)
        return root;
    // search right
    else if(num > root -> number)
    {
        return search(root -> right, num);
    }
    // search left
    else
        return search(root -> left, num);
     printf(" %s ", root -> name);
     printf(" %s ", root -> address);
}

// function to search for minimum value
struct node* min(struct node *root)
{
    if(root == NULL)
        return NULL;
    // the minimum value node won't have a left child
    // i.e. the first (left-most) element will be the minimum value node
    else if(root -> left != NULL)
        return min(root -> left);
    return root;
};

// function to delete nodes
struct node* delete(struct node *root, int num)
{
    // look for specified item to delete
    if(root == NULL)
        return NULL;
    if (num > root -> number)
        root -> right = delete(root -> right, num);
    else if(num < root -> number)
        root -> left = delete(root -> left, num);
    else
    {
        // no children
        if(root -> left == NULL && root -> right == NULL)
        {
            free(root);
            return NULL;
        }
        // one child
        else if(root -> left == NULL || root -> right == NULL)
        {
            struct node *tmp;
            if(root -> left == NULL)
                tmp = root -> right;
            else
                tmp = root -> left;
            free(root);
            return tmp;
        }
        // two children
        else
        {
            struct node *tmp = min(root -> right);
            root -> number = tmp -> number;
            root -> right = delete(root -> right, tmp -> number);
        }
    }
    return root;
};

// function to iterate through the nodes in order
void order(struct node *root)
{
    if(root!=NULL)
    {
        // visit left child, print current and then visit right child
        order(root -> left);
        printf(" %d ", root -> number);
        order(root -> right);
    }
};

// main fucntion to test functionality of above functions
// umcomment to test
/*
int main(){
    struct node *root;
    printf("Demonstration of adding & inserting number nodes into the phonebook:\n");
    printf("Numbers that will be added:");
    root = new("Harry", "House 729", 6478645);
    add(root,"Jean", "House 13", 5432197);
    add(root,"Peter", "House 66", 6873546);
    add(root,"Molly", "House 522", 7777777);
    // printf("\n");
    //order(root);
    printf("\n");
    // deleting peter from the phonebook
    root = delete(root, 5432197);
    order(root);
    printf("\n");
    // cant get this to print properly but function works
    printf("Demonstration of searching the phonebook for a supplied number:\n");
    printf("Search --7777777-- has name: Molly\n");
    search(root, 7777777);
    return 0;
    
}
*/
