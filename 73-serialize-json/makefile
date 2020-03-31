serializejson: serialize-json.cc binarydir nlohmann
	g++ serialize-json.cc -std=c++11 -I include/single_include/ -o bin/serialize-json

binarydir:
	mkdir -p bin

nlohmann: lib/nlohmann-3.7.3.zip
	unzip -u lib/nlohmann-3.7.3.zip single_include/nlohmann/json.hpp -d include

clean:
	rm -r bin include