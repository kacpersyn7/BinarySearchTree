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
#include <unistd.h>
#include "tree.h"

/*
 * 
 */

int main(int argc, char** argv) {
    int i, error = 0;
    char charkey;
    char searchname[20];
    data_t first;
    node_t *root=NULL;
    node_t *search;
    root = (node_t*)malloc(sizeof(node_t));
    printf("Podaj dane korzenia \n");
    loadData(&first);
    root->book = first;
    root->left = NULL;
    root->right = NULL;
    while((charkey = getchar()) != 'z' && error != 1)
    {
        system("clear");
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
                getchar();
                fflush(stdin);
                break;
            case 's':
                printf("Podaj szukane nazwisko\n");
                scanf("%s",searchname);
                search = searchKey(root, searchname);
                if(search)
                    writeElement(&(search->book));
                getchar();
                fflush(stdin);
                break;
            case 'x':
                maxRecord(root);
                getchar();
                fflush(stdin);
                break;
            case 'm':
                minRecord(root);
                getchar();
                fflush(stdin);
            default:
                break;
        }
    }
    delAll(root);
    printf("super\n");
    getchar();
    return error;
}

