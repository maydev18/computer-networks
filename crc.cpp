#include <iostream>
#include <string>
using namespace std;
class CRC{
    string msg , polynomial;
    public :
        CRC(string msg , string polynomial){
            this->msg = msg;
            this->polynomial = polynomial;
        }
        string myxor(string data){
            string ans = "";
            for(int i = 0  ; i < polynomial.size() ; i++){
                if(data[i] == '0' && polynomial[i]=='0'){
                    ans.push_back('0');
                }
                else if(data[i] == '1' && polynomial[i]=='1'){
                    ans.push_back('0');
                }
                else{
                    ans.push_back('1');
                }
            }
            int one = -1;
            for(int i = 0 ; i < ans.size() ; i++){
                if(ans[i] == '1'){
                    one = i;
                    break;
                }
            }
            if(one == -1) return "";
            else return ans.substr(one);
        }
        string sender(){
            string dividend = (msg + string(polynomial.size()-1 , '0'));
            string currxor = myxor(dividend.substr(0,polynomial.size()));
            int curr = polynomial.size();
            while(curr != dividend.size()){
                if(currxor.size() != polynomial.size()){
                    currxor.push_back(dividend[curr++]);
                }
                else{
                    currxor = myxor(currxor);
                }
            }
            if(currxor.size() != polynomial.size()-1){
                return msg + string(polynomial.size()-currxor.size()-1,'0') + currxor;
            }
            else{
                return msg + currxor;
            }
        }
        void receiver(string data){
            string currxor = myxor(data.substr(0,polynomial.size()));
            int curr = polynomial.size();
            while(curr != data.size()){
                if(currxor.size() != polynomial.size()){
                    currxor.push_back(data[curr++]);
                }
                else{
                    currxor = myxor(currxor);
                }
            }
            if(currxor.find('1') != string::npos){
                cout << "there is some error in data" << endl;
            }
            else{
                cout << "correct message recieved" << endl;
            }
        }
};
int main(){
    string msg , poly;
    cout << "enter the data: ";
    cin >> msg;
    cout << "enter the polynomial: ";
    cin >> poly;
    CRC ob(msg , poly);
    string ans = ob.sender();
    ob.receiver(ans);
    return 0;
}