Documentation of the steps to each function

Algorithm for insertAtBeginning Implementation
1.Create a new Node
2.Point the new Node's next pointer to the current head.
3.Update the head of the linked list as the new node.


Algorithm for insertAtEnd Implementation
1.Create a new Node
2.If the linked list is empty, update the head as the new node.
3.Otherwise traverse till the last node of the linked list.
4.Update the next pointer of the last node from NULL to new node.


Algorithm for insertAtPosition Implementation
1.Check if the provided position by the user is a valid poistion.
2.Create a new node.
3.Find the node at position -1.
4.Update the next pointer of the new node to the next pointer of the current node.
5.Update the next pointer of the current node to new node


Algorithm for deleteFromBeginning Implementation
1.Check whether the Head of the linked list is not NULL. If Head is equal to NULL return as the linked list is empty, there is no node present for deletion.
2.Store the head of the linked list in a temp pointer.
3.Update the head of the linked list to next node.
4.Delete the temporary node stored in the temp pointer.


Algorithm for deleteFromEnd Implementation
1.Verify whether the linked is empty or not before deletion.
2.If the linked list has only one node, delete head and set head to NULL.
3.Traverse till the second last node of the linked list.
4.Store the last node of the linked list in a temp pointer.
5.Pointer the next pointer of the second last node to NULL.
6.Delete the node represented by the temp pointer.


Algorithm for deleteFromPosition Implementation
1.Check if the provided postion by the users is a valid position in the linked list or not.
2.Find the node at position -1.
3.Save node to be deleted in a temp pointer.
4.Set the next pointer of the current node to the next pointer of the node to be deleted.
5.Set the next pointer of temp to NULL.
6.Delete the node represented by temp pointer.


Algorithm for Display Implementation
1.Check if the Head pointer of the linked list is not equal to NULL.
2.Set a temp pointer to the Head of the linked list.
3.Until temp becomes null:
    1.Print temp->data
    2.Move temp to the next node.
