#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H


class RandomNumberGenerator
{
    public: 
        virtual double next() = 0;
        virtual ~RandomNumberGenerator(){}
};

#endif