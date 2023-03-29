# Laba
Have you ever wandered which stack works faster? Made on singly linked list or on a dynamic one?

This brilliant repository will give you answer to this question!

Test-1: (1000000 pushes + 500000 pops + 750000 pushes) x 9 times

Test-2: (10000 pushes & 10000 pops) x 900 times

Test-3: 1000000 pushes and 1000000 pushes or pops (on random)

> SHORT ANSWER: DYNAMIC ONE

Here's comparison table:\
(First line is singly linked list, second is dynamic array)

![Stack comparison](https://github.com/ThreadJava800/StackLaba/blob/main/comp.png?raw=true)

So, here we can see that dynamic list works faster (probably because it's cache-friendly and so memory access takes less time).

To run this app, just simply run this command:
> make