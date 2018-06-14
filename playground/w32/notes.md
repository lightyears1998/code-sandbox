## Windows Console

来源：https://docs.microsoft.com/en-us/windows/console/

### 概念：Character Mode(Command Line Mode) Application

The console is build-in. Any number of process can share a console.

Console events include keyboard events and mouse events.

### IO方法

#### High-Level Method

ReadFile() WriteFile() ReadConsole() WriteConsole()

会抛弃鼠标和buffer-resize事件

#### Low-Level Method

直接读取输入/输出缓存

#### 控制台模式

https://docs.microsoft.com/en-us/windows/console/console-modes

输入模式影响输入操作，输出模式影响输出操作（输出模式对低级输出没有影响）

`GetConsoleMode()`

`SetConsoleMode()`
如果一个控制台有多个屏幕缓冲，输出模式可以不同；
可以在任意时刻改变IO模式

https://docs.microsoft.com/en-us/windows/console/input-and-output-methods
