/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree.h
 * Author: kacper
 *
 * Created on 27 marca 2016, 20:26
 */

#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef struct data{
    char name[20];
    char secondname_id[20];
    int numberfirst;
    int numbersecond;
} data_t;
typedef struct node{
    data_t book;
    //struct node *parent;
    struct node *left;
    struct node *right;
}node_t;
int insertElement(node_t *root,data_t *newelement);
void loadData(data_t *);
void writeElement(data_t *);
void delAll(node_t *);
void writeTree(node_t *);
node_t *searchKey(node_t *,char *);
void maxRecord(node_t *);
void minRecord(node_t *);
int treeHeight(node_t *);
int Nodes(node_t *);
void show();
#ifdef __cplusplus
}
#endif

#endif /* TREE_H */

