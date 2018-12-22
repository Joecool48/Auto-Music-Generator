#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;
#define LEN 4000000 // Audio samples size
#define WAVE_HEIGHT 3000
#define SAMPLE_RATE 44100
void generate_square_wave(char * samples, short amplitude, short frequency, unsigned num_samples) {
    short counter = 0;
    short current_height = amplitude;
    short counter_switch = SAMPLE_RATE / frequency / 2;
    if (counter_switch <= 0) counter_switch = 1;
    for (int i = 0; i < 2 * num_samples; i += 2) {
        if (counter % counter_switch == 0) current_height = current_height == 0 ? amplitude : 0;
        samples[i] = (current_height) & 0xff;
        samples[i + 1] = (current_height >> 8) & 0xff;
        counter++;
    }
}

void generate_sine_wave(char * samples, short amplitude, short dcOffset, short frequency, unsigned num_samples) {
    double period = 1 / (double) frequency;
    unsigned current_sample = 0;

    for (int i = 0; i < 2 * num_samples; i += 2) {
        unsigned sample = (amplitude * sin(period * current_sample)) + dcOffset; // Offset sign
        //std::cout << sample << std::endl;
        samples[i] = sample & 0xff;
        samples[i + 1] = (sample >> 8) & 0xff;
        current_sample++;
    }
}

void generate_sawtooth_wave(char * samples, short upSlope, short downSlope, short amplitude, short dcOffset, unsigned num_samples) {
    bool up = true;
    short current_height = dcOffset;

    for (int i = 0; i < 2 * num_samples; i += 2) {
        if (up) {
            if (current_height + upSlope >= amplitude + dcOffset) {
                up = false;
            }
            else {
                current_height += upSlope;
            }
        }
        else {
            if (current_height - downSlope <= dcOffset) {
                up = true;
            }
            else {
                current_height -= downSlope;
            }
        }

        samples[i] = current_height & 0xff;
        samples[i + 1] = (current_height >> 8) & 0xff;

    }
}

int main() {
    fstream file;
    file.open("test.pcm", ios::out | ios::binary);
    short counter = 0;
    char bytes[LEN * 2];

    generate_square_wave(bytes, 3000, 300, LEN);

    file.write(bytes, LEN * 2 * sizeof(char));
    file.flush();
    file.close();
}
