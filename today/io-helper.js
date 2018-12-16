'use strict';

function main() {
    let n = nextInt(), ans = 0;
    while (n--) {
        let str = nextString();
        str[1] === '+' ? ++ans : --ans;
    }
    console.log(ans);
}

// ------ IO Helper ------
// nextInt(), nextFloat(), nextChar(), nextString()
// isWhitespace(character :string), clearWhitespaces()

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
