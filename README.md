# ESP IDF Led
## Building

We recommend using the [ESP-IDF VSCode extension](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension) to build the project. Alternatively, you can use the command line: `idf.py build`.

## Simulation

To simulate this project, install [Wokwi for VS Code](https://marketplace.visualstudio.com/items?itemName=wokwi.wokwi-vscode). Open the project directory in Visual Studio Code, press **F1** and select "Wokwi: Start Simulator".

## Debugging

The project is already set up for debugging. To debug the project, first start Wokwi in debug mode (press **F1** and select "Wokwi: Start Simulator and Wait for Debugger"). Then press **F5** to start the debugger. You can set breakpoints, step through the code, and inspect variables.

The debugger is configured to use TCP port 3333. If this port is already in use on your computer, you can change it in the `.vscode/launch.json` file (`miDebuggerServerAddress`) and in `wokwi.toml` (`gdbServerPort`).

Note that the debugger setup requires the ESP-IDF extension to be installed in VS Code. If you don't have the ESP-IDF extension, you can manually set `miDebuggerServerAddress` in `.vscode/launch.json` to point to your local installation of the `xtensa-esp32-elf-gdb` debugger (it's usually installed in the esp tools directory, under `tools/xtensa-esp-elf-gdb/<version>/xtensa-esp-elf-gdb/bin`).
## Board Support

1、创建组件
```bash
idf.py -C components create-component component_name
```
默认组件目录为`components`，会自动加载编译组件内部的cmakelist
引用时，只需要引用组件的头文件即可

2、c++ 编译c 需要 声明 extern "C"
    在头文件中实现类方法,需要在前面加上inline,但最好不要这么做

3、Kconfig 包含 在main目录下的上级目录下的Kconfig文件中添加如下代码：
```bash
source "main/boards/Kconfig.projbuild"
```

4、抽象类编译
   需要在cmakelist 添加抽象类的头文件和其公共部分的代码，在编译时动态选择真实实现功能的派生类
   board.h 中定义抽象类
   board.cc 中实现抽象类的方法  
   wifi_board.cc 中实现抽象类的方法
   引用的时候，导入board.h,即通过抽象类进行引用，本质上是工厂的实现