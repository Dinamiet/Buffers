#include "linkedlist.h"

#include <stdio.h>

#define NUM_NODES 10

typedef struct
{
	Node	 List;
	uint32_t Number;
} DataNode;

int main(int argc, char* argv[])
{
	LinkedList list;
	LinkedList_Init(&list);

	DataNode dataNodes[NUM_NODES];

	// Setup nodes
	for (size_t i = 0; i < NUM_NODES; i++) { dataNodes[i].Number = i; }

	// Add nodes to front
	LinkedList_LinkHead(&list, (Node*)&dataNodes[3]);
	LinkedList_LinkHead(&list, (Node*)&dataNodes[2]);
	LinkedList_LinkHead(&list, (Node*)&dataNodes[1]);
	LinkedList_LinkHead(&list, (Node*)&dataNodes[0]);

	LinkedList_LinkTail(&list, (Node*)&dataNodes[4]);
	LinkedList_LinkTail(&list, (Node*)&dataNodes[5]);
	LinkedList_LinkTail(&list, (Node*)&dataNodes[6]);
	LinkedList_LinkTail(&list, (Node*)&dataNodes[7]);

	DataNode* testNode;

	//Test 1;
	testNode = (DataNode*)LinkedList_UnlinkHead(&list);
	if (!testNode)
		return 1;
	if (testNode->Number != 0)
		return 1;

	// 2
	testNode = (DataNode*)LinkedList_UnlinkHead(&list);
	if (!testNode)
		return 2;
	if (testNode->Number != 1)
		return 2;

	// 3
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	if (!testNode)
		return 3;
	if (testNode->Number != 7)
		return 3;

	// 4
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	if (!testNode)
		return 4;
	if (testNode->Number != 2)
		return 4;

	// 5
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	if (testNode != NULL)
		return 5;

	testNode = (DataNode*)LinkedList_UnlinkHead(&list);
	if (testNode != NULL)
		return 5;

	// 6
	LinkedList_LinkTail(&list, (Node*)&dataNodes[9]);
	testNode = (DataNode*)LinkedList_UnlinkHead(&list);
	if (!testNode)
		return 6;
	if (testNode->Number != 9)
		return 6;

	LinkedList_LinkHead(&list, (Node*)&dataNodes[8]);
	testNode = (DataNode*)LinkedList_UnlinkHead(&list);
	if (!testNode)
		return 6;
	if (testNode->Number != 8)
		return 6;

	LinkedList_LinkHead(&list, (Node*)&dataNodes[2]);
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	if (!testNode)
		return 6;
	if (testNode->Number != 2)
		return 6;

	LinkedList_LinkTail(&list, (Node*)&dataNodes[0]);
	testNode = (DataNode*)LinkedList_UnlinkTail(&list);
	if (!testNode)
		return 6;
	if (testNode->Number != 0)
		return 6;

	// Checking itteration
	// populate list
	LinkedList_LinkHead(&list, (Node*)&dataNodes[0]);
	LinkedList_LinkTail(&list, (Node*)&dataNodes[2]);
	LinkedList_LinkTail(&list, (Node*)&dataNodes[4]);
	LinkedList_LinkTail(&list, (Node*)&dataNodes[6]);
	LinkedList_LinkTail(&list, (Node*)&dataNodes[8]);

	// Checking forward links
	testNode = (DataNode*)list.Head;
	for (size_t i = 0; i < NUM_NODES; i += 2)
	{
		if (testNode == NULL)
			return 7;
		if (testNode->Number != i)
			return 7;

		testNode = (DataNode*)testNode->List.Next;
	}

	if (testNode != (DataNode*)list.Head)
		return 7;

	// Checking backward links
	testNode = (DataNode*)list.Tail;
	for (int i = NUM_NODES - 2; i >= 0; i -= 2)
	{
		if (testNode == NULL)
			return 8;
		if (testNode->Number != i)
			return 8;

		testNode = (DataNode*)testNode->List.Prev;
	}

	if (testNode != (DataNode*)list.Tail)
		return 8;

	testNode = (DataNode*)LinkedList_UnlinkHead(&list);
	LinkedList_LinkTail(&list, (Node*)testNode);

	// Checking forward links
	testNode = (DataNode*)list.Head->Prev;
	for (size_t i = 0; i < NUM_NODES; i += 2)
	{
		if (testNode == NULL)
			return 9;
		if (testNode->Number != i)
			return 9;

		testNode = (DataNode*)testNode->List.Next;
	}

	// Checking backward links
	testNode = (DataNode*)list.Tail->Prev;
	for (int i = NUM_NODES - 2; i >= 0; i -= 2)
	{
		if (testNode == NULL)
			return 10;
		if (testNode->Number != i)
			return 10;

		testNode = (DataNode*)testNode->List.Prev;
	}

	return 0;
}
