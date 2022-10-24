
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
![image](https://gyazo.com/676405463d46b5b38bdd1ee14246840a)

- Encoding file
```bash
  python3 b64 -e hello -o encoded
```
- Decoding file
```bash
  python3 b64 -d encoded -o decoded
```
![image](https://gyazo.com/bb7b4a1bdaecf1a9ca3706d91e673f00)
