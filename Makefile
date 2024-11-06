build:	
	g++ -std=c++11 -o image-processor src/main.cpp src/image.cpp

tasks: build
	