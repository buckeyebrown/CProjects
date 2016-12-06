# Singley Linked List

### The Author
My name is Dylan Brown, and I'm a senior at The Ohio State University.

### The Problem
This project is meant to implement a Singly Linked List with C. The user should be able to input an array of values to form the list with. Then, the user can either print the list or input a value, search for it in the list, and insert or delete it from the list. The program exits when the list is empty or the user requests the program to exit.

### The Algorithm
The list and each node in the list were implemented with two structures, both with dynamically allocated memory. The node structure held both an integer value, and a pointer to the next node. The list structure holds simply the head node for the list. Nodes are inserted at the end of the list, by assigning the last node on the lists' node->next value to the inserted node. Nodes are deleted by assigning the previous nodes' node->next pointer to the delete nodes' node->next pointer, and freeing up the dynamic memory for the previous node. 
