# ArtBot

A CLI tool to generate random, pretty png's. ArtBot is capable of producing images in any resolution. Different methods of producing images can be substituted for one another.

ArtBot is dependency-free and hence can be built very simply, using the command:

```
g++ -std=c++17 src/*.cpp -o artbot.o
```

To run ArtBot run the command:

```
./artbot.o
```

This will run ArtBot with a random seed, creating a png whose name is based on the seed. The default width is 256 pixels.

These details can be changed using command arguments.

| Key | Effect                                             |
| --- | -------------------------------------------------- |
| -n  | Supply the name for the png                        |
| -s  | Supply the seed for the random number generation   |
| -w  | Supply the width and height in pixels of the image |

![Demo Image](https://github.com/gabrielbarker/ArtBot/raw/master/img/readme.png "Demo Image")
