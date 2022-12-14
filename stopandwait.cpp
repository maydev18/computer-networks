#include<iostream>
#include<windows.h>
#include<unistd.h> 
#include<math.h>
using namespace std;
int main(){
    int i,j,packet[30];
    bool flag =true;
    int fsize=(rand()%16)+1;
    cout<<"frame size is :  "<<fsize<<endl;
    cout<<"\tframe"<<"\tdata"<<"\twaiting"<<"\tack"<<"\tresend"<<endl;

    for(i=0;i<fsize;i++){
        packet[i]=rand()%1000;
        cout<<"\t"<<i+1<<"\t"<<packet[i];
        while(j=0||rand()%2==0){

            sleep(1);
            cout<<"\t"<<1;
            sleep(1);
            for(j=2;rand()%2==0&& j<4;j++){
                cout<<j;
                sleep(1);
            }
            if(j==4){
                
                cout<<"\t"<<"no"<<"\t"<<"resending"<<endl;
            }
            else{
                
                break;
            }
        } 
        if(j==0){
            sleep(1);
            cout<<"\t"<<0;
        }
        cout<<"\t"<<"yes"<<"\t"<<"no"<<endl;


    }
cout<<"-----------all packets sent-----------"<<endl;
return 0;

}