#include "bufferedlist.h"
#include <stdio.h>

#define NUM_NODES 10

typedef struct
{
	Node	 List;
	uint32_t Number;
} DataNode;

int main(int argc, char* argv[])
{
	DataNode dataNodes[NUM_NODES];

	BufferedList list;
	BufferedList_Init(&list, (Node*)dataNodes, sizeof(DataNode), NUM_NODES);

	DataNode* testNode;

	// Unlink with empty list
	testNode = (DataNode*)BufferedList_UnlinkHead(&list);
	if (testNode != NULL)
		return 1;

	// Unlink with empty list
	testNode= (DataNode*)BufferedList_UnlinkTail(&list);
	if (testNode != NULL)
		return 1;

	// Add data to buffer tail
	testNode= (DataNode*)BufferedList_LinkTail(&list);
	testNode->Number= 80;

	// Add data to buffer head
	testNode= (DataNode*)BufferedList_LinkHead(&list);
	testNode->Number= 50;

	// Add data to buffer to tail
	testNode= (DataNode*)BufferedList_LinkTail(&list);
	testNode->Number= 20;

	// Add data to buffer head
	testNode= (DataNode*)BufferedList_LinkHead(&list);
	testNode->Number= 10;

	// Check if unlinking is correct
	testNode= (DataNode*)BufferedList_UnlinkHead(&list);
	if (testNode == NULL)
		return 2;
	if (testNode->Number != 10)
		return 2;

	testNode= (DataNode*)BufferedList_UnlinkHead(&list);
	if (testNode == NULL)
		return 3;
	if (testNode->Number != 50)
		return 3;

	testNode= (DataNode*)BufferedList_UnlinkTail(&list);
	if (testNode == NULL)
		return 4;
	if (testNode->Number != 20)
		return 4;

	testNode= (DataNode*)BufferedList_UnlinkTail(&list);
	if (testNode == NULL)
		return 5;
	if (testNode->Number != 80)
		return 5;


	//Check if list is empty
	testNode= (DataNode*)BufferedList_UnlinkTail(&list);
	if (testNode != NULL)
		return 6;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		testNode= (DataNode*)BufferedList_LinkTail(&list);
		if (testNode == NULL)
			return 7;
		testNode->Number= i;
	}

	// Should not be able to add this one
	testNode= (DataNode*)BufferedList_LinkTail(&list);
		if (testNode != NULL)
			return 8;

	testNode= (DataNode*)BufferedList_LinkHead(&list);
		if (testNode != NULL)
			return 8;

	// Empty buffer again
	for (size_t i = 0; i < NUM_NODES; i++)
	{
		testNode= (DataNode*)BufferedList_UnlinkHead(&list);
		if (testNode == NULL)
			return 9;
		if (testNode->Number != i)
			return 9;
	}

	//Buffer should be empty
	testNode= (DataNode*)BufferedList_UnlinkHead(&list);
	if (testNode != NULL)
		return 10;

	testNode= (DataNode*)BufferedList_UnlinkTail(&list);
	if (testNode != NULL)
		return 10;


	return 0;
}
