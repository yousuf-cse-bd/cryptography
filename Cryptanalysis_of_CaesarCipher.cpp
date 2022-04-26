/*****
 * @Author: Muhammad Yousuf Ali
 * @Since: 26 January 2021
 */

#include <iostream>
#include <string.h>
using namespace std;

//Encryption to PlainText Method
string encrypt(string x, int n)
{
    string cipher = "";

    for (int i = 0; i < x.length(); i++)
    {
        if (isupper(x[i]))                       ///Upper Test
            cipher += (x[i] + n - 65) % 26 + 65; /*x[i] read ASCII value of corresponding alphabet */
        else if (islower(x[i]))                  //Lower Test
            cipher += (x[i] + n - 97) % 26 + 97;
        else
            cipher += x[i]; /*Special Symbol and Space on change*/
    }
    return cipher;
}

//Decrypt the Cipher Text Using BruteForceAttack ALG.
void decrypt(string x)
{
    string text;
    ///Count 1 to 26
    for (int n = 1; n <= 26; n++)
    {
        text = "";
        for (int i = 0; i < x.length(); i++)
        {
            if (isupper(x[i]))
            {
                if ((x[i] - n - 65) < 0)
                    text += 91 + (x[i] - n - 65);
                else
                    text += (x[i] - n - 65) % 26 + 65;
            }
            else if (islower(x[i]))
            {
                if ((x[i] - n - 97) < 0)
                    text += 123 + (x[i] - n - 97);
                else
                    text += (x[i] - n - 97) % 26 + 97;
            }
            else
                text += x[i];
        }
        ///Display each PlainText Possible
        cout << "Plain Text For Key :" << n << " :- " << text << endl;
    }
}

int main()
{
    int key;
    string text;
    cout << "Enter Text Here: ";
    getline(cin, text);
    cout << "Enter Key Here: ";
    cin >> key;

    string cipher = encrypt(text, key);
    cout << "Ciper Text Here : " << cipher << "\n\n";

    decrypt(cipher);

    return 0;
}