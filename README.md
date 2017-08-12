I always wondered how the base64 works , 
and how different libraries implement base64 encoder decoder,
for example boost and others...

There is the same code moving around the forums and internet specially on stackoverflow 
to perform encoding and decoding but it more c than c++.
I find that code hard to understand and is not documented.

So I followed the wiki pedia page https://en.wikipedia.org/wiki/Base64 
to understand how the base64 works and how can I encode and decode.

Once I understood the idea it was easy to implement.

About the implemenation:
The main idea is how to get each char from an input string and shrink that 8 bits to 6 bits
in order to calculate the base64 code for those 6 bits value.
I used std::bitset something I didn't see otherlibrary use when performing base64.

I tryied to add the padding of '=' at end - its working fine I guess.

TODO LIST:
1. Add a decoder code.
2. Add tests.
3. This is a qtcreator project for now.
   I will add a makefile to remove dependency on qtcreator later.

I didn't test the code deeply - just used several strings and encoded that with online base encoders 
and compared the reuslts it looks working just find - it still need more testing something which I plan to add.




