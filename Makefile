.PHONY: all clean update flash menuconfig


all: build
	cmake --build build/debug
	cmake --build build/release

build:
	cmake -G Ninja -S . -B build/debug -DCMAKE_TOOLCHAIN_FILE=tool.cmake -DCMAKE_BUILD_TYPE=DEBUG
	cmake -G Ninja -S . -B build/release -DCMAKE_TOOLCHAIN_FILE=tool.cmake -DCMAKE_BUILD_TYPE=RELEASE

clean:
	rm -r build

flash:
	cmake --build build/release --target flash

menuconfig:
	ccmake . build/release
