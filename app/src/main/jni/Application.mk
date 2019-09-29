APP_OPTIM := debug
APP_PLATFORM := android-28
APP_ABI := armeabi-v7a
#NDK_TOOLCHAIN_VERSION=4.9
APP_PIE := false
#APP_STL := c++_static
APP_CFLAGS := -O3 -Wall -pipe \
    -ffast-math \
    -fstrict-aliasing -Werror=strict-aliasing \
    -Wno-psabi -Wa,--noexecstack \
    -DANDROID -DNDEBUG