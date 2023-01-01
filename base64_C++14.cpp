#include <string>
#include <vector>
#include <fstream>

using str = std::string;
using vector_uint8t = std::vector<uint8_t>;

str b64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

auto ISFILE = [](auto filename){return std::ifstream(filename).good();};

auto COUNT = [](auto data, char ch){
    int n = 0;
    for(char c : data)
    {
        n += (c == ch) ? 1 : 0;
    }
    return n;
};

auto FILE_SIZE = [](auto filename)
{
    std::ifstream file(filename);
    file.seekg(0, file.end);
    int n = file.tellg();
    file.seekg(0, file.beg);
    return n;
};

template<typename T> void b64_encode(T data)
{
    int iters = data.size()/3;
    uint32_t bits;
   
    for(int i = 0, j = 0 ; j < iters ; i+=3, j++)
    {
        bits = ((data[i] << 16)) | ((data[i+1] << 8)) | (data[i+2]);

        printf("%c%c%c%c",  b64_table[(bits >> 18) & 0x3f],
                            b64_table[(bits >> 12) & 0x3f],
                            b64_table[(bits >> 6) & 0x3f],
                            b64_table[(bits >> 0) & 0x3f]
        );
    }

    if(int rest = data.size()%3)
    {
        if(rest == 1)
        {        
            uint16_t bits = data[iters*3] << 4;
            printf("%c%c==",  b64_table[(bits >> 6) & 0x3f],
                              b64_table[(bits >> 0) & 0x3f]);
        }
        else{
            uint32_t bits = (data[iters*3] << 10) | (data[iters*3+1] << 2);
            printf("%c%c%c=",   b64_table[(bits >> 12) & 0x3f],
                                b64_table[(bits >> 6) & 0x3f],
                                b64_table[(bits >> 0) & 0x3f]);
        }
    }
}

template <typename T> void b64_decode(T data)
{   
    int iters = data.size()/4;
    uint32_t bits;

    for(int i = 0, j = 0; j < iters-1; i+=4, j++)
    {
        bits = (b64_table.find(data[i]) << 18) | (b64_table.find(data[i+1]) << 12) | (b64_table.find(data[i+2]) << 6) | (b64_table.find(data[i+3]));
        printf("%c%c%c", ((bits >> 16) & 0xff),
                        ((bits >> 8) & 0xff),
                        ((bits >> 0) & 0xff)); 
    }

    str last4(&data[data.size()-4], 4);

    if(int padd = COUNT(last4, '='))
    {
        if(padd == 1)
        {
            uint32_t bits = (b64_table.find(last4[0]) << 18 | (b64_table.find(last4[1]) << 12 | (b64_table.find(last4[2]) << 6)));
            printf("%c%c%c",((bits >> 16) & 0xff), 
                            ((bits >> 8) & 0xff), 
                            ((bits >> 0) & 0xff));
        }
        else if(padd == 2)
        {
            uint16_t bits = (b64_table.find(last4[0]) << 10) | (b64_table.find(last4[1]) << 4);
            printf("%c%c",  ((bits >> 8) & 0xff),
                            ((bits >> 0) & 0xff));            
        }
        return;
    }
    
    bits = (b64_table.find(last4[0]) << 18) | (b64_table.find(last4[1]) << 12) | (b64_table.find(last4[2]) << 6) | (b64_table.find(last4[3]));
    printf("%c%c%c",((bits >> 16) & 0xff),
                    ((bits >> 8) & 0xff),
                    ((bits >> 0) & 0xff));
}

int main(int argc, const char *args[])
{
    int decode{0};
    str data;
    for(str arg : std::vector<const char*>(&args[1], &args[argc]))
    {
        if(arg == "-d" || arg == "--decode")
        {
            decode = 1;
            continue;
        }
        data = arg;
    }
    
    if(ISFILE(data))
    {
        if(decode)
        {
            str buffer(FILE_SIZE(data), '\x00');
            std::ifstream(data, std::ios::in).read(&buffer[0], buffer.size());
            b64_decode<str>(buffer);
        }
        else
        {   
            std::vector<uint8_t> buffer(FILE_SIZE(data));
            std::ifstream(data,std::ios::binary).read(reinterpret_cast<char*>(buffer.data()), buffer.size());
            b64_encode<std::vector<uint8_t>>(buffer);
        }
    }
    else
    {
        decode ? b64_decode<str>(data) : b64_encode<str>(data);
    }
}
