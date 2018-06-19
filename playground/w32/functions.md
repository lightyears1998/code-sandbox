## 宏

- TEXT

## 句柄

*HANDLE*

*INVALID_HANDLE_VALUE*

- *GetStdHandle()* STD_INPUT_HANDLE STD_OUTPUT_HANDLE

## 消息提示函数

- MessageBox(NULL, TEXT("Comment"), TEXT("Title"), MB_OK);

## 输入输出函数

BLUE, GREEN, RED
FOREGROUND BACKGROUND

*CONSOLE_SCREEN_BUFFER_INFO* csbiInfo
*WORD* wOldColorAttrs

- GetConsoleScreenBufferInfo(hStdout, &csbiInfo)
- wOldColorAttrs = csbiInfo.wAttributes
- SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY)