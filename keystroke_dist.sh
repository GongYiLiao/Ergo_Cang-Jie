#!/bin/sh

./test4_qwerty cj5.cin > qwerty_dist.txt
./test4_qwerty_ht cj5.cin >> qwerty_dist.txt 
./test4_qwerty_hb cj5.cin >> qwerty_dist.txt
./test4_qwerty example1.txt >> qwerty_dist.txt
./test4_qwerty_ht example1.txt >> qwerty_dist.txt 
./test4_qwerty_hb example1.txt >> qwerty_dist.txt

./test4_dvorak cj5_ergonomic.cin > dvorak_dist.txt
./test4_dvorak_ht cj5_ergonomic.cin >> dvorak_dist.txt
./test4_dvorak_hb cj5_ergonomic.cin >> dvorak_dist.txt 
./test4_dvorak example1.txt >> dvorak_dist.txt
./test4_dvorak_ht example1.txt >> dvorak_dist.txt
./test4_dvorak_hb example1.txt >> dvorak_dist.txt 



