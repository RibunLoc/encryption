#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string encrypt(string plaintext, string key){
    string cipherText = "";
    // lặp qua các kí tự key để in hoa
    for(char& c : key){ 
        c = std::toupper(c);
    }
    

    int keyindex = 0;

    for(int i = 0; i < plaintext.length(); i++ ){
        char currentChar = plaintext[i];
        
        if(isalpha(currentChar)){ // kiểm tra có phải là chữ cái không
            char offset = isupper(currentChar) ? 'A' : 'a';

            currentChar = (char)(((currentChar - offset + key[keyindex] - 'A') % 26 ) + offset); // đưa currentChar và key[keyindex] về cùng một phạm vi (0 - 25);
            keyindex = ( keyindex + 1 ) % key.length(); // duyệt từ kí tự key rồi lặp lại
        }
        cipherText += currentChar;
    }
    return cipherText;
}

string decrypt(string ciphertext, string key){
    string plaintext = "";

    for(char& c : key){ // in hoa chuỗi key
        c = std::toupper(c);
    }
    
    int keyindex = 0;
    
    for(int i = 0; i < ciphertext.length(); i++)
    {
        char currentChar = ciphertext[i];

        if(isalpha(currentChar)){
            char offset = isupper(currentChar) ? 'A' : 'a';

            currentChar = ((((currentChar - offset - key[keyindex] + 'A') + 26 ) % 26 ) + offset); // đưa currentChar và key[keyindex] về cùng một phạm vi (0 - 25);
            keyindex = (keyindex + 1) % key.length();
        }
        plaintext += currentChar;
    }
    return plaintext;
}

int main(){
    cout << "Plaintext: "; // nhập plaintext;
    string plaintext;
    std::getline(std::cin,plaintext);
    cout << "Key: "; // nhập khóa key;
    string key;
    cin >> key;

    string encryptedText = encrypt(plaintext, key); //gọi hàm mã hóa dữ liệu
    cout << "Văn bản đã mã hóa: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, key); //gọi hàm giải mã dữ liệu
    cout << "Văn bản sau khi giải mã: " << decryptedText << endl;

    return 0;
}