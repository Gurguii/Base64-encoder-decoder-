#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cctype>
#include <map>
#include <cmath>

/*Required variables*/
std::string outfile = "";
int encode = 1;

int ascii_table_chars[] = {' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', 'DEL', '¡', '¢', '£', '¤', '¥', '¦', '§', '¨', '©', 'ª', '«', '¬', '®', '¯', '°', '±', '²', '³', '´', 'µ', '¶', '·', '¸', '¹', 'º', '»', '¼', '½', '¾', '¿', 'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ð', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ú', 'Û', 'Ü', 'Ý', 'Þ', 'ß', 'à', 'á', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ý', 'þ', 'ÿ'};
std::string ascii_table_codes[] = {"00100000", "00100001", "00100010", "00100011", "00100100", "00100101", "00100110", "00100111", "00101000", "00101001", "00101010", "00101011", "00101100", "00101101", "00101110", "00101111", "00110000", "00110001", "00110010", "00110011", "00110100", "00110101", "00110110", "00110111", "00111000", "00111001", "00111010", "00111011", "00111100", "00111101", "00111110", "00111111", "01000000", "01000001", "01000010", "01000011", "01000100", "01000101", "01000110", "01000111", "01001000", "01001001", "01001010", "01001011", "01001100", "01001101", "01001110", "01001111", "01010000", "01010001", "01010010", "01010011", "01010100", "01010101", "01010110", "01010111", "01011000", "01011001", "01011010", "01011011", "01011100", "01011101", "01011110", "01011111", "01100000", "01100001", "01100010", "01100011", "01100100", "01100101", "01100110", "01100111", "01101000", "01101001", "01101010", "01101011", "01101100", "01101101", "01101110", "01101111", "01110000", "01110001", "01110010", "01110011", "01110100", "01110101", "01110110", "01110111", "01111000", "01111001", "01111010", "01111011", "01111100", "01111101", "01111110", "01111111", "10100001", "10100010", "10100011", "10100100", "10100101", "10100110", "10100111", "10101000", "10101001", "10101010", "10101011", "10101100", "10101110", "10101111", "10110000", "10110001", "10110010", "10110011", "10110100", "10110101", "10110110", "10110111", "10111000", "10111001", "10111010", "10111011", "10111100", "10111101", "10111110", "10111111", "11000000", "11000001", "11000010", "11000011", "11000100", "11000101", "11000110", "11000111", "11001000", "11001001", "11001010", "11001011", "11001100", "11001101", "11001110", "11001111", "11010000", "11010001", "11010010", "11010011", "11010100", "11010101", "11010110", "11010111", "11011000", "11011001", "11011010", "11011011", "11011100", "11011101", "11011110", "11011111", "11100000", "11100001", "11100010", "11100011", "11101001", "11100101", "11100110", "11100111", "11101000", "11101001", "11101010", "11101011", "11101100", "11101101", "11101110", "11101111", "11110000", "11110001", "11110010", "11110011", "11110100", "11110101", "11110110", "11110111", "11111000", "11111001", "11111010", "11111011", "11111100", "11111101", "11111110", "11111111"};


std::string base64_table_codes[] = {"000000", "000001", "000010", "000011", "000100", "000101", "000110", "000111", "001000", "001001", "001010", "001011", "001100", "001101", "001110", "001111", "010000", "010001", "010010", "010011", "010100", "010101", "010110", "010111", "011000", "011001", "011010", "011011", "011100", "011101", "011110", "011111", "100000", "100001", "100010", "100011", "100100", "100101", "100110", "100111", "101000", "101001", "101010", "101011", "101100", "101101", "101110", "101111", "110000", "110001", "110010", "110011", "110100", "110101", "110110", "110111", "111000", "111001", "111010", "111011", "111100", "111101", "111110", "111111"};
char base64_table_chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

void help()
{
    std::cout << "Base64 encoder/decoder\n";
    std::cout << "Usage: base <options> <string|file>\n";
    std::cout << "Options:\n-o - output file\n-d - decode mode\n-h - display this message";
}
std::string decToBinary(int n)
{
    std::string binary = "";
    for (int i = 7; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            binary+="1";
        else
            binary+="0";
    }
    return binary;
}
int binToDec(int bin)
{
   int n = 0, dec = 0;
   while(bin!=0)
   {
      dec+=bin%10 * pow(2,n);
      bin/=10;
      n+=1;
   }
   return dec;
}
void encodeString(std::string *data)
{   
    /*Initialize variables*/
    std::string result = "";
    std::map<std::string,char> base64Table;
    std::map<int,std::string> asciiTable;
    std::string binaryRep = "";
    std::vector<std::string> bit6;
    std::vector<std::string> base64_result;

    /*Create base64Table*/
    for(int i = 0 ; i < 64 ; i++)
    {
        base64Table.insert(std::pair<std::string,char>(base64_table_codes[i],base64_table_chars[i]));
    }

    /*Create asciiTable*/
    for(int i = 0 ; i < 190 ; i++)
    {
        asciiTable.insert(std::pair<int,std::string>(ascii_table_chars[i],ascii_table_codes[i]));
    }

    /*Start encoding*/
    for(char c : *data)
    {
        binaryRep += asciiTable[c];
    }

    /*Create groups of 6 bits*/
    while(binaryRep.size() >= 6)
    {
        bit6.push_back(binaryRep.substr(0,6));
        binaryRep=binaryRep.substr(6);
    }
    int diff = 6-binaryRep.size();
    for(int i = 0 ; i < diff ; i++)
    {
        binaryRep+="0";
    }
    bit6.push_back(binaryRep);

    /*Iterate over groups of 6 bits and storage BASE64 representation*/
    for(std::string code : bit6)
    {   
        result+=base64Table[code]; 
    }
    
    /*Add padding*/
    int padding = bit6.size()%4;
    if (padding != 4)
    {
        for (int i = 0 ; i < padding ; i ++)
        {
            result+="=";
        }
    }

    /*Check if user wants the output in a file, else print it to stdout*/
    if(!outfile.empty())
    {
        std::ofstream file(outfile);
        if (file.is_open() && file.good())
        {
            file << result;
        }
        std::cout << "Encode saved at file " << std::filesystem::current_path() << "\\" << outfile << "\n";
    }
    else
    {
        std::cout << result << "\n";
    }
}

void decodeString(std::string *data)
{
    // Base64 -> 6bits -> 8bits -> ascii
    /*Initialize variables*/
    std::string result = "";
    /*Create key-value maps according to what we need*/
    std::map<char,std::string> base64Table;
    std::map<std::string,int> asciiTable;
    /*base64Table map*/
    for(int i = 0 ; i < 64 ; i++ )
    {
        base64Table.insert(std::pair<char,std::string>(base64_table_chars[i],base64_table_codes[i]));
    }
    /*asciiTable map*/
    for(int i = 0 ; i < 190 ; i++)
    {
        asciiTable.insert(std::pair<std::string,int>(ascii_table_codes[i],ascii_table_chars[i]));
    }
    /**/
    std::string b64Converted = "";
    for(char c : *data)
    {
        b64Converted+=base64Table[c];
    }
    /**/
    std::string bit6 = "";
    while(b64Converted.size() > 0)
    {
        bit6+=b64Converted.substr(0,6);
        b64Converted=b64Converted.substr(6);
    }
    /**/
    std::vector<std::string> bit8;
    while(bit6.size() >= 8)
    {
        bit8.push_back(bit6.substr(0,8));
        bit6=bit6.substr(8);
    }
    /**/
    for(std::string str : bit8)
    {
        result+=asciiTable[str];
    }
    /**/
    if(!outfile.empty())
    {
        std::ofstream file(outfile);
        if(file.is_open() && file.good())
        {
            file << result;
            std::cout << "Decoded string saved at " << std::filesystem::current_path() << "\\" << outfile << "\n";
        }
    }else
    {
        std::cout << result << "\n";
    }
}

void encodeFile(std::ifstream *file)
{
    std::map<std::string,char>table;
    for (int i = 0 ; i < 64 ; i++)
    {
        table.insert(std::pair<std::string,char>(base64_table_codes[i],base64_table_chars[i]));
    }

    std::vector<char> *buffer = new std::vector<char>;

    file->seekg(0,file->end);
    size_t len = file->tellg();
    file->seekg(0,file->beg);

    if(len > 0)
    {
        buffer->resize(len);
        file->read(&buffer->at(0),len);
    }

    std::stringstream *bits = new std::stringstream;

    for(int byte : *buffer)
    {   
        *bits << decToBinary(byte);       
    }
    
    std::string result;
    std::string bit6(6,'\0');
    
    while(bits->read(&bit6[0],bit6.size()))
    {
        result+=table[bit6];
    }
    /*Add last byte*/
    bit6.erase(buffer->size()%6);
    for(int i = 0 ; i < 6-buffer->size()%6 ; i++)
    {
        bit6+="0";
    }
    result+=table[bit6];
    /*Add padding*/
    for(int i = 0 ; i < buffer->size()/6%4 ; i++)
    {
        result+="==";
    }
    int *n = new int(76);
    std::string *crlf = new std::string{"\r\n"};
    while(*n < result.size())
    {
        result.insert(*n,*crlf);
        *n+=78;
    }
    delete buffer;
    delete n;
    delete crlf;
    /*Check output source*/
    if(!outfile.empty())
    {
        std::ofstream file(outfile);
        if(file.is_open() && file.good())
        {
            file << result;
            std::cout << "Encoded file saved at " << std::filesystem::current_path() << "\\" << outfile << "\n";
        }
    }else
    {
        std::cout << result;
    }
}

void decodeFile(std::ifstream *file)
{
    std::map<char,std::string> table;
    for(int i = 0 ; i < 64 ; i++)
    {
        table.insert(std::pair<char,std::string>(base64_table_chars[i],base64_table_codes[i]));
    }

    std::vector<char> *buffer = new std::vector<char>;

    file->seekg(0,file->end);
    size_t len = file->tellg();
    file->seekg(0,file->beg);
    
    if(len > 0)
    {
        buffer->resize(len);
        file->read(&buffer->at(0),len);
        file->close();
    }

    std::stringstream *bits = new std::stringstream;
    for(char c: *buffer)
    {
        *bits << table[c];
    }

    std::vector<char> *data = new std::vector<char>;
    std::string bit8(8,'\0');

    while(bits->read(&bit8[0],bit8.size()))
    {
        data->push_back(binToDec(std::stoi(bit8)));
    }
    
    if(!outfile.empty())
    {   
        std::ofstream file(outfile,std::ios::binary);
        if(file.is_open() && file.good())
        {
            file.write(&data->at(0),data->size());
            std::cout << "Decoded file saved at " << std::filesystem::current_path() << "\\" << outfile;
        }
    }else
    {
        for(char c : *data)
        {
            std::cout << c;
        }
    }
}

int main(int argc, char **argv)
{
    std::string data = argv[argc-1];
    
    /*Parse arguments*/
    std::stringstream *args = new std::stringstream;
    std::string *opt = new std::string;
    for(int i = 1 ; i < argc ; i++)
    {
        *args << argv[i] << ' ';
    }
    while(!args->eof())
    {
        *args >> *opt;  
        if(*opt == "-d" || *opt == "decode")
        {
            encode = 0;
        }
        else if (*opt == "-o" || *opt == "-output")
        {
            *args >> outfile;
        }
        else if (*opt == "-h" || *opt == "-help")
        {
            help();
            exit(0);
        }
    }
    delete args;
    delete opt;

    /*Check if inputted data source is a file*/
    std::filesystem::path file(data);
    if(std::filesystem::is_regular_file(file))
    {
        std::ifstream filestream(file,std::ios::binary);
        if (filestream.good())
        {
            encode ? encodeFile(&filestream) : decodeFile(&filestream);
            exit(0);
        }
    }

    /*Check if inputted data is a printable string*/
    for(char c : data)
    {
        if(!isprint(c))
        {
            std::cout << "[!] - Found non-printable character\n";
            std::cout << "[-] Exiting...\n";
            help();
        }
    }

    /*At this point we know it's a string so we check encode variable status and call encode/decode*/
    encode ? encodeString(&data) : decodeString(&data);
    return 0;
}
