serializejson: serialize-json.cc binarydir nlohmann
	g++ serialize-json.cc -std=c++17 -I include/single_include/ -o bin/serialize-json -g

binarydir:
	mkdir -p bin

nlohmann: lib/nlohmann-3.7.3.zip
	unzip -u lib/nlohmann-3.7.3.zip single_include/nlohmann/json.hpp -d include

test:
	@bin/serialize-json

clean:
	rm -r bin include