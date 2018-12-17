'use strict';

function main() {
    print('hello, world!');
}

/**
 * Node.js IO Helper
 * 
 * `nextInt()`, `nextFloat()`, `nextChar()`, `nextString()`
 * `nextLine()` skips lines that contain only whitespace character.
 * `isWhitespaces(character)`, `clearWhitespaces()`
 * `print(string)`
 */

var input = "";
var cursor = 0;
process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function(data) { input += data; });
process.stdin.on('end', function() { main(); });

function isWhitespace(character) {
    return ' \t\n\r\v'.indexOf(character) > -1;
}

function clearWhitespaces() {
    while (cursor < input.length && isWhitespace(input[cursor])) ++cursor; 
}

function nextInt() {
    return parseInt(nextString());
}

function nextFloat() {
    return parseFloat(nextString());
}

function nextChar() {
    clearWhitespaces();
    if (cursor < input.length)
        return input[cursor++];
    return '';
}

function nextString() {
    let str = "";
    clearWhitespaces();
    while (cursor < input.length && !isWhitespace(input[cursor])) {
        str += input[cursor++];
    }
    return str;
}

function nextLine() {
    let str = "";
    clearWhitespaces();
    while (cursor < input.length) {
        let ch = input[cursor++];
        if (ch !== '\n') str += ch; else break;
    }
    return str;
}

function print(str) {
    console.log(str);
}
