from ubuntu:latest
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow
ADD ./ /var/src
RUN apt-get update && apt-get install -y cmake g++ make mosquitto python python3-pip && pip3 install conan
RUN cd /var/src && mkdir build && cd build
WORKDIR /var/src/build
RUN ls .. && cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" .. && make -j4

