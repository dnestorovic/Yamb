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
COPY ./code/NetworkServer/CMakeLists.txt NetworkServer/
COPY ./code/NetworkServer/*.h NetworkServer/
COPY ./code/NetworkServer/*.cpp NetworkServer/

# Copying backend files
RUN mkdir GameLogic
COPY ./code/GameLogic/*.h GameLogic/
COPY ./code/GameLogic/*.cpp GameLogic/

# Copying common files
RUN mkdir NetworkCommon
COPY ./code/NetworkCommon/*.h NetworkCommon/

# Building server
RUN echo "Building project" \
    && cd NetworkServer \
    && cmake CMakeLists.txt \
    && make

# Port for listening TCP connections
EXPOSE 5000

# Running server
CMD ./NetworkServer/server
