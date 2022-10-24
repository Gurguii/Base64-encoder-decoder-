
# Base64 encoder/decoder



## Download

Clone the repository locally  
```bash
  sudo git clone https://github.com/Gurguii/Base64-encoder-decoder-
```
## Usage
```bash
  python3 b64.py -e|-d <string/file> -o* <outputFile>
```
## Testing

- Encoding string
```bash
  python3 b64.py -e "hello world¡¡"
```
- Decoding string
```bash
  python3 b64.py -d "aGVsbG8gd29ybGShoQ=="
```
![imagen](https://user-images.githubusercontent.com/101645735/197558673-6a342812-b772-47d3-b882-849f7d316697.png)


- Encoding file
```bash
  python3 b64 -e hello -o encoded
```
- Decoding file
```bash
  python3 b64 -d encoded -o decoded
```

![imagen](https://user-images.githubusercontent.com/101645735/197558318-1bd48c70-c243-4295-9043-2e710c1a67c5.png)

