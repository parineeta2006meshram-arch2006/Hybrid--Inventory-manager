all:
	gcc -c src/inventory.c -o inventory.o
	g++ -c src/InventoryManager.cpp -o manager.o
	g++ -c src/main.cpp -o main.o
	g++ inventory.o manager.o main.o -o inventory_app

clean:
	rm *.o inventory_app
