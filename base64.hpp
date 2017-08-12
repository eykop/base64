/*
MIT License

Copyright (c) 2017 Eyas Kopty

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#ifndef BASE64_HPP
#define BASE64_HPP
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
using namespace std;

namespace eykop {

void base64Encode(const std::string &inputString, std::string& encodedString, const bool url_safe_encoding=false)
{
    //init the CODES constant string using lambda method...
    const std::string CODES = [&]{
        std::string selected_codes;
        const std::string REGULAR_CODES     = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
        const std::string URL_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_=";
        if(url_safe_encoding){
            selected_codes = URL_CODES;
        }else{
            selected_codes = REGULAR_CODES;
        }
        return selected_codes;
    }();

    //Convert each char in input string to 8 bits 'byte represntation of given char' - and append to the bitsOfOiginalString variable!
    std::string bitsOfOriginalString;
    for(unsigned int i =0 ; i< inputString.size(); i++){
        bitsOfOriginalString+=std::bitset<8>(inputString[i]).to_string();
    }

    //Calculate Addtions for padding ...
    //if the numbe rof bytes does not devide by 3 then we need to append '0' bit to the last 24 bits block!
    unsigned int startAppendingFromThisBit = bitsOfOriginalString.size();
    unsigned int originalSize= bitsOfOriginalString.size();

    //get how many bytes we have in original string...
    unsigned int bytes = bitsOfOriginalString.size() / 8;

    //calculate how many bits we need to append (for paddings!!!)
    if (bytes%3 != 0 ){

        //bit addtion are calculate of how many missing bytes multiply by 8 are required to complete the last 24 bits block.
        unsigned int bitsAddition = 24 -(bytes%3)*8 ;

        bitsOfOriginalString.resize(bitsOfOriginalString.size() +  bitsAddition);
        for(; startAppendingFromThisBit<bitsOfOriginalString.size(); startAppendingFromThisBit++ ){
            bitsOfOriginalString[startAppendingFromThisBit]= '0';
        }
    }

    std::stringstream outputstream;
    //Encode to base 64 - each 6 bits will be encoded to corresponding char value!
    for(unsigned int i =0 ; i < bitsOfOriginalString.size(); i+=6){

        //get each 6 bits from original string!!!
        std::string sub = bitsOfOriginalString.substr(i,6);

        //before we retrieve the output encoded char - we need to assure its not padding ( zeros added by us above for padding).
        //we know this if current set of 6 bits is above original size then we added those padding bits!!!

        if (std::bitset<6>(sub).to_ulong() == 0 && i  > originalSize){
            outputstream<<"=";
        }else{
            outputstream<<CODES[std::bitset<6>(sub).to_ulong()];
        }

    }
    encodedString = outputstream.str();
}
}
#endif // BASE64_HPP
