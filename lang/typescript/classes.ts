class SomeClass {
    public property: Date

    public constructor() {
        this.property = new Date();
    }

    public method() {
        console.log("Hello, world!")
    }
};


// function
console.log(typeof SomeClass);


// [ 'length', 'name', 'arguments', 'caller', 'prototype' ]
console.log(Object.getOwnPropertyNames(SomeClass));
// length: 函数期望参数长度（默认参数不算入期望数量）
// 'arguments', 'caller': 被废弃


// [ 'method' ]
console.log(Object.keys(SomeClass.prototype));
// 参阅原型链
// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Inheritance_and_the_prototype_chain


// SomeClass { property: 2020-08-11T01:39:58.878Z }
console.log(new SomeClass());
