#include "Net.h"
#include <iostream>
#include <vector>

using std::cout; using std::endl; 
using std::vector;

int main(){
    cout << "Creating neural network from scratch: " << endl;

    // topology: each index is a layer w number of neurons at that layer
    vector<unsigned> topology = {3, 2, 1};

    Net myNet(topology);

    vector<double> inputVals;
    vector<double> targetVals;
    vector<double> resultVals;

    /*
    // inputvals should be some array or struct that holds input values
    myNet.feedForward(inputVals);

    // intended output values for training
    myNet.backProp(targetVals);

    // getResults to be used once training is complete
    myNet.getResults(resultVals);
    */
}