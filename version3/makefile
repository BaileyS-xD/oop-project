item.o: Item.h Item.cpp
	@g++ Item.cpp -o item.o

bugrepel.o: BugRepel.h BugRepel.cpp
	@clang++ BugRepel.cpp -o bugrepel.o

fruitfert.o: FruitFert.h FruitFert.cpp
	@clang++ FruitFert.cpp -o fruitfert.o

vegfert.o: VegFert.h VegFert.cpp
	@clang++ VegFert.cpp -o vegfert.o

shop.o: Shop.h Shop.cpp
	@clang++ Shop.cpp -o shop.o

farmer.o: Farmer.h Farmer.cpp
	@clang++ Farmer.cpp -o farmer.o

run: main.cpp
	@make item.o
	@make bugrepel.o
	@make fruitfert.o
	@make vegfert.o
	@make shop.o
	@make farmer.o
	@clang++ item.o bugrepel.o fruitfert.o vegfert.o shop.o farmer.o main.cpp -o Farming

run2: Plant.h Plant.cpp Fruit.h Fruit.cpp Blueberry.h Blueberry.cpp Vegetable.h Vegetable.cpp Garden.h Garden.cpp Item.h Item.cpp BugRepel.h BugRepel.cpp FruitFert.h FruitFert.cpp VegFert.h VegFert.cpp Shop.h Shop.cpp Farmer.h Farmer.cpp main.cpp
	@clear
	@clang++ Plant.cpp Fruit.cpp Blueberry.cpp Vegetable.cpp Garden.cpp item.cpp bugrepel.cpp fruitfert.cpp vegfert.cpp shop.cpp farmer.cpp main.cpp -o Farming
	@./Farming
