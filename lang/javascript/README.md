# JavaScript代码沙盒

## 函数参数

```js
/* 默认参数 */
function sayHello(str = 'hello') {
    console.log(str);
}

sayHello();
sayHello('hello, again.');

/* 不定参数 */

function add(...x) {
    return x.reduce((m, n) => m + n);
}

//! Reduce empty array with no initial value
//! console.log(add());

console.log(add(1));
console.log(add(1, 2, 3, 4, 5));

/* 拓展参数 */
/* 通过数组或类数组直接作为函数的参数，而不需要使用apply()方法 */

var people = ['Jack', 'Tom', 'Jackson'];
function greetPeople(first, second, third) {
    console.log(`Hello, ${first}, ${second} and ${third}`);
}
greetPeople(people);      // Hello, Jack,Tom,Jackson, undefined and undefined
greetPeople(...people);   // Hello, Jack, Tom and Jackson
```

## ES6导入和导出

```js
// ES6语法的导出

export var total = 36;

/* ---------- */

// ES6语法的导入
// 目前Nodejs没有原生的ES6 import支持
// 一说是加参数和调整文件名
// 一说是使用Babel转译

import total from './es6-export';

console.log(total);
```