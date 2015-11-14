efl: message efl_main.o efl_init.o item.o room.o list.o enread.o roomread.o player.o parse.o switch.o map.o enemy.o swread.o utils.o main.o efl_end.o EncDec.o
	gcc efl_main.o efl_init.o item.o room.o list.o enread.o roomread.o player.o parse.o EncDec.o switch.o map.o enemy.o swread.o utils.o main.o efl_end.o -o efl 
utils.o: utils.c utils.h
	gcc -c utils.c
item.o: item.c types.h utils.h room.h item.h
	gcc -c item.c
room.o: room.c room.h item.h
	gcc -c room.c
list.o: list.c list.h types.h item.h
	gcc -c list.c
enread.o: enread.c enread.h types.h utils.h EncDec.h
	gcc -c enread.c
roomread.o: roomread.c roomread.h types.h utils.h
	gcc -c roomread.c
player.o: player.c player.h types.h utils.h globals.h
	gcc -c player.c
parse.o: parse.c parse.h utils.h
	gcc -c parse.c
switch.o: switch.c switch.h types.h
	gcc -c switch.c
enemy.o: enemy.c enemy.h types.h
	gcc -c enemy.c
map.o: map.c map.h
	gcc -c map.c
swread.o: swread.c swread.h types.h utils.h
	gcc -c swread.c
efl_init.o: efl_init.c item.h room.h list.h enread.h roomread.h player.h parse.h switch.h map.h enemy.h globals.h utils.h types.h
	gcc -c efl_init.c
efl_main.o: efl_main.c item.h room.h list.h enread.h roomread.h player.h parse.h switch.h map.h enemy.h globals.h utils.h types.h
	gcc -c efl_main.c
efl_end.o: efl_end.c globals.h
	gcc -c efl_end.c
main.o: main.c efl_main.c efl_init.c efl_end.c
	gcc -c main.c
EncDec.o: EncDec.h EncDec.c types.h
	gcc -c EncDec.c
clean:
	@echo Removing .o and executable...
	rm *.o
	rm efl
lean: efl
	@echo Removing .o files...
	rm *.o
message:
	@echo Building project, efl...
