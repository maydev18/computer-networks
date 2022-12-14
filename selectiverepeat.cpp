#include <iostream>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
class SR{
    public:
        int n;
        int * dataframes;
        SR(){
            cout << "enter the number of frames to be sent: ";
            cin >> n;
            dataframes = new int[n];
            for(int i = 1 ; i<=n ; i++){
                cout << "enter the data of the " << i << " frame to be sent: ";
                cin >> dataframes[i];
            }
            receiveframes();
        }
        void receiveframes(){
            int frame = rand()%n + 1;
            cout << "frame number " << frame << " is not recieved !!! " << endl;
            resendframe(frame);
        }
        void resendframe(int frame){
            cout << "resending the frame number " << frame  << endl;
            sleep(2);
            cout << "successfully resent the frame " << frame << " again" << endl << endl;
            cout << "frame number " << frame << " with data " << dataframes[frame] << " received" << endl; 
            cout << "all frames have been successfully sent " << endl;
        }
};
int main(){
    SR s;
    return 0;
}