# Hangman

# Introduction // Inspiration

After seeing many different Hangman implementations online, I decided to make my own. Why another one, you may ask? Well, I noticed that current implementations seemed to perform O(n^2) search and I hadn't seen anyone take advantage of multiple indirection, which allows for a different approach for the game.

# How to run

The Ninja build system is used to build this project.

1. Generate build files using the following

```
cmake . -GNinja
```

2. Then, run ninja


```
ninja
```

3. Finally, run the program

```
./Hangman
```

# License
This code is released under the MIT License.