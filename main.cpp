//MIT License
//Copyright (c) 2017 Eyas Kopty

#include "base64.hpp"
int main()
{

    const std::string str = "Join GitHub today\r\nGitHub is home to over 20 million developers working together to host and review code, manage projects, and build software together.";
    std::string output;
    eykop::base64Encode(str,output);
    std::cout<<output<<std::endl;
    return 0;
}
