#include <iostream>
#include "board.h" // Make sure this header defines the Board class
extern "C" {
  #include "MyComponent.h"
}
// Main application
extern "C" void app_main() {
  func();
  // BreadWifiBoard::getInstance();
  // std::cout << "Board Version: " << Board::getInstance().getBoardVersion() << std::endl;
  auto &board = Board::getInstance();
  std::cout << "Board Version: " << board.getBoardVersion() << std::endl;
  // std::cout << "Board Name: " << board.GetBoardName() << std::endl;
}
