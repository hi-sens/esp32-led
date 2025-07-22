#ifndef BOARD_H
#define BOARD_H

#include <string>
// #include <cstdint>
#include <esp_random.h>
#include <sdkconfig.h>
#include <iostream>
using namespace std;

// Board version defined in sdkconfig
#define Board_Version  CONFIG_Board_Version


void* create_board();

class Board
{
private:
    Board(const Board&) = delete; // 禁用拷贝构造函数
    Board& operator=(const Board&) = delete; // 禁用赋值操作
    /* data */

protected:  // 添加 protected 访问修饰符
    Board(){
        // 构造函数可以在这里进行初始化
        std::cout << "Board initialized." << std::endl;
    }

public:
    // virtual ~Board() = default;
    int getBoardVersion() const
    {
        return Board_Version; // 假设版本号为1
    }
    string GetBoardName();
    string GenerateUUID();
    static Board& getInstance()
    {
        static Board* instance = static_cast<Board*>(create_board());
        return *instance;
    }
};


inline string Board::GetBoardName()
{
    return "Generic Board";
}

inline string Board::GenerateUUID() {
    uint8_t uuid[16];
    esp_fill_random(uuid, sizeof(uuid));
    uuid[6] = (uuid[6] & 0x0F) | 0x40;
    uuid[8] = (uuid[8] & 0x3F) | 0x80;
    char uuid_str[37];
    snprintf(uuid_str, sizeof(uuid_str),
        "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
        uuid[0], uuid[1], uuid[2], uuid[3],
        uuid[4], uuid[5], uuid[6], uuid[7],
        uuid[8], uuid[9], uuid[10], uuid[11],
        uuid[12], uuid[13], uuid[14], uuid[15]);
    return std::string(uuid_str);
}

#define DECLARE_BOARD(BOARD_CLASS_NAME) \
void* create_board() { \
    return new BOARD_CLASS_NAME(); \
}

#endif // BOARD_H