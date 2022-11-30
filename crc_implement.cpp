#include <iostream>
using namespace std;

class CRC{
    public:
        string sender(string message,string crc){
            string encoded = "";
            int m = message.length();
            int n = crc.length();
            encoded += message;
            cout<<encoded<<endl;
            for(int i = 0;i<n-1;i++){
                encoded+= '0';
            }
            cout<<encoded<<endl;
            // Main Part Starts here
            for (int i = 0; i <= encoded.length()-n;)
            {
                for(int j = 0;j<n;j++){
                    encoded[i+j] = encoded[i+j]==crc[j]?'0':'1';
                }
                // for(;i<encoded.length() && encoded[i]!='1' ;i++);
                if(i<encoded.length() && encoded[i]!='1' ) i++;
            }
            cout<<encoded<<endl;
            message += encoded.substr(encoded.length()-n+1);
            cout<<message<<endl;
            return message;

            
        }

        bool receiver(string encoded,string crc){
            int m = encoded.length(),n = crc.length();
            for(int i = 0;i<=m-n;){
                for(int j = 0;j<n;j++){
                    encoded[i+j]=encoded[i+j]==crc[j]?'0':'1';

                }
                // for(;i<m && encoded[i]!='1';i++);
                if(i<m && encoded[i]!='1') i++;
            }
            cout<<encoded<<endl;
            for (char i:encoded.substr(m-n)){
                if(i!='0'){
                    cout<<"Error In mEssage\n";
                    return false;
                }
                
            }
            cout<<"Correct MEssage Received\n";
                return true;
        }
};

int main(){
    CRC obj; //Object Creation
    string msg = "1110010101",crc="1101";//Taking An example of MEssage and CRC
    string op=obj.sender(msg,crc); //Calling Sender Function
    bool ans = obj.receiver(op,crc); //Calling Receiver Function
    return 0;
}

