# [C++] - Base64 encoder/decoder  

## Description  
Program that allows base64 encoding and decoding text/file.  
## Setup  
Clone de project  
```bash
git clone https://github.com/Gurguii/Base64-encoder-decoder-
```  
Get into the project directory  
```bash
cd Base64-encoder-decoder-
```  
Compile  

Compiling C++20 version(just change both 20 depending on the file you want to compile)
```bash
g++ -std=c++20 base64_C++20.cpp -o <executable_name_you_desire>
```  
## Encoding

```bash
./base <file|string>
```  
## Decoding
```bash  
./base -d <file|string>
```  
or 
```bash
./base <file|string> -d  
```  

## Output
Encoded/decoded data will be printed so in order to save output to file just redirect it:  
***./base "hello world¡" > [filename]***
