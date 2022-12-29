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
```bash
g++ -std=c++20 <file_chosen> -o <executable_name>
```  
Note: When using base64C++20 '-std=C++20' is required, when using base64C++17 '-std=C++17' is required.
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
