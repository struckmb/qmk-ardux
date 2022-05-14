FROM debian:11-slim

RUN apt update && apt install -y \
    avr-libc \
    avrdude \
    binutils-arm-none-eabi \
    binutils-avr \
    binutils-riscv64-unknown-elf \
    build-essential \
    ca-certificates \
    clang-format-11 \
    dfu-programmer \
    dfu-util \
    dos2unix \
    ca-certificates \
    gcc \
    gcc-arm-none-eabi \
    gcc-avr \
    gcc-riscv64-unknown-elf \
    git \
    libfl2 \
    libnewlib-arm-none-eabi \
    picolibc-riscv64-unknown-elf \
    python3 \
    python3-pip \
    software-properties-common \
    tar \
    teensy-loader-cli \
    unzip \
    tar \
    wget \
    zip \
    && rm -rf /var/lib/apt/lists/*

# Install python packages
RUN python3 -m pip install --upgrade pip setuptools wheel
RUN python3 -m pip install nose2 yapf qmk

# Set the default location for qmk_firmware
VOLUME /qmk_firmware
ENV QMK_HOME /qmk_firmware

# Run qmk setup to catch anything missing
CMD ["/bin/bash"] 
