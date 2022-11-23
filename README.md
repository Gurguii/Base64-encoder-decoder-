# Base64 encoder/decoder [C++ & Python]  
Allows encoding/decoding a given file/string using Base64 concept. Not reccomended as a substitute of base64 tool installed in most systems by default.
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
./base -d encoded.txt > decoded.txt
```  
## Dev notes
Both programs work themselves but got some incompatibilities with base64 tool since I don't add any LF (Unix) or CRLF (Windows).  On one hand my encode is slightly lighter due to the absence of '\n' and '\r\n'. On the other hand it performs slower than base64 tool, more noticeable with bigger sizes.

