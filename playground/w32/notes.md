## Windows编程基本概念

数据类型表：https://msdn.microsoft.com/en-us/library/windows/desktop/ff381404(v=vs.85).aspx

总结的几点信息：

- 今天已经不需要区分long pointer和pointer。

### 匈牙利命名法

`m_`, `g_`, `l_`

- 'n' / 'i' = INT
- 'l' = LONG
- 'u' = UNSIGNED
- 'ch' = CHAR
- 'b' = BOOL
- 'f' = FLOAT
- 'd' = DOUBLE
- 'w' = WORD(2 bytes) / UNSIGNED SHORT
- 'dw' = DWORD(4 bytes) / UNSIGNED LONG
- 'p' = pointer
- 'lp' = long pointer
- 'lpsz' = long pointer to string that is zero-terminated / LPSTR

## Windows Console

来源：https://docs.microsoft.com/en-us/windows/console/

### 概念：Character Mode(Command Line Mode) Application

The console is build-in. Any number of process can share a console.
Console events include keyboard events and mouse events.

### IO方法

High Level -  抛弃鼠标和buffer-resize事件
Low Level - 直接读取输入/输出缓存

`ReadFile()` `WriteFile()` `ReadConsole()` `WriteConsole()`

#### 控制台模式

https://docs.microsoft.com/en-us/windows/console/console-modes

输入模式影响输入操作，输出模式影响输出操作（输出模式对低级输出没有影响）

如果一个控制台有多个屏幕缓冲，输出模式可以不同；
可以在任意时刻改变IO模式

`GetConsoleMode()` `SetConsoleMode()`

https://docs.microsoft.com/en-us/windows/console/input-and-output-methods
