FROM ubuntu

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get -qq -y install gcc g++ && \
    apt-get -qq -y install libboost-all-dev && \
    apt-get -qq -y install libasio-dev && \
    apt-get -y install cmake

RUN mkdir NetworkServer
COPY ./NetworkServer/main.cpp NetworkServer/
COPY ./NetworkServer/CMakeLists.txt NetworkServer/

RUN mkdir Classes
COPY ./Classes/*.cpp Classes/
COPY ./Classes/*.h Classes/

RUN mkdir NetworkCommon
COPY ./NetworkCommon/*.h NetworkCommon/

RUN echo "Building project" \
    && cd NetworkServer \
    && cmake CMakeLists.txt \
    && make

EXPOSE 5000

CMD ./NetworkServer/server