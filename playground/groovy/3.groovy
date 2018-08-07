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