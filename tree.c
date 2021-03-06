/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * wyszukiwanie wartości minimalnej  klucza w drzewie – zrealizowane rekurencyjnie
 * wyszukiwanie wartości maksymalnej klucza w drzewie
 * zliczanie wezlow w drzewie
 * wyszukiwanie okreslonego klucza w drzewie
 * okreslanie wysokosci drzewa
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
void delAll(node_t * root)  
{
    node_t * temp;
    if (root)
    {
        delAll(root->left);
        delAll(root->right);
        temp = root;
        free(temp);
        root = NULL;
    }
}
int insertElement(node_t *root,data_t *newelement)
{
    int checkadd=1;
    int error = 0;
    node_t *temp = root;
    while(checkadd)
    {
        
        if(strcoll((temp->book).secondname_id,newelement->secondname_id)>0)
        {
            if(temp->left == NULL)
            {
                temp->left = (node_t*)malloc(sizeof(node_t));
                if(temp->left != NULL)
                {
                    temp->left->left = NULL;
                    temp->left->right = NULL;
                    temp->left->book = *newelement;
                    checkadd = 0;
                }
                else 
                {
                    delAll(root);
                    printf("FAIL!");
                    error = 1;
                    break;
                }
            }
            else 
                temp = temp->left;
        }
        else
        {
           if(temp->right == NULL)
            {
                temp->right = (node_t*)malloc(sizeof(node_t));
                if(temp->right != NULL)
                {
                    temp->right->left = NULL;
                    temp->right->right = NULL;
                    temp->right->book = *newelement;
                    checkadd = 0;
                }
                else 
                {
                    delAll(root);
                    printf("FAIL!");
                    error = 1;
                    break;
                }
            }
           else
               temp = temp->right;
        }
    }
    return error;
}
node_t *searchKey(node_t *root, char *key)
{
  node_t *x = root;
  while((x) && (strcmp(x->book.secondname_id, key)))
    x = (strcoll(key, x->book.secondname_id)<0) ? x->left : x->right;
  return x;
}
void minRecord(node_t *root)
{
   if (root)
   { 
       maxRecord(root->left);
       if (root->left == NULL)
            writeElement(&(root->book));
   }
}
int treeHeight(node_t *tree)
{
	int hl, hr;
	if (tree != NULL )
	{
		hl = treeHeight(tree->left);
		hr = treeHeight(tree->right);
		return(1 + (hl > hr ? hl : hr));
	}
	else
		return(0);
}
void maxRecord(node_t *root)
{
   if (root)
   {  
       maxRecord(root->right);
       if (root->right == NULL)
            writeElement(&(root->book));
   }
}
int Nodes(node_t *root)
{
    if(!root) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return(1+Nodes(root->left)+Nodes(root->right));
}

void loadData(data_t *element)
{
    printf("\nPodaj imie\n");
    scanf("%s", element->name);
    printf("Podaj nazwisko\n");
    scanf("%s", element->secondname_id);
    printf("Podaj pierwszy numer\n");
    scanf("%d", &(element->numberfirst));
    printf("Podaj drugi numer\n");
    scanf("%d", &(element->numbersecond));
}
void writeElement(data_t *element)
{
    printf("\n Imie: %s",element->name);
    printf("\n Nazwisko: %s",element->secondname_id);
    printf("\n Pierwszy numer: %d",element->numberfirst);
    printf("\n Drugi numer: %d",element->numbersecond);
}
void writeTree(node_t *root)
{
    if(root != NULL)
    {
        writeTree(root->left);
        writeElement(&(root->book));
        writeTree(root->right);
    }
}
void show(void)
{
    printf("1.Dodaj element - d\n2.Wyszukaj element (po nazwisku) - s\n3.podaj wysokosc - h\n");
    printf("4.Podaj ostatni element - x\n5.Podaj pierwszy element - m\n6.Wypisz baze - w\n7.Podaj ilosc wezlow - n\n");
    printf("8.Zakoncz - z\n");
}