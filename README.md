Steganography
=============

## Presentation ##
------------------

## Requirements ##
------------------

* Java 8

## Instalation ##
------------------

## Configuration ##
------------------

## Current Version ##
------------------

18/11/2015 - Steganography Software Version 1 : 
This version of the Software comprises of 2 elements, one in Java (dissimulation), and one in C (revelation)

Dissimulation :
- Format used : PNG
- Dissimulation method : code on LSB of each color component (RGB), direct (first pixel to last, going in rows)

Revelation :
- Format used : PNG
- Revelation : acquires determined number of bits (set in the code), and prints in the console the LSb for all the color components concerned (magic number not implemented)

24/01/2016 - Steganography Software Version 4:
This version is the upgrade version of last version. With a instruct compress, compress a message in Java (dissimulation), and decompress the message in C (revelation)

Dissimulation : Compress a message, dissimulate it in a image. 

Revalation : Reveal message from image, then decompress it.

MVP : 1 bit used when hiding message, channel RGB, direct (first pixel to last, going in rows)


## Maintainers ##
------------------

Current maintainers

* Paul BERTOT (paulbertot@gmail.com)
* Charly LAFON (charlylafon@gmail.com)
* Raquel LOPES DE OLIVEIRA (oliveira.raquel.lopes@gmail.com)
* Xiaohan HUANG (stephanie1028han@gmail.com)

This project has been sponsored by

 * Polytech Nice Sophia


