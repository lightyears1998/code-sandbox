'use strict';

console.log(abx);

let abx;

var reg = /^ab*$/;
var mail_reg = /^.*e\.gzhu\.edu\.cn$/;

console.log(reg.test('ab'));
console.log(reg.test('abbc'));

console.log(mail_reg.test('419250332@qq.com'));
console.log(mail_reg.test('1706300001@e.gzhu.edu.cn'));
