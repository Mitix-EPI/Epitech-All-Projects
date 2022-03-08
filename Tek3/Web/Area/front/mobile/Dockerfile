FROM ubuntu

RUN rm -rf node_modules

#ENVIRONNEMENT
ENV GLIB_PACKAGE_BASE_URL https://github.com/sgerrand/alpine-pkg-glibc/releases/download
ENV GLIB_VERSION 2.25-r0

ENV GRADLE_HOME /usr/local/gradle
ENV GRADLE_VERSION 4.4

ENV ANDROID_HOME /usr/local/android-sdk-linux
ENV ANDRDOID_TOOLS_VERSION r25.2.5
ENV ANDROID_API_LEVELS android-26
ENV ANDROID_BUILD_TOOLS_VERSION 26.0.2
ENV IONIC_VERSION 4.12.0

ENV ANDROID_SDK_ROOT /opt/android-sdk-linux
# Preserved for backwards compatibility
ENV ANDROID_HOME /opt/android-sdk-linux

ENV PATH ${GRADLE_HOME}/bin:${JAVA_HOME}/bin:${ANDROID_HOME}/tools:$ANDROID_HOME/platform-tools:$PATH

WORKDIR /usr/src/app/Area

COPY . .

# Install OpenJDK-8
RUN apt-get update && \
    apt-get install -y openjdk-8-jdk && \
    apt-get install -y ant && \
    apt-get install -y curl && \
    apt-get install -y unzip && \
    apt-get install -y wget && \
    apt-get clean;

# Fix certificate issues
RUN apt-get update && \
    apt-get install ca-certificates-java && \
    apt-get clean && \
    update-ca-certificates -f;

# Setup JAVA_HOME -- useful for docker commandline
ENV JAVA_HOME /usr/lib/jvm/java-8-openjdk-amd64/
RUN export JAVA_HOME

# INSTALL NODE / NPM
RUN curl -sL https://deb.nodesource.com/setup_16.x | bash
RUN apt-get install -y nodejs
RUN npm install
RUN npm install -g npm@latest

WORKDIR /usr/src/app/Area/mobile

# INSTALL IONIC AND CORDOVA
RUN npm install -g cordova @ionic/cli

#INSTALL Graddle
# RUN mkdir -p ${GRADLE_HOME} && \
#   curl -L https://services.gradle.org/distributions/gradle-${GRADLE_VERSION}-bin.zip > /tmp/gradle.zip && \
#   unzip /tmp/gradle.zip -d ${GRADLE_HOME} && \
#   mv ${GRADLE_HOME}/gradle-${GRADLE_VERSION}/* ${GRADLE_HOME} && \
#   rm -r ${GRADLE_HOME}/gradle-${GRADLE_VERSION}/

# # INSTALL ANDROID
# RUN mkdir -p ${ANDROID_HOME} && \
#   curl -L https://dl.google.com/android/repository/tools_${ANDRDOID_TOOLS_VERSION}-linux.zip > /tmp/tools.zip && \
#   unzip /tmp/tools.zip -d ${ANDROID_HOME}

# INSTALL GLIBC
# RUN curl -L https://raw.githubusercontent.com/wassim6/alpine-pkg-glibc/master/sgerrand.rsa.pub > /etc/apk/keys/sgerrand.rsa.pub && \
#   curl -L ${GLIB_PACKAGE_BASE_URL}/${GLIB_VERSION}/glibc-${GLIB_VERSION}.apk > /tmp/glibc.apk && \
#   curl -L ${GLIB_PACKAGE_BASE_URL}/${GLIB_VERSION}/glibc-bin-${GLIB_VERSION}.apk > /tmp/glibc-bin.apk && \
#   apk add /tmp/glibc-bin.apk /tmp/glibc.apk
# RUN apt --no-cache add ca-certificates wget
# RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
# RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk
# RUN apt add glibc-2.28-r0.apk

# CONFIGURATION
# RUN echo y | android update sdk --no-ui -a --filter platform-tools,${ANDROID_API_LEVELS},build-tools-${ANDROID_BUILD_TOOLS_VERSION}

# # Make license agreement
# RUN mkdir $ANDROID_HOME/licenses && \
#     echo 8933bad161af4178b1185d1a37fbf41ea5269c55 > $ANDROID_HOME/licenses/android-sdk-license && \
#     echo d56f5187479451eabf01fb78af6dfcb131a6481e >> $ANDROID_HOME/licenses/android-sdk-license && \
#     echo 24333f8a63b6825ea9c5514f83c2829b004d1fee >> $ANDROID_HOME/licenses/android-sdk-license && \
#     echo 84831b9409646a918e30573bab4c9c91346d8abd > $ANDROID_HOME/licenses/android-sdk-preview-license

# ARG GRADLE_VERSION=5.2.1
# ARG GRADLE_DIST=bin
# RUN cd /opt && \
#     wget -q https://services.gradle.org/distributions/gradle-${GRADLE_VERSION}-${GRADLE_DIST}.zip && \
#     unzip gradle*.zip && \
#     ls -d */ | sed 's/\/*$//g' | xargs -I{} mv {} gradle && \
#     rm gradle*.zip

# # download and install Android SDK
# # https://developer.android.com/studio/#downloads
# ARG ANDROID_SDK_VERSION=4333796
# ENV ANDROID_HOME /opt/android-sdk
# RUN mkdir -p ${ANDROID_HOME} && cd ${ANDROID_HOME} && \
#     wget -q https://dl.google.com/android/repository/sdk-tools-linux-${ANDROID_SDK_VERSION}.zip && \
#     unzip *tools*linux*.zip && \
#     rm *tools*linux*.zip
# # set the environment variables
# ENV APK_SIGNER=/opt/android-sdk/build-tools/29.0.2/
# ENV JAVA_HOME /usr/lib/jvm/java-8-openjdk-amd64
# ENV ANDROID_SDK_ROOT /opt/android-sdk
# ENV GRADLE_HOME /opt/gradle
# ENV PATH ${PATH}:${GRADLE_HOME}/bin:${ANDROID_HOME}/emulator:${ANDROID_HOME}/tools/bin:${ANDROID_HOME}/tools:${ANDROID_HOME}/platform-tools:${ANDROID_HOME}/tools/bin/apksigner:${APK_SIGNER}
# ENV _JAVA_OPTIONS -XX:+UnlockExperimentalVMOptions -XX:+UseCGroupMemoryLimitForHeap
# # WORKAROUND: for issue https://issuetracker.google.com/issues/37137213
# ENV LD_LIBRARY_PATH ${ANDROID_HOME}/emulator/lib64:${ANDROID_HOME}/emulator/lib64/qt/lib


# Gradle PPA
ENV GRADLE_VERSION=6.3
ENV PATH=$PATH:"/opt/gradle/gradle-6.3/bin/"
RUN wget https://services.gradle.org/distributions/gradle-${GRADLE_VERSION}-bin.zip -P /tmp \
    && unzip -d /opt/gradle /tmp/gradle-*.zip \
    && chmod +775 /opt/gradle \
    && gradle --version \
    && rm -rf /tmp/gradle*

# # accept the license agreements of the SDK components
# ADD license_accepter.sh /opt/
# RUN chmod +x /opt/license_accepter.sh && /opt/license_accepter.sh $ANDROID_HOME

# ------------------------------------------------------
# --- Download Android Command line Tools into $ANDROID_SDK_ROOT

RUN cd /opt \
    && wget -q https://dl.google.com/android/repository/commandlinetools-linux-6858069_latest.zip -O android-commandline-tools.zip \
    && mkdir -p ${ANDROID_SDK_ROOT}/cmdline-tools \
    && unzip -q android-commandline-tools.zip -d /tmp/ \
    && mv /tmp/cmdline-tools/ ${ANDROID_SDK_ROOT}/cmdline-tools/latest \
    && rm android-commandline-tools.zip && ls -la ${ANDROID_SDK_ROOT}/cmdline-tools/latest/

ENV PATH ${PATH}:${ANDROID_SDK_ROOT}/platform-tools:${ANDROID_SDK_ROOT}/cmdline-tools/latest/bin

# ------------------------------------------------------
# --- Install Android SDKs and other build packages

# Other tools and resources of Android SDK
#  you should only install the packages you need!
# To get a full list of available options you can use:
#  sdkmanager --list

# Accept licenses before installing components, no need to echo y for each component
# License is valid for all the standard components in versions installed from this file
# Non-standard components: MIPS system images, preview versions, GDK (Google Glass) and Android Google TV require separate licenses, not accepted there
RUN yes | sdkmanager --licenses

RUN touch /root/.android/repositories.cfg

# Emulator and Platform tools
RUN yes | sdkmanager "emulator" "platform-tools"

# SDKs
# Please keep these in descending order!
# The `yes` is for accepting all non-standard tool licenses.

RUN yes | sdkmanager --update --channel=0
# Please keep all sections in descending order!
RUN yes | sdkmanager \
    "platforms;android-30" \
    "platforms;android-29" \
    "platforms;android-28" \
    "platforms;android-27" \
    "platforms;android-26" \
    "platforms;android-25" \
    "platforms;android-24" \
    "platforms;android-23" \
    "platforms;android-22" \
    "platforms;android-21" \
    "platforms;android-19" \
    "platforms;android-17" \
    "platforms;android-15" \
    "build-tools;30.0.3" \
    "build-tools;30.0.2" \
    "build-tools;30.0.0" \
    "build-tools;29.0.3" \
    "build-tools;29.0.2" \
    "build-tools;29.0.1" \
    "build-tools;29.0.0" \
    "build-tools;28.0.3" \
    "build-tools;28.0.2" \
    "build-tools;28.0.1" \
    "build-tools;28.0.0" \
    "build-tools;27.0.3" \
    "build-tools;27.0.2" \
    "build-tools;27.0.1" \
    "build-tools;27.0.0" \
    "build-tools;26.0.2" \
    "build-tools;26.0.1" \
    "build-tools;25.0.3" \
    "build-tools;24.0.3" \
    "build-tools;23.0.3" \
    "build-tools;22.0.1" \
    "build-tools;21.1.2" \
    "build-tools;19.1.0" \
    "build-tools;17.0.0"

#FILES DELETION
RUN rm -rf /tmp/* /var/cache/apk/*

# Install Cordova
RUN npm install -g cordova-res@latest

# Install capacitor
RUN npm install -g @capacitor/cli
RUN npm install @capacitor/core

WORKDIR /usr/src/app/Area/mobile

RUN rm -rf node_modules

WORKDIR /usr/src/app/Area
RUN npm install

WORKDIR /usr/src/app/Area/mobile
