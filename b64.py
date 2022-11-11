#############################
#   BASE64 ENCODER/DECODER  #
######################################
# Author: Gurgui                     #
# Github: https://github.com/Gurguii #
######################################
import sys
import os
ascii_table_chars = (' ', '!', '"', '#', '$', '%', '&', "'", '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', 'DEL', '¡', '¢', '£', '¤', '¥', '¦', '§', '¨', '©', 'ª', '«', '¬', '®', '¯', '°', '±', '²', '³', '´', 'µ', '¶', '·', '¸', '¹', 'º', '»', '¼', '½', '¾', '¿', 'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ð', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ú', 'Û', 'Ü', 'Ý', 'Þ', 'ß', 'à', 'á', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ý', 'þ', 'ÿ')
ascii_table_codes = ('00100000', '00100001', '00100010', '00100011', '00100100', '00100101', '00100110', '00100111', '00101000', '00101001', '00101010', '00101011', '00101100', '00101101', '00101110', '00101111', '00110000', '00110001', '00110010', '00110011', '00110100', '00110101', '00110110', '00110111', '00111000', '00111001', '00111010', '00111011', '00111100', '00111101', '00111110', '00111111', '01000000', '01000001', '01000010', '01000011', '01000100', '01000101', '01000110', '01000111', '01001000', '01001001', '01001010', '01001011', '01001100', '01001101', '01001110', '01001111', '01010000', '01010001', '01010010', '01010011', '01010100', '01010101', '01010110', '01010111', '01011000', '01011001', '01011010', '01011011', '01011100', '01011101', '01011110', '01011111', '01100000', '01100001', '01100010', '01100011', '01100100', '01100101', '01100110', '01100111', '01101000', '01101001', '01101010', '01101011', '01101100', '01101101', '01101110', '01101111', '01110000', '01110001', '01110010', '01110011', '01110100', '01110101', '01110110', '01110111', '01111000', '01111001', '01111010', '01111011', '01111100', '01111101', '01111110', '01111111', '10100001', '10100010', '10100011', '10100100', '10100101', '10100110', '10100111', '10101000', '10101001', '10101010', '10101011', '10101100', '10101110', '10101111', '10110000', '10110001', '10110010', '10110011', '10110100', '10110101', '10110110', '10110111', '10111000', '10111001', '10111010', '10111011', '10111100', '10111101', '10111110', '10111111', '11000000', '11000001', '11000010', '11000011', '11000100', '11000101', '11000110', '11000111', '11001000', '11001001', '11001010', '11001011', '11001100', '11001101', '11001110', '11001111', '11010000', '11010001', '11010010', '11010011', '11010100', '11010101', '11010110', '11010111', '11011000', '11011001', '11011010', '11011011', '11011100', '11011101', '11011110', '11011111', '11100000', '11100001', '11100010', '11100011', '11101001', '11100101', '11100110', '11100111', '11101000', '11101001', '11101010', '11101011', '11101100', '11101101', '11101110', '11101111', '11110000', '11110001', '11110010', '11110011', '11110100', '11110101', '11110110', '11110111', '11111000', '11111001', '11111010', '11111011', '11111100', '11111101', '11111110', '11111111')

base64_table_codes = ('000000', '000001', '000010', '000011', '000100', '000101', '000110', '000111', '001000', '001001', '001010', '001011', '001100', '001101', '001110', '001111', '010000', '010001', '010010', '010011', '010100', '010101', '010110', '010111', '011000', '011001', '011010', '011011', '011100', '011101', '011110', '011111', '100000', '100001', '100010', '100011', '100100', '100101', '100110', '100111', '101000', '101001', '101010', '101011', '101100', '101101', '101110', '101111', '110000', '110001', '110010', '110011', '110100', '110101', '110110', '110111', '111000', '111001', '111010', '111011', '111100', '111101', '111110', '111111')
base64_table_chars = ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/')

def usage():
    print(f"""
    Base64 encoder/decoder:
    Usage: python3 {sys.argv[0]} <options> <string/file>
    Github: Gurguii

    [ Options ]
    -h / --help - display this message and exit
    -o <file>  - desired output file
    -d - decode mode (by default the script encodes given data)""")

def fileCheck():
    global data

    if os.path.exists(data):
        with open(data,"r") as file:
            if not file.readable():
                print(f"File {filename} not readable")
                exit(0)
            return 1
    return 0

def encodeString():
    global data

    base64_table = dict(zip(base64_table_codes,base64_table_chars))
    ascii_table = dict(zip(ascii_table_chars,ascii_table_codes))
    ascii_table_user = ""
    result = ""
    n = 0
    for char in data:
        ascii_table_user+=ascii_table[char]

    while len(ascii_table_user) > 0:
        try:
            result+=base64_table[ascii_table_user[:6]]
            ascii_table_user = ascii_table_user[6:]
            n+=1
        except:
            result+=base64_table[ascii_table_user+"0"*(6-len(ascii_table_user))]
            n+=1
            break

    if 4-n%4 != 4:
        result+="="*(4-n%4)

    print(result)

def decodeString():
    global data

    base64_table = dict(zip(base64_table_chars,base64_table_codes))
    ascii_table = dict(zip(ascii_table_codes,ascii_table_chars))
    base64_codes = ""
    result = ""

    for char in data:
        try:
            base64_codes+=(base64_table[char])
        except:
            pass

    while len(base64_codes) > 0:
        try:
            result+=ascii_table[base64_codes[:8]]
            base64_codes = base64_codes[8:]
        except:
            break

    print(result)
    
def encodeFile():
    global data

    encode_table = dict(zip(base64_table_codes,base64_table_chars))
    binaryList = ""
    result = ""
    n = 0
    with open(data,"rb") as file:
        for n in list(file.read()):
            binaryList+=bin(n)[2:].zfill(8)

    while len(binaryList) > 0:
        try:
            result+=encode_table[binaryList[:6]]
            binaryList = binaryList[6:]
            n+=1
        except:
            n+=1
            break

    padding = 4-n%4
    if padding!=4:
        result+="="*padding

    print(result)


def decodeFile():
    global data

    decodeTable = dict(zip(base64_table_chars,base64_table_codes))
    bits = ""
    result = []

    with open(data,"r") as file:
        for i in file.read():
            try:
                bits+=decodeTable[i]
            except:
                continue

    while len(bits)!=0:
        try:
            result.append(int(bits[:8],2))
            bits = bits[8:]
        except:
            break

    sys.stdout.buffer.write(bytes(result))

## PARSE ARGUMENTS
data = sys.argv[-1]
encode = 1

if len(sys.argv) < 2:
    usage()
    exit(0)

for i in sys.argv:
    if i == "-h" or i == "--help":
        usage()
        exit(0)
    elif i == "-d" or i == "--decode":
        encode = 0

if fileCheck():
    if encode:
        encodeFile()
    else:
        decodeFile()
else:
    if encode:
        encodeString()
    else:
        decodeString()
