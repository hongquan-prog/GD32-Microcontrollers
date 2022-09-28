.PHONY: all clean update flash menuconfig

MODULES := GD32F103 GD32E103 GD32F303 GD32F450

# BUILD_TYPE := DEBUG
# BUILD_OUTPUT_DIR := build/debug
BUILD_TYPE := RELEASE
BUILD_OUTPUT_DIR := build/release

# compile all
all: config
	cmake --build ${BUILD_OUTPUT_DIR}

# single module independent compile
$(MODULES): config ${BUILD_OUTPUT_DIR}/$(MAKECMDGOALS)
	cmake --build ${BUILD_OUTPUT_DIR} --target $(MAKECMDGOALS)

config:
	cmake -G Ninja -S . -B ${BUILD_OUTPUT_DIR} -DCMAKE_TOOLCHAIN_FILE=tool.cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE}

clean:
	rm -r build

flash:
	cmake --build ${BUILD_OUTPUT_DIR} --target flash

menuconfig:
	cmake-gui ${BUILD_OUTPUT_DIR}

