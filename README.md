# philosophers_git
Philosophers proyect 42

The dining philosophers problem is a classic computer science problem that involves five philosophers seated around a circular table. Each philosopher has a plate of food in front of them, and they must alternate between thinking and eating. The problem is to design a protocol that allows the philosophers to eat without getting into a "deadlock" state, where they are unable to eat because they are waiting for another philosopher to finish eating.

One solution to the dining philosophers problem is to use a "resource hierarchy" approach, where each philosopher is assigned a number, and they are only allowed to pick up their chopsticks if their number is lower than the number of the philosopher to their left. This ensures that no philosopher will be waiting for another philosopher to finish eating, because they will always be able to pick up their chopsticks as long as they are not trying to eat at the same time as the philosopher to their left.

Another solution is to use a "token-based" approach, where a special "token" is passed around the table, and a philosopher can only pick up their chopsticks if they have the token. This ensures that only one philosopher can eat at a time, and that the others will not be in a deadlock state.

There are also other solutions to the dining philosophers problem, such as using semaphores or monitors to coordinate the philosophers' access to the chopsticks. Ultimately, the solution that is chosen will depend on the specific requirements and constraints of the problem.