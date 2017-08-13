//MIT License
//Copyright (c) 2017 Eyas Kopty

#include "base64.hpp"


int main()
{

    const std::string str = "Join GitHub today\r\nGitHub is home to over 20 million developers working together to host and review code, manage projects, and build software together.";
    std::string output;
    eykop::base64Encode(str,output);
    std::cout<<output<<std::endl;

    //Convert each char in input string to 6 bits - Base64's code bits length' -
    //and append to the bitsOfOiginalString variable!
    eykop::base64Decode(output, output);
    std::cout<<std::endl;
    std::cout<<output<<std::endl;
    return 0;
}
