#include <iostream>
using namespace std;

string encrypt(string text, int key)
{
    string cipherText;
    //Traverse Text
    for(int i = 0; i< text.length(); i++)
    {
        if(isupper(text[i]))
        {
            cipherText += (text[i] + key - 65) % 26 + 65;
        }
        else if(islower(text[i]))
        {
            cipherText += (text[i] + key - 65) % 26 + 97;
        }
        else
        {
            cipherText += text[i];
        }
    }
    return cipherText;
}

string decrypt(string ciperText, int key)
{
    string plainText;
    for(int i = 0; i<ciperText.length(); i++)
    {
        if(isupper(ciperText[i]))
        {
            plainText += (ciperText[i] - 65 - key + 26) % 26 + 65;
        }
        else if(islower(ciperText[i]))
        {
            plainText += (ciperText[i] - 97 - key + 26) % 26 + 97;
        }
        else
        {
            plainText += ciperText[i];
        }
    }

    return plainText;
}

int main(int argc, char const *argv[])
{
    string text = "MY CAT HAS FLEAS";
    unsigned int key = 4;
    cout<<"Text: "<<text<<endl;
    cout<<"Key: "<<key<<endl;
    cout<<"Cipher Text: "<<encrypt(text, key)<<endl;
    cout<<"Main Text: "<<decrypt(encrypt(text, key), key)<<endl;
    return 0;
}
