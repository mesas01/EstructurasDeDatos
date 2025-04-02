// node.hxx
#pragma once

enum Color { RED, BLACK };

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    // Constructor
    Node(int data);
};
