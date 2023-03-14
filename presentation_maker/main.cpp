#include "Context.h"
#include <iostream>

int main(int argc, char** argv)
{
    try
    {
        Context context;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Abort." << std::endl;
    }
    
    return EXIT_SUCCESS;
}
