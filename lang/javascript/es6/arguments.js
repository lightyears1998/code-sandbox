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
