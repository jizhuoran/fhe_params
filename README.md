For each param, use write_file.hpp to save c++ array/vector to file. The format is ```inline int write_data(std::string name, std::vector<size_t> shape, uint64_t* data)```. You need and only need give a name to array.

Then, execute "compact.py". All written files will be compact to a single npz, that can be easily load in python.


