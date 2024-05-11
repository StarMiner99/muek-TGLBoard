//
// Created by thijs on 11.05.24.
//

#include "tiny_letter_test.h"

TinyLetterTest::TinyLetterTest(MatrixOutput *ledMatrix, Color (*frame)[8][16]) : display_program(ledMatrix, frame) {
    this->refreshSpeed = REFRESH_RATE;
}

void TinyLetterTest::refresh() {
    //int charIndex = tinyNormalChars.indexOf(displayedChar);

    clearFrame();
    const uint8_t* charArray = tinyLetter[charIndex];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((charArray[i] >> (2 - j)) & 1) {
                (*frame)[i][j] = colorWhite;
            }

        }
    }


    matrix->setDisplayData(frame);
    matrix->sendData();

}

void TinyLetterTest::setDisplayChar(char displayedChar) {
    this->displayedChar = displayedChar;
}

void TinyLetterTest::restart() {
    charIndex = 0;
}

void TinyLetterTest::button1ISR(bool data) {
    if (data) {
        if (charIndex -1 < 0) {
            charIndex = 82;
        }
        charIndex--;
    }

}

void TinyLetterTest::button2ISR(bool data) {
    if (data) {
        charIndex = (charIndex + 1) % 82;
    }

}
