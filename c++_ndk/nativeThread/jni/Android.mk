LOCAL_PATH:= $(call my-dir)

# #
# # expat
# #
#
# include $(CLEAR_VARS)
# LOCAL_MODULE := libexpat
# LOCAL_CFLAGS := -DHAVE_MEMMOVE
# EXPAT_PATH := $(LOCAL_PATH)/../../src/expat
# LOCAL_C_INCLUDES := \
# 	$(EXPAT_PATH)/include
#
# LOCAL_SRC_FILES := \
# 	$(EXPAT_PATH)/src/xmlparse.c \
# 	$(EXPAT_PATH)/src/xmlrole.c \
# 	$(EXPAT_PATH)/src/xmltok.c \
# 	$(EXPAT_PATH)/src/xmltok_impl.c \
# 	$(EXPAT_PATH)/src/xmltok_ns.c
#
# include $(BUILD_STATIC_LIBRARY)

#
# libstrohe (static library)
#

# include $(CLEAR_VARS)
# LOCAL_MODULE := libstrophe
# LOCAL_CFLAGS :=
# LIBSTROPHE_PATH := $(LOCAL_PATH)/../../src/libstrophe
# LOCAL_C_INCLUDES := \
# 	$(LIBSTROPHE_PATH)/../expat/include \
# 	$(LIBSTROPHE_PATH)/include
#
# LOCAL_SRC_FILES := \
# 	$(LIBSTROPHE_PATH)/src/auth.c \
# 	$(LIBSTROPHE_PATH)/src/conn.c \
# 	$(LIBSTROPHE_PATH)/src/ctx.c \
# 	$(LIBSTROPHE_PATH)/src/event.c \
# 	$(LIBSTROPHE_PATH)/src/handler.c \
# 	$(LIBSTROPHE_PATH)/src/hash.c \
# 	$(LIBSTROPHE_PATH)/src/jid.c \
# 	$(LIBSTROPHE_PATH)/src/md5.c \
# 	$(LIBSTROPHE_PATH)/src/parser_expat.c \
# 	$(LIBSTROPHE_PATH)/src/rand.c \
# 	$(LIBSTROPHE_PATH)/src/sasl.c \
# 	$(LIBSTROPHE_PATH)/src/scram.c \
# 	$(LIBSTROPHE_PATH)/src/sha1.c \
# 	$(LIBSTROPHE_PATH)/src/snprintf.c \
# 	$(LIBSTROPHE_PATH)/src/sock.c \
# 	$(LIBSTROPHE_PATH)/src/stanza.c \
# 	$(LIBSTROPHE_PATH)/src/thread.c \
# 	$(LIBSTROPHE_PATH)/src/tls_dummy.c \
# 	$(LIBSTROPHE_PATH)/src/util.c \
# 	$(LIBSTROPHE_PATH)/src/uuid.c
#
# LOCAL_STATIC_LIBRARIES := libexpat
#
# include $(BUILD_STATIC_LIBRARY)

#
# interface
#
include $(CLEAR_VARS)
LOCAL_MODULE := threads
LOCAL_CFLAGS :=


LOCAL_SRC_FILES := com_duanzw_guides_cplusplus_ndk_NativeThreadActivity.c


LOCAL_LDLIBS := -llog
#
# LOCAL_STATIC_LIBRARIES := libstrophe libexpat

include $(BUILD_SHARED_LIBRARY)
