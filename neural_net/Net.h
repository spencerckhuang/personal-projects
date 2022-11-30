#ifndef NET_H
#define NET_H

#include <vector>
#include "Neuron.h"

class Net{
    public:
        Net(const std::vector<unsigned> &topology);

        void feedForward(const std::vector<double>& inputVals);

        void backProp(const std::vector<double>& targetVals);

        void getResults(std::vector<double>& resultVals) const;

    private:
        // vector of layers, making a two dimensional array of neurons
        std::vector<Layer> m_layers;

        double m_error;
        double m_recentAverageError;
        double m_recentAverageSmoothingFactor;

};

#endif