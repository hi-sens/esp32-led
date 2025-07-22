// #ifndef _BOARD_BREAD_WIFI_H_
// #define _BOARD_BREAD_WIFI_H_
#include "board.h"
#include <iostream>

class BreadWifiBoard: public Board {

    public:
        BreadWifiBoard();
        // virtual ~BreadWifiBoard() override = default;
};


DECLARE_BOARD(BreadWifiBoard);
// #endif // _BOARD_BREAD_WIFI_H_
