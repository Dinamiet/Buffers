#	Buffers
A collection of commonly used buffers and storage types for easy reuse in other project. Aimed at embedded projects, with no dynamic memory allocation.

##	Linked List
Circular doubly linked list.

`Nodes` are not dynamically allocated. `Nodes` need to be created before they are added to the list. `Nodes` need to survive for the entire duration they are in the list.

##	Buffered List
Initialized with a preallocated array of `Nodes`. When a `Node` is required, the list provides an available `Node`. If a `Node` is reported as unused, it is returned to the pool for potential reuse later.

##	Fifo buffer
A First In First Out buffer implemented using a fixed-size buffer. The buffer acts as a FIFO when adding and removing elements.

##	Lifo buffer
A Last In First Out buffer implemented using a fixed-size buffer. The buffer acts as a LIFO when adding and removing elements.

# Building
This project utilizes `CMake` for building and integration with other projects. Custom build configurations are recommended to simplify the process of including this library in your own projects.

# Documentation
Documentation for this project is generated using Doxygen (`CMake` target `docs`) to provide a clear and concise reference for users.
