#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron;
typedef std::vector<Neuron> Layer;

struct Connection{
    double weight;
    double deltaWeight;
};

class Neuron{
    public:
        Neuron(unsigned numOutputs, unsigned myIndex);
        
        void setOutputVal(double d){ m_outputVal = d; }

        double getOutputVal() const { return m_outputVal; }

        void feedForward(const Layer& prevLayer);

        void calcOutputGradients(double targetVal);

        void calcHiddenGradients(const Layer &nextLayer);

        void updateInputWeights(Layer &prevLayer);

        void setEta(double e) { eta = e; }

        void setAlpha(double a) { alpha = a; }

    private:
        static double randomWeight();

        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);

        double sumDOW(const Layer &nextLayer) const;

        double m_outputVal;
        std::vector<Connection> m_outputWeights;

        unsigned m_myIndex;

        double m_gradient;

        static double eta; // {0.0 ... 1.0} overall net training rate
        static double alpha; // {0.0 ... n} multiplier of last weight change (momentum)

};



#endif