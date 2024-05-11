//
// Created by thijs on 11.05.24.
//

#ifndef MUEK_TGLBOARD_FORK_TINY_LETTER_TEST_H
#define MUEK_TGLBOARD_FORK_TINY_LETTER_TEST_H


#include "display_program.h"
#include "TinyLetter/tinyLetters.h"

#define REFRESH_RATE 17

class TinyLetterTest : public display_program {
public:
    void refresh() override;
    void restart() override;

    void button1ISR(bool data) override; // select
    void button2ISR(bool data) override; // mode

    explicit TinyLetterTest(MatrixOutput *ledMatrix, Color (*frame)[MATRIX_HEIGHT][MATRIX_LENGTH]);

    void setDisplayChar(char displayedChar);
private:

    bool scroll = true;
    char displayedChar;
    int charIndex;
};


#endif //MUEK_TGLBOARD_FORK_TINY_LETTER_TEST_H
