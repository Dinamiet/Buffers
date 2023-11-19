#	Buffers
Collection of commonly used buffers and storage types

##	Linked List
Circular doubly linked list.

`Nodes` are not dynamically allocated. `Nodes` need to be created before they are added to the list. `Nodes` need to survive for the entire duration they are in the list.

##	Buffered List
Initialized with a preallocated array of `Nodes`. When a `Node` is required the list will provide an available `Node`. If `Node` is unused inform the list and it will be added back to the unused pool to be used later when needed.

##	Fifo buffer
First In First Out buffer. Initialized with a preallocated buffer which then acts as a `FIFO` when adding and removing elements

##	Lifo buffer
Last In First Out buffer. Initialized with a preallocated buffer which then acts as a `LIFO` when adding and removing elements.
