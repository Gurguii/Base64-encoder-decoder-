# Base64 encoder/decoder [C++ & Python]  
Allows encoding/decoding a given file/string in Base64.  
*Note: I'm thinking on better code for big files, but I'm not sure if it's gonna work since I'm not implementing bitwise operators, discovered them too late so i decided to go for it this way since I'm gonna practise optimizing, pointers, etc anyway*
# Setup  
- Clone repository
```bash
sudo git clone https://github.com/Gurguii/Base64-encoder-decoder-
```  

- Get into project directory  
```bash
cd Base64-encoder-decoder-
```  
- Compile C++ program  
```bash
g++ b64.cpp -o base -Wno-multichar
```   
*Note: C++ is faster*
# Usage  
**C++**
```base64
./base -d* <string/file>
```  
**Python**
```bash
python3 b64.py -d* <string/file>
```  

The **-d** option means **decode** and It's optional (*)  
- In order to save the result to a file redirect the output:  

```bash
./base "HelloWorld!" > encoded.txt
```  
```bash
./base encoded.txt > decoded.txt
```  
## Dev(xd)notes(problems)
Both programs work with the base64 tool installed in most systems but if you decode with the original tool a file encoded with mine, even tho It will decode and create a complete usable file, it will print an 'invalid input' error. I've been testing a few things using **wc** tool but when I've gotten to same amount of chars by adding '\n' it still shows 'invalid input' so I might be missing something really dummy. 

