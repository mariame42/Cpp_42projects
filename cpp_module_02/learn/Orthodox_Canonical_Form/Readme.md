📌 Explanation

Default constructor

Called when you create an object without arguments.

Initializes value to 0.

Copy constructor

Called when you create a new object from an existing one:

Sample a;
Sample b(a);   // copy constructor


Copy assignment operator

Called when you assign one existing object to another:

Sample a;
Sample b;
b = a;   // copy assignment


Destructor

Called automatically when the object goes out of scope or is deleted.

Used to free resources if necessary (not needed here since only int is used).