FROM trzeci/emscripten:sdk-tag-1.38.8-64bit

RUN apt-get update
RUN apt-get install -y valgrind
RUN apt-get install -y less
RUN apt-get install -y build-essential
RUN apt-get install -y openjdk-8-jre

RUN git clone --recursive https://github.com/WebAssembly/wabt /src/wabt
RUN mkdir -p /src/wabt/build && cd /src/wabt/build && cmake ../ && make && make install

WORKDIR /src/emscripten
ADD . /src/emscripten

CMD [ "tail", "-f", "/dev/null" ]
