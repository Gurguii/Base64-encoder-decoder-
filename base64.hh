#ifndef BASE64
#define BASE64

#include <string>
#include <vector>

using str = std::string;
using vector_uint8t = std::vector<uint8_t>;

str b64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int COUNT(str data, char ch){
    int n = 0;
    for(char c : data)
    {
        n += (c == ch) ? 1 : 0;
    }
    return n;
};

namespace base64
{
    std::string encode(std::string_view data)
    {
        int iters = data.size()/3;
        uint32_t bits;
        std::string result;
        for(int i = 0, j = 0 ; j < iters ; i+=3, j++)
        {
            bits = ((data[i] << 16)) | ((data[i+1] << 8)) | (data[i+2]);
            result+=(b64_table[(bits >> 18) & 0x3f]);
            result+=(b64_table[(bits >> 12) & 0x3f]);
            result+=(b64_table[(bits >> 6) & 0x3f]);
            result+=(b64_table[(bits >> 0) & 0x3f]);
        }

        if(int rest = data.size()%3)
        {
            if(rest == 1)
            {        
                uint16_t bits = data[iters*3] << 4;
                result+=b64_table[(bits >> 6) & 0x3f];
                result+=b64_table[(bits >> 0) & 0x3f];
                result+="==";
            }
            else{
                uint32_t bits = (data[iters*3] << 10) | (data[iters*3+1] << 2);
                result+=b64_table[(bits >> 12) & 0x3f];
                result+=b64_table[(bits >> 6) & 0x3f];
                result+=b64_table[(bits >> 0) & 0x3f];
                result+='=';
            }
        }
        return result;
    }

    std::string decode(std::string_view data)
    {   
        int iters = data.size()/4;
        uint32_t bits;
        std::string result;
        for(int i = 0, j = 0; j < iters-1; i+=4, j++)
        {
            bits = (b64_table.find(data[i]) << 18) | (b64_table.find(data[i+1]) << 12) | (b64_table.find(data[i+2]) << 6) | (b64_table.find(data[i+3]));
            result+=((bits >> 16) & 0xff);
            result+=((bits >> 8) & 0xff);
            result+=((bits >> 0) & 0xff);
        }
        str last4(&data[data.size()-4], 4);

        if(int padd = COUNT(last4, '='))
        {
            if(padd == 1)
            {
                uint32_t bits = (b64_table.find(last4[0]) << 18 | (b64_table.find(last4[1]) << 12 | (b64_table.find(last4[2]) << 6)));
                result+=((bits >> 16) & 0xff);
                result+=((bits >> 8) & 0xff);
                result+=((bits >> 0) & 0xff);
            }
            else if(padd == 2)
            {
                uint16_t bits = (b64_table.find(last4[0]) << 10) | (b64_table.find(last4[1]) << 4);
                result+=((bits >> 8) & 0xff);
                result+=((bits >> 0) & 0xff);            
            }
            return result;
        }

        bits = (b64_table.find(last4[0]) << 18) | (b64_table.find(last4[1]) << 12) | (b64_table.find(last4[2]) << 6) | (b64_table.find(last4[3]));
        result+=((bits >> 16) & 0xff);
        result+=((bits >> 8) & 0xff);
        result+=((bits >> 0) & 0xff);
        return result;
    }
}
#endif
