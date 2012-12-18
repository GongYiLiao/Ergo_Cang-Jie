GCC = gcc 
CLANG = clang
GEN_CC_FLAGS = -fPIC -Wall 
COUNT_KEY_ROWS_SRC = count_keys_on_which_rows.c
EXAMPLE_FILE = example1.txt

all: qwerty_dist_table dvorak_dist_table

check-syntax:
	$(GCC) $(CXXFLAGS) -o nul -S ${CHK_SOURCES}

dvorak_key:
	$(GCC) -DDVORAK $(GEN_CC_FLASE) -o dvorak_key $(COUNT_KEY_ROWS_SRC)  

dvorak_ht_key:
	$(GCC) -DDVORAK_HT $(GEN_CC_FLASE) -o dvorak_ht_key $(COUNT_KEY_ROWS_SRC)  

dvorak_hb_key:
	$(GCC) -DDVORAK_HB $(GEN_CC_FLASE) -o dvorak_hb_key $(COUNT_KEY_ROWS_SRC)  

dvorak_tb_key:
	$(GCC) -DDVORAK_TB $(GEN_CC_FLASE) -o dvorak_tb_key $(COUNT_KEY_ROWS_SRC)  

qwerty_key:
	$(GCC) $(GEN_CC_FLASE) -o qwerty_key $(COUNT_KEY_ROWS_SRC)  

qwerty_ht_key:
	$(GCC) -DQWERTY_HT $(GEN_CC_FLASE) -o qwerty_ht_key $(COUNT_KEY_ROWS_SRC)  

qwerty_hb_key:
	$(GCC) -DQWERTY_HB $(GEN_CC_FLASE) -o qwerty_hb_key $(COUNT_KEY_ROWS_SRC)  

dvorak_dist_table: dvorak_key dvorak_ht_key dvorak_hb_key dvorak_tb_key
	touch dvorak_dist.txt
	echo "DROVAK" >> dvorak_dist.txt
	./dvorak_key $(EXAMPLE_FILE) >> dvorak_dist.txt
	echo "DROVAK_HT" >> dvorak_dist.txt
	./dvorak_ht_key $(EXAMPLE_FILE) >> dvorak_dist.txt
	echo "DROVAK_HB" >> dvorak_dist.txt
	./dvorak_hb_key $(EXAMPLE_FILE) >> dvorak_dist.txt 
	echo "DROVAK_TB" >> dvorak_dist.txt
	./dvorak_tb_key $(EXAMPLE_FILE) >> dvorak_dist.txt 

qwerty_dist_table: qwerty_key qwerty_ht_key qwerty_hb_key
	touch qwerty_dist.txt
	echo "QWERTY" >> qwerty_dist.txt
	./qwerty_key $(EXAMPLE_FILE) >> qwerty_dist.txt
	echo "QWERTY_HT" >> qwerty_dist.txt
	./qwerty_ht_key $(EXAMPLE_FILE) >> qwerty_dist.txt 
	echo "QWERTY_HB" >> qwerty_dist.txt
	./qwerty_hb_key $(EXAMPLE_FILE) >> qwerty_dist.txt 

clean: 
	rm dvorak_key dvorak_ht_key dvorak_hb_key dvorak_tb_key qwerty_key qwerty_ht_key qwerty_hb_key 


