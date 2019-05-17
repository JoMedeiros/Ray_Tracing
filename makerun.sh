#!/bin/bash

make
./bin/img_gen perspective_exemp.yml > teste.txt
xdg-open ./output.png

