#include <iostream>

//RUN PROJECT
//cmake should work on docker, am using gnu for development
//to compile use g++ -o executablename main.cpp
//use ./executablename to run

//DEBUGGING
//gdb executablename (no extension)
//type quit to quit gdb
//use -g flag when compiling to allow debugging (g++ main.cpp -g -o executablename.exe)
//it will work without the -g flag but will not be readable by human
//type break plus the method or line u want to break on
//line numbers work too
//type next to step,
//type continue to keep running
//type print varname to print a varible, make sure to dereference pointers to see the value
//to set breakpoint in other files do 
//break filename.extensions:linenumber
//break other.cpp:35
//backtrace tells u where the current method was called from I think?


//idk not working for me
//sanatizer is a memory tracing call. uses a trace allocator so every allocation gets tracked
//flag -fsanitize=address


int main(int argc, char ** agrv){
    std::cout << "Hello World!!!" << std::endl;
}