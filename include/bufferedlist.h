#ifndef __BUFFEREDLIST_H__
#define __BUFFEREDLIST_H__

#include "linkedlist.h"

typedef struct _BufferedList
{
	LinkedList Free;
	LinkedList Used;
} BufferedList;

void  BufferedList_Init(BufferedList* list, Node* nodes, uint32_t nodeSize, uint32_t numNodes);
Node* BufferedList_LinkHead(BufferedList* list);
Node* BufferedList_LinkTail(BufferedList* list);
Node* BufferedList_UnlinkHead(BufferedList* list);
Node* BufferedList_UnlinkTail(BufferedList* list);
Node* BufferedList_LinkAfter(BufferedList* list, Node* afterNode);
Node* BufferedList_LinkBefore(BufferedList* list, Node* beforeNode);
Node* BufferedList_UnlinkNode(BufferedList* list, Node* node);

#endif // __BUFFEREDLIST_H__
