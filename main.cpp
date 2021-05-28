#include <iostream>
#include <vector>

#include <rell.h>
#include <slotmachine.h>

#define SIZE_CHECK_RTP 100000

using namespace std;

void game(SlotMachine *machine);
float checkRTP(SlotMachine *machine, int sizeSpin);

int main()
{
    Rell<int> r1{0,7,7,4,2,2,5,8,2,1,8,5,5,4,4,6,4,5,8,1,7,3,5,7,6,8,3,6,7,6,6,3,8,3};
    Rell<int> r2{0,5,6,8,4,6,2,4,8,5,8,4,7,3,5,3,7,3,7,7,5,7,5,2,3,1,2,4,6,8,8,1,6,6};
    Rell<int> r3{0,5,3,7,8,4,5,1,2,3,2,8,6,5,8,4,5,6,6,8,7,4,6,6,3,1,2,4,7,7,8,7,5,3};
    vector<Rell<int>> rells;
    rells.push_back(r1);
    rells.push_back(r2);
    rells.push_back(r3);

    SlotMachine machine(rells);

    int selectDecision;
    cout << "What you want to do?\n" <<
            "enter 1 - game\n" <<
            "enter 2 - check RTP\n" <<
            "decision : ";
    cin >> selectDecision;

    switch(selectDecision)
    {
    case 1: {
        game(&machine);
        break;
    }
    case 2: {
        float rtp = checkRTP(&machine, SIZE_CHECK_RTP);
        cout << "RTP = " << rtp << "%" << endl;
        if(rtp > 1.f) {
            cout << "Returns" << endl;
        }
        else {
            cout << "No Spinn!";
        }
    }
    }

    return 0;
}

void game(SlotMachine *machine)
{
    int win;
    char c;

    do
    {
        win = machine->spinMachine();
        cout << "Spin\n";
        machine->showLastRoll();
        cout << "Win = " << win << endl;

        cout << "Exit game - enter \"q\"\n";
        cin >> c;
    }while(c != 'q');
}

float checkRTP(SlotMachine *machine, int sizeSpin)
{
    int gain = 0;
    for(int i = 0; i < sizeSpin; i++)
    {
        gain += machine->spinMachine();
    }

    return gain/ static_cast<float>(sizeSpin);
}
