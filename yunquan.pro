#-------------------------------------------------
#
# Project created by QtCreator 2015-07-19T11:04:00
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yunquan
TEMPLATE = app


SOURCES += main.cpp\
    common/util.cpp \
    views/groupchatview.cpp \
    views/personalchatview.cpp \
    content.cpp \
    groupchat.cpp \
    mainwin.cpp \
    p2pchat.cpp \
    model/user.cpp \
    controller/logindialog.cpp \
    common/Log.cpp \
    protocol/AuthCodeGetRequest.cpp \
    jsonlib/json_reader.cpp \
    jsonlib/json_value.cpp \
    jsonlib/json_writer.cpp \
    jsonlib/jsoncpptest4.cpp \
    protocol/AuthCodeGetResponse.cpp
HEADERS  += \
    common/connection.h \
    common/struct.h \
    common/util.h \
    views/groupchatview.h \
    views/personalchatview.h \
    content.h \
    groupchat.h \
    mainwin.h \
    p2pchat.h \
    model/user.h \
    controller/logindialog.h \
    common/common.h \
    common/Log.h \
    common/ProtJsonGetValue.h \
    protocol/AuthCodeGetRequest.h \
    jsonlib/autolink.h \
    jsonlib/config.h \
    jsonlib/features.h \
    jsonlib/forwards.h \
    jsonlib/json.h \
    jsonlib/json_batchallocator.h \
    jsonlib/json_tool.h \
    jsonlib/reader.h \
    jsonlib/value.h \
    jsonlib/writer.h \
    protocol/AuthCodeGetResponse.h

FORMS    += \
    views/groupchatview.ui \
    views/logindialog.ui \
    views/personalchatview.ui

RESOURCES += \
    yunquan.qrc

