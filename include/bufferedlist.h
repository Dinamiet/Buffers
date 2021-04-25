#ifndef __BUFFEREDLIST_H__
#define __BUFFEREDLIST_H__

#include "linkedlist.h"

typedef struct _BufferedList
{
	LinkedList Free;
	LinkedList Used;
} BufferedList;

void BufferedList_Init(BufferedList* list, Node* nodes, uint32_t numNodes);
Node* BufferedList_LinkHead(BufferedList* list, void* data);
Node* BufferedList_LinkTail(BufferedList* list, void* data);
Node* BufferedList_UnlinkHead(BufferedList* list);
Node* BufferedList_UnlinkTail(BufferedList* list);

#endif // __BUFFEREDLIST_H__
