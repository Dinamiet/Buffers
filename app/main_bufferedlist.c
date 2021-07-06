#include "bufferedlist.h"

#include <stdio.h>

#define NUM_NODES		 10
#define TEST_BUFFER_SIZE 5

typedef struct
{
	Node	 Link;
	uint32_t Number;
} DataNode;

int main()
{
	DataNode dataNodes[NUM_NODES];

	BufferedList list;
	BufferedList_Init(&list, &dataNodes->Link, sizeof(DataNode), NUM_NODES);

	DataNode* testNode;

	// Unlink with empty list
	testNode = BufferedList_UnlinkHead(&list);
	if (testNode != NULL)
		return 1;

	// Unlink with empty list
	testNode = BufferedList_UnlinkTail(&list);
	if (testNode != NULL)
		return 1;

	// Add data to buffer tail
	testNode		 = BufferedList_LinkTail(&list);
	testNode->Number = 80;

	// Add data to buffer head
	testNode		 = BufferedList_LinkHead(&list);
	testNode->Number = 50;

	// Add data to buffer to tail
	testNode		 = BufferedList_LinkTail(&list);
	testNode->Number = 20;

	// Add data to buffer head
	testNode		 = BufferedList_LinkHead(&list);
	testNode->Number = 10;

	// Check if unlinking is correct
	testNode = BufferedList_UnlinkHead(&list);
	if (testNode == NULL)
		return 2;
	if (testNode->Number != 10)
		return 2;

	testNode = BufferedList_UnlinkHead(&list);
	if (testNode == NULL)
		return 3;
	if (testNode->Number != 50)
		return 3;

	testNode = BufferedList_UnlinkTail(&list);
	if (testNode == NULL)
		return 4;
	if (testNode->Number != 20)
		return 4;

	testNode = BufferedList_UnlinkTail(&list);
	if (testNode == NULL)
		return 5;
	if (testNode->Number != 80)
		return 5;

	//Check if list is empty
	testNode = BufferedList_UnlinkTail(&list);
	if (testNode != NULL)
		return 6;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		testNode = BufferedList_LinkTail(&list);
		if (testNode == NULL)
			return 7;
		testNode->Number = i;
	}

	// Should not be able to add this one
	testNode = BufferedList_LinkTail(&list);
	if (testNode != NULL)
		return 8;

	testNode = BufferedList_LinkHead(&list);
	if (testNode != NULL)
		return 8;

	// Empty buffer again
	for (size_t i = 0; i < NUM_NODES; i++)
	{
		testNode = BufferedList_UnlinkHead(&list);
		if (testNode == NULL)
			return 9;
		if (testNode->Number != i)
			return 9;
	}

	//Buffer should be empty
	testNode = BufferedList_UnlinkHead(&list);
	if (testNode != NULL)
		return 10;

	testNode = BufferedList_UnlinkTail(&list);
	if (testNode != NULL)
		return 10;

	// Testing node unlink which is not on head or tail
	testNode		  = BufferedList_LinkTail(&list);
	DataNode* delete1 = testNode;
	testNode->Number  = 5;
	testNode		  = BufferedList_LinkTail(&list);
	DataNode* delete3 = testNode;
	testNode->Number  = 10;
	testNode		  = BufferedList_LinkHead(&list);
	DataNode* delete2 = testNode;
	testNode->Number  = 2;
	testNode		  = BufferedList_LinkTail(&list);
	testNode->Number  = 15;
	testNode		  = BufferedList_LinkHead(&list);
	testNode->Number  = 0;

	uint32_t testBuffer[TEST_BUFFER_SIZE] = {0, 2, 5, 10, 15};

	testNode = (DataNode*)list.Used.Head;
	for (size_t i = 0; i < 2 * TEST_BUFFER_SIZE; i++)
	{
		if (testNode->Number != testBuffer[i % TEST_BUFFER_SIZE])
		{
			return 10 + i;
		}
		testNode = (DataNode*)testNode->Link.Next;
	}

	testNode = BufferedList_UnlinkNode(&list, &delete1->Link);
	if (testNode != delete1)
	{
		return 20;
	}
	if (testNode->Number != 5)
	{
		return 20;
	}

	testNode = (DataNode*)list.Used.Head;
	for (size_t i = 0; i < 2 * TEST_BUFFER_SIZE; i++)
	{
		if (testBuffer[i % TEST_BUFFER_SIZE] == 5)
			continue;
		if (testNode->Number != testBuffer[i % TEST_BUFFER_SIZE])
		{
			return 20 + i;
		}
		testNode = (DataNode*)testNode->Link.Next;
	}

	testNode = BufferedList_UnlinkNode(&list, &delete2->Link);
	if (testNode != delete2)
	{
		return 30;
	}
	if (testNode->Number != 2)
	{
		return 30;
	}

	testNode = (DataNode*)list.Used.Head;
	for (size_t i = 0; i < 2 * TEST_BUFFER_SIZE; i++)
	{
		if (testBuffer[i % TEST_BUFFER_SIZE] == 5 || testBuffer[i % TEST_BUFFER_SIZE] == 2)
			continue;
		if (testNode->Number != testBuffer[i % TEST_BUFFER_SIZE])
		{
			return 30 + i;
		}
		testNode = (DataNode*)testNode->Link.Next;
	}

	testNode = BufferedList_UnlinkNode(&list, &delete3->Link);
	if (testNode != delete3)
	{
		return 40;
	}
	if (testNode->Number != 10)
	{
		return 40;
	}

	testNode = (DataNode*)list.Used.Head;
	for (size_t i = 0; i < 2 * TEST_BUFFER_SIZE; i++)
	{
		if (testBuffer[i % TEST_BUFFER_SIZE] == 5 || testBuffer[i % TEST_BUFFER_SIZE] == 2 || testBuffer[i % TEST_BUFFER_SIZE] == 10)
			continue;
		if (testNode->Number != testBuffer[i % TEST_BUFFER_SIZE])
		{
			return 40 + i;
		}
		testNode = (DataNode*)testNode->Link.Next;
	}

	testNode = BufferedList_UnlinkNode(&list, list.Used.Head);
	if (testNode == (DataNode*)list.Used.Head)
	{
		return 40;
	}
	if (testNode->Number != 0)
	{
		return 40;
	}

	testNode = (DataNode*)list.Used.Head;
	for (size_t i = 0; i < 3; i++)
	{
		if (testNode->Number != testBuffer[TEST_BUFFER_SIZE - 1])
		{
			return 40 + i;
		}
		testNode = (DataNode*)testNode->Link.Next;
	}

	printf("SUCC\n");
	return 0;
}
