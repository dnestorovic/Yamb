FROM ubuntu

# Preventing unnecesary terminal freeze
ARG DEBIAN_FRONTEND=noninteractive

# Installing g++, Boost and ASIO
RUN apt-get update && \
    apt-get -qq -y install gcc g++ && \
    apt-get -qq -y install libboost-all-dev && \
    apt-get -qq -y install libasio-dev && \
    apt-get -qq -y install cmake

# Copying server files
RUN mkdir NetworkServer
COPY ./NetworkServer/CMakeLists.txt NetworkServer/
COPY ./NetworkServer/*.h NetworkServer/
COPY ./NetworkServer/*.cpp NetworkServer/

# Copying backend files
RUN mkdir Classes
COPY ./Classes/*.h Classes/
COPY ./Classes/*.cpp Classes/

# Copying common files
RUN mkdir NetworkCommon
COPY ./NetworkCommon/*.h NetworkCommon/

# Building server
RUN echo "Building project" \
    && cd NetworkServer \
    && cmake CMakeLists.txt \
    && make

# Port for listening TCP connections
EXPOSE 5000

# Running server
CMD ./NetworkServer/server
