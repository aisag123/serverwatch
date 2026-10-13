FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
	&& apt-get install --no-install-recommends --yes \
		build-essential \
		cmake \
		ninja-build \
		dpkg-dev \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY . .

RUN cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release \
	&& cmake --build build --target package \
	&& mkdir /out

CMD ["sh", "-c", "cp build/*.deb /out/"]
