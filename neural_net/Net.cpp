#include "Net.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using std::cout; using std::endl;
using std::vector; using std::sqrt;

Net::Net(const vector<unsigned>& topology){
    // number of layers should be length of topology array
    unsigned numLayers = topology.size();

    // initializes all layers
    for(unsigned layerNum = 0; layerNum < numLayers; ++layerNum){
        m_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
        
        // layer created, now we need to add individual neurons in the layer
        // note "<=" --> one additional loop for bias neuron
        for(unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum){
            m_layers.back().push_back(Neuron(numOutputs, neuronNum)); // fill in constructor arguments later
            cout << "Neuron made!" << endl;
        }
    }
}

void Net::feedForward(const std::vector<double>& inputVals){
    assert(m_layers[0].size() == inputVals.size() - 1); // make sure input vals = number of input neurons

    // assign the values from inputVals and put them into the input neurons
    for(unsigned i = 0; i < inputVals.size(); ++i){
        m_layers[0][i].setOutputVal(inputVals[i]);
    }

    // forward propagate
    for(unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum){
        Layer &prevLayer = m_layers[layerNum-1];
        for(unsigned n = 0; n < m_layers[layerNum].size() - 1; ++n){
            m_layers[layerNum][n].feedForward(prevLayer); // Neuron::feedForward, not Net::feedForward
        }
    }
}

void Net::backProp(const std::vector<double>& targetVals){
    // calculate overall net error (RMS)
    Layer &outputLayer = m_layers.back();
    m_error = 0.0;

    for(unsigned n = 0; n < outputLayer.size() - 1; ++n){
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta;
    }

    m_error /= outputLayer.size() - 1; // get average
    m_error = sqrt(m_error); // RMS

    // implement a recent average measurement
    m_recentAverageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error) / (m_recentAverageSmoothingFactor + 1.0); 

    // calculate output layer gradients
    for(unsigned n = 0; n < outputLayer.size() - 1; ++n){
        outputLayer[n].calcOutputGradients(targetVals[n]);
    }

    // calculate gradients on  hidden layers
    for(unsigned layerNum = m_layers.size() - 2; layerNum > 0; --layerNum){
        Layer &hiddenLayer = m_layers[layerNum];
        Layer &nextLayer = m_layers[layerNum + 1];

        for(unsigned n = 0; n < hiddenLayer.size(); ++n){
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }


    // for all layers from outputs to first hidden layer, update connection weights
    for(unsigned layerNum = m_layers.size(); layerNum > 0; --layerNum){
        Layer &layer = m_layers[layerNum];
        Layer &prevLayer = m_layers[layerNum - 1];

        for(unsigned n = 0; n < layer.size() - 1; ++n){
            layer[n].updateInputWeights(prevLayer);
        }
    }

}

void Net::getResults(std::vector<double>& resultVals) const{
    resultVals.clear();

    for(unsigned n = 0; n < m_layers.back().size() - 1; ++n){
        resultVals.push_back(m_layers.back()[n].getOutputVal());
    }

    m_layers.back().back().setOutputVal(1.0);
}

