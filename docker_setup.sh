#!/bin/bash
cd .devcontainer

docker volume create qmk_firmware

docker build --network host -t qmkfm/qmk_cli:latest .

docker run -it --rm \
	--network host \
	-v qmk_firmware:/qmk_firmware \
	qmkfm/qmk_cli:latest \
	/bin/bash -c "git clone https://github.com/qmk/qmk_firmware.git /qmk_firmware"

docker run -it --rm \
	--network host \
	-v qmk_firmware:/qmk_firmware \
	qmkfm/qmk_cli:latest \
	/bin/bash -c "qmk setup"

docker run -it --rm \
	--network host \
	-v qmk_firmware:/qmk_firmware \
	qmkfm/qmk_cli:latest \
	/bin/bash -c "qmk compile -kb crkbd/rev1 -km default"

cd ..
