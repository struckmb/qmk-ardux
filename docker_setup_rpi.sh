#!/bin/bash
docker volume create qmk_firmware

cd .devcontainer

docker build --network host -t qmk-ardux:latest -f Dockerfile

docker build --network host -t qmk-ardux:latest -f Dockerfile.rpi

docker run -it --rm \
	--network host \
	-v qmk_firmware:/qmk_firmware \
	qmk-ardux:latest \
	/bin/bash -c "git clone https://github.com/qmk/qmk_firmware.git /qmk_firmware"

docker run -it --rm \
	--network host \
	-v qmk_firmware:/qmk_firmware \
	qmk-ardux:latest \
	/bin/bash -c "qmk setup"

docker run -it --rm \
	--network host \
	-v qmk_firmware:/qmk_firmware \
	qmk-ardux:latest \
	/bin/bash -c "qmk compile -kb crkbd/rev1 -km default"

cd ..
