#!/bin/bash

FILE=./premake5

if [ ! -f $FILE ]; then
	wget -O ./premake5_source.tar.gz "https://github.com/premake/premake-core/archive/refs/tags/v5.0.0-beta2.tar.gz"
	tar -xzf ./premake5_source.tar.gz
	rm -f ./premake5_source.tar.gz
	cd "premake-core-5.0.0-beta2"
	apt install uuid-dev
	make -f Bootstrap.mak linux
	chmod +x ./bin/release/premake5
	mv ./bin/release/premake5 ../premake5
	cd ..
	rm -rf "premake-core-5.0.0-beta2"
fi

./premake5 gmake2
