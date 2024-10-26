ARG VARIANT=debian-11
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        # oj-verify
        curl python3-distutils \
    && apt-get clean

# oj-verify
RUN curl https://bootstrap.pypa.io/get-pip.py -o /tmp/get-pip.py \
    && python3 /tmp/get-pip.py \
    && rm -f /tmp/get-pip.py \
    && pip3 install online-judge-verify-helper
