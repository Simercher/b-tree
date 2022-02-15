#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct treeNode
{
    struct treeNode *left;
    int datanumber;
    struct treeNode *right;

} TreeNode;

typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *Treeptr, int datanum);
// void searchNode(TreeNodePtr *Treeptr, int datanum);
void print(TreeNodePtr treeptr);

int main()
{
    TreeNodePtr tree = NULL;
    // struct treeNode *tree = NULL;
    struct treeNode student;
    char arr[999] = {0}, arr1[999] = {0};
    int buf[999] = {0}, i = 0, ct = 0;;
    scanf("%[^\n]", arr);
    scanf(" %[^\n]", arr1);
    for (i = 0; i < strlen(arr); i++)
    {
        if (isdigit(arr[i]))
        {
            buf[ct++] =(int)(arr[i] - '0');
        }
    }
    for(int j = 0; j < ct; j++)
    {
        // printf("%d ", buf[j]);
        insertNode(&tree, buf[j]);
    }
    print(tree);
    puts("");

    return 0;
}

void insertNode(TreeNodePtr *Treeptr, int datanum)
{
    if (*Treeptr == NULL)
    {
        *Treeptr = malloc(sizeof(TreeNode));

        if (*Treeptr != NULL)
        {
            (*Treeptr)->datanumber = datanum;
            (*Treeptr)->left = NULL;
            (*Treeptr)->right = NULL;
        }
        else
        {
            printf("data not inserted. No memory available.\n");
        }
    }
    else
    {
        if (datanum < (*Treeptr)->datanumber)
        {
            insertNode(&((*Treeptr)->left), datanum);
        }
        else if (datanum > (*Treeptr)->datanumber)
        {
            insertNode(&((*Treeptr)->right), datanum);
        }
        else
        {
            printf("This data is duplication\n");
        }
    }
}

void print(TreeNodePtr treeptr)
{
    if (treeptr != NULL)
    {
        print(treeptr->left);
        print(treeptr->right);
        printf("%d ", treeptr->datanumber);
    }
}

// void searchNode(TreeNodePtr *Treeptr, int data)
// {
//     if ((*Treeptr)->datanumber == data)
//     {
//         printf("%d\n", (*Treeptr)->datanumber);
//         return 1;
//     }
//     else if ((*Treeptr)->left != NULL || (*Treeptr)->right != NULL)
//     {
//         if (data > (*Treeptr)->datanumber)
//         {
//             searchNode(&((*Treeptr)->right), data);
//         }
//         else
//         {
//             searchNode(&((*Treeptr)->left), data);
//         }
//     }
//     else
//     {
//         return 0;
//     }
// }