/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kacper
 *
 * Created on 27 marca 2016, 20:22
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
 * 
 */

int main(int argc, char** argv) {
    int i, error = 0;
    char charkey;
    data_t first;
    node_t *root=NULL;
    root = (node_t*)malloc(sizeof(node_t));
    printf("Podaj dane korzenia \n");
    loadData(&first);
    root->book = first;
    root->left = NULL;
    root->right = NULL;
    switch(charkey)
    {
        case 'd':
            loadData(&first);
             if(insertElement(root,&first))
             {
                error = 1;
                printf("blad");
             }
            break;
        case 'w':
            writeTree(root);
            break;
        default:
            break;
    }
    
      /*loadData(&first);
      if(insertElement(root,&first))
      {
          error = 1;
          
      }
    
      if(insertElement(root,&first))
      {
          error = 1;
          
      }
      writeTree(root);
      delAll(root);
    printf("super");
    getchar();*/
    return error;
}

