//
// Created by leo on 28.04.24.
//

#ifndef MUEK_ARGB_MATRIX_BOARD_DISPLAY_PROGRAM_H
#define MUEK_ARGB_MATRIX_BOARD_DISPLAY_PROGRAM_H

#include "Arduino.h"
#include "color.h"
#include "PIOMatrixOutput/pio_matrix_output.h"


class display_program {

protected:
    Color (*frame)[MATRIX_HEIGHT][MATRIX_LENGTH];
    MatrixOutput *matrix;

public:
    display_program(MatrixOutput *matrix, Color (*frame)[MATRIX_HEIGHT][MATRIX_LENGTH]);


    uint32_t refreshSpeed;

    void clearFrame();



    virtual void button1ISR(bool state) = 0;
    virtual void button2ISR(bool state) = 0;

    virtual void refresh() = 0;
    virtual void restart() = 0;


};











#endif //MUEK_ARGB_MATRIX_BOARD_DISPLAY_PROGRAM_H
