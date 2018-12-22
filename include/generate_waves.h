#ifndef GENERATE_WAVES
#define GENERATE_WAVES
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<cmath>


namespace waves {
    void generate_square_waveE(char * samples, short amplitude, short frequency, unsigned num_samples);
    void generate_sine_wave(char * samples, short amplitude, short dfOffset, short frequency, unsigned num_samples);
    void generate_sawtooth_wave(char * samples, short upSlope, short downSlope, short amplitude, short dcOffset, unsigned num_samples);
}
#endif
