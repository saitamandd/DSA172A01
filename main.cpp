#include <iostream>

#include "listLib.h"
#include "requestLib.h"
#include "dbLib.h"

using namespace std;

bool processRequest(VRequest& request, L1List<VRecord>& recList, void* pGData);
bool initVGlobalData(void** pGData);
void releaseVGlobalData(void* pGData);

int main(int narg, char** argv) {
    L1List<VRequest>  reqList;
    L1List<VRecord>   recDB;// database of records
    void*             pGData;

    loadRequests(argv[1], reqList);
    loadVDB(argv[2], recDB);

    cout << fixed << setprecision(12);// preset for floating point numbers
    /// Process events
    if (initVGlobalData(&pGData)) {
        clog << "Successfully initialize data\n";
    }
    else {
        clog << "Failed to initialize data\nExiting...\n";
        return -1;
    }

    while (!reqList.isEmpty()) {
        if (!processRequest(reqList[0], recDB, pGData))
            cout << "Failed to process the request\n";
        reqList.removeHead();
    }

    cout << resetiosflags(ios::showbase) << setprecision(-1);
    /// Release any global allocaed data
    releaseVGlobalData(pGData);
    return 0;
}