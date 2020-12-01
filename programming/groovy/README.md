# Groovy代码片段

基础

```groovy
// Println
println '世界，你好'

// 运算
int x = 5; int y = 7
assert 12 == x + y

assert 12 == 3*x +4.5*y / (2/x + y**3)
```

POGOs

```groovy
import groovy.transform.Canonical

@Canonical
class Event {
    String name
    Date when
    int priority
}

Event e1 = new Event(name: 'Android Studio 1.0',
    when: Date.parse('MMM d, yyyy', 'Dec 8, 2014'),
    priority: 1)

Event e2 = new Event(name: 'Android Studio 1.0',
    when: Date.parse('MMM d, yyyy', 'Dec 8, 2014'),
    priority: 1)

println e1.toString()
println e2.toString()
```
