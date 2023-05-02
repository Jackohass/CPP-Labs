#include <iostream>
#include <cstdlib>
#include <cctype>

#include "hello.h"

void hello (const char * name, int count) {
    if(!count) return;
    std::cout << "Hello,";
    for (int i = 0; i < count; i++)
    {
        std::cout << " " << name;
    }
    std::cout << "!" << std::endl;
}

std::pair<const char *, int> parse_args (int argc, char * argv[]) {
    switch(argc)
    {
        case 1:
            return std::make_pair ("world", 1);
        break;

        case 2:
            return std::make_pair (argv[1], 1);
        break;
        
        case 3:
            if(isdigit(argv[2][0]))
            {
                int temp = atoi(argv[2]);
                if(temp > -1) return std::make_pair (argv[1], temp);
            }
            std::cerr << "error: 2nd argument must be an integral greater than zero!" << std::endl;
            return std::make_pair (argv[1], -1);
        break;

        default:
            std::cerr << "error: Too many arguments!" << std::endl;
            return std::make_pair (argv[1], -1);
        break;
    }
}