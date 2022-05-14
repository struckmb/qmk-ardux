#!/bin/bash
docker run -it --rm \
	--network host \
	--privileged \
	-v /dev:/dev \
	-v qmk_firmware:/qmk_firmware \
	-v ./.build:/qmk_firmware/.build \
	-v ./keyboards/ardux:/qmk_firmware/keyboards/ardux \
	-v ./keyboards/faunchpad:/qmk_firmware/keyboards/faunchpad \
	-v ./users/ardux:/qmk_firmware/users/ardux \
	qmkfm/qmk_cli:latest \
	/bin/bash
