# Chess in Python and C++

This is a dummy project where I am trying to implement chess in C++ and then also make it usable in Python as a module. This is mostly done to teach me self some more C++, as well as for the reason that all chess operations will run faster in C++ than what they will in Python, meaning that if I wanna mess around with some AI stuff with Python, this will hopefully speed that up considerably.

I use pybind11 in this project in order to package the C++ stuff into a module that is usable in Python.

## Build

In order to build this into a module, enter the `build` folder and then type `cmake ..` and `make`. This will build a new .so-file, which then can be imported in Python. In the case of this project, it can be imported as `chess_module`, as seen in `main.py`.

As you change methods in the C++ files, you have to add them to the actual Python module explicitly. This is currently done in the `tester.cc` file, but we'll see what I do with it in the future. Currently it seems to work, but I am far from done with my implementation.
